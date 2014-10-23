//===--------------- loopInv.cpp - Project 1 for CS 701 ---------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file is a skeleton of an implementation for the loopInv
// pass of Univ. Wisconsin-Madison's CS 701 Project 2.
//
//===----------------------------------------------------------------------===//

#define DEBUG_TYPE "loopInv"
#include "llvm/Pass.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/Instruction.h"
#include "llvm/ADT/StringExtras.h"
#include "llvm/ADT/Statistic.h"
#include "llvm/Support/InstIterator.h"
#include "llvm/Support/raw_ostream.h"
#include  "llvm/Support/CFG.h"
#include "llvm/ADT/SmallVector.h"

#include "flags.h"
#include <iostream>
#include <vector>
#include <stdio.h>
#include <queue>
#include <algorithm>

#include <set>
#include <map>
#include <list>

#define STEVE_DEBUG 1

using namespace llvm;
using namespace std;

namespace {
STATISTIC(LoopInvariantInstructionCount, "Number of loop-invariant instructions moved");

unsigned int inst_num = 1  ;
unsigned int BB_num = 1  ;

map<const Instruction* , unsigned int> inst_map;
//a map for block B to dom(B)
typedef set<const BasicBlock *> domSet ;
typedef map<const BasicBlock *, domSet > BBDomSet;
typedef deque<const BasicBlock *> BBworklist;


class loopInv : public FunctionPass {
	private:
    map<const BasicBlock* , unsigned int> BB_map;
    BBDomSet BB_dom;

	bool doMap(const Instruction *pinst, const unsigned int mapVal){
		inst_map[pinst] = mapVal;
		return true;
	}

	bool doBBMap(const BasicBlock *pBB, const unsigned int mapVal){
		BB_map[pBB] = mapVal;
		return true;
	}

	void itBBMap(const Function &F){
		for(Function::const_iterator f_it = F.begin(), f_it_end = F.end();f_it != f_it_end; f_it++){
				doBBMap(f_it, BB_num);
				BB_num ++;
		}
	}

	void itMap(const Function &F){
		for(Function::const_iterator f_it = F.begin(), f_it_end = F.end();f_it != f_it_end; f_it++){
			for(BasicBlock::const_iterator b_it = (*f_it).begin(), b_it_end = (*f_it).end(); b_it != b_it_end; b_it++){
				doMap(b_it, inst_num);
				inst_num ++;
			}
		}
	}

	void itBasicBlock(const Function &F){
	  	//2. iterator over basic blocks
	  	for(Function::const_iterator f_it = F.begin(), f_it_end = F.end(); f_it != f_it_end; f_it++){
			cerr << endl;
			cerr << "BASIC BLOCK " << (*f_it).getName().str();
            cerr << "\t" << BB_map[f_it] << "\n";
			//insert the gen into the map
			BasicBlock::const_iterator b_it = (*f_it).begin(), b_it_rev = (*f_it).end();
			do{
				b_it_rev --;
				//dest seudo reg
				int dest_reg = inst_map.find(b_it_rev)->second ;
				cerr << "%" << dest_reg << ":\t" ;
				//op
				cerr << (*b_it_rev).getOpcodeName() <<"\t" ;
				for(unsigned int i=0; i < (*b_it_rev).getNumOperands(); i++){
					if( isa<Instruction>( (*b_it_rev).getOperand(i)) ){
						cerr << " %" << inst_map.find( (Instruction *) (*b_it_rev).getOperand(i) )->second;
					}
					else if( (*b_it_rev).getOperand(i)->hasName() ){
						errs() << " " << (*b_it_rev).getOperand(i)->getName();// << "\t";
					}
					else {
						cerr << " XXX";
					}
				}
				cerr << endl;
	  		}while( b_it_rev != b_it );
		}
	}

    void printWorklist(BBworklist &worklist){
        cerr << "WL:[ ";
        for(BBworklist::const_iterator it=worklist.begin(),it_end=worklist.end();
                it!=it_end; it++){
            cerr << BB_map[ *it ] << " ";
        }
        cerr << " ]" << endl;
    }

    void findLoops(const Function &F){
        BBworklist worklist;
        //dom(N0) = {N0}, never change
        domSet domN0;
        domN0.insert(F.begin());

        BB_dom[F.begin()] = domN0;

        //dom(N) = {all nodes}
        domSet init_domN;
		for(Function::const_iterator f_it = F.begin(), f_it_end = F.end();
                f_it != f_it_end; f_it++){
            init_domN.insert(f_it);
		}
        //except N0
		for(Function::const_iterator f_it = (++F.begin()), f_it_end = F.end();
                f_it != f_it_end; f_it++){
            BB_dom[f_it] = init_domN;
		}

        //push all nodes but N0 into worklist
        for(Function::const_iterator f_it = (++F.begin()), it_end = F.end();
                f_it!=it_end; f_it ++){
            worklist.push_back( f_it);
        }
#ifdef STEVE_DEBUG
        cerr << "before worklist algo: " <<endl;
        printWorklist(worklist);
        cerr << "worklist algo start...  " <<endl;
#endif

        do{
            const BasicBlock * BBN = worklist.front();
            worklist.pop_front();

#ifdef STEVE_DEBUG
            printWorklist(worklist);
#endif

            //dom(Z) = Z U ( ^<Y in pred(Z)> dom(Y) )
            domSet domZ(BB_dom[BBN]);
            domSet domYAll(BB_dom[ *pred_begin(BBN)]);
            for(const_pred_iterator pred_it = pred_begin(BBN), pred_it_end = pred_end(BBN);
                    pred_it != pred_it_end; pred_it++){
                    domSet newDomSet, domY(BB_dom[*pred_it]);
                    set_intersection(domYAll.begin(), domYAll.end(),
                                     domY.begin(), domY.end(),
                                     inserter(newDomSet, newDomSet.begin()));
                    domYAll = newDomSet;
            }
            domSet newDomZ;
            domYAll.insert(BBN);
            newDomZ = domYAll;
            //if dom(Z) diffs from current value, use new, and add succ to worklist
            if( !(newDomZ == domZ) ){
                BB_dom[BBN] = newDomZ;
                for(succ_const_iterator succ_it = succ_begin(BBN),
                    succ_it_end = succ_end(BBN);
                    succ_it != succ_it_end; succ_it++){
                    worklist.push_back(*succ_it);
                }
            }
        }while(!worklist.empty());

        return ;
    }

    void print_domSet(const domSet &inSet){
        for(domSet::const_iterator it=inSet.begin(), it_end = inSet.end();it!=it_end;it++){
            //cerr << (*it)->getName().str();
            cerr << "( "<< BB_map[(*it)] << " ) ";
        }
        cerr<<endl;
    }

    void print_BB_dom(){
        cerr << "------------------------" <<endl;
        for(BBDomSet::const_iterator it = BB_dom.begin(), it_end = BB_dom.end();
            it!= it_end; it++){
            cerr << BB_map[it->first] << ": " ;
            print_domSet( it->second );
        }
        cerr << "------------------------" <<endl;
    }



    public:
    static char ID; // Pass identification, replacement for typeid
    loopInv() : FunctionPass(ID) {
	}

    //**********************************************************************
    // runOnFunction
    //**********************************************************************
    virtual bool runOnFunction(Function &F) {
      	// print fn name
      	bool isModified = false;

		itMap(F);
        itBBMap(F);
		itBasicBlock(F);

        //find loops
        findLoops(F);
#ifdef STEVE_DEBUG
        print_BB_dom();
#endif

        //find loop invariant instructions

        //move them out of loops

        //if it is modified, return true
      	return isModified;  // because we have NOT changed this function
    }

    //**********************************************************************
    // print (do not change this method)
    //
    // If this pass is run with -f -analyze, this method will be called
    // after each call to runOnFunction.
    //**********************************************************************
    virtual void print(std::ostream &O, const Module *M) const {
        O << "This is loop invariant.\n";
    }

    //**********************************************************************
    // getAnalysisUsage
    //**********************************************************************

    // We don't modify the program, so we preserve all analyses
    virtual void getAnalysisUsage(AnalysisUsage &AU) const {
        //AU.setPreservesAll();
    };

};
char loopInv::ID = 0;

// register the loopInv class:
//  - give it a command-line argument (loopInv)
//  - a name ("live Vars")
//  - a flag saying that we don't modify the CFG
//  - a flag saying this is not an analysis pass
RegisterPass<loopInv> X("loopInv", "loop invariant analysis", false, true);

}
