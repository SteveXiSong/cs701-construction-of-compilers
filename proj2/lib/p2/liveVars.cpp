//===--------------- liveVars.cpp - Project 1 for CS 701 ---------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file is a skeleton of an implementation for the liveVars 
// pass of Univ. Wisconsin-Madison's CS 701 Project 2.
//
//===----------------------------------------------------------------------===//

#define DEBUG_TYPE "liveVars"
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

#include <iostream>
#include <vector>
#include <stdio.h>

#include <set>
#include <map>
#include <list>

#include "liveVars.h"

//steve****************
//#include "instMapInt.h"
//*********************

using namespace llvm;
using namespace std;

namespace {
STATISTIC(RemovedInstructionCount, "Number of useless assignments found.");
typedef set<unsigned> regSet;
typedef map<llvm::Instruction* , unsigned int> inst_reg;

unsigned int inst_num = 1  ;
map<llvm::Instruction* , unsigned int> inst_map;

map<BasicBlock *, set<unsigned> > BB_liveBefore;
map<BasicBlock *, set<unsigned> > BB_liveAfter;

map<Instruction *, set<unsigned> > BB_liveBefore_inst;
map<Instruction *, set<unsigned> > BB_liveAfter_inst;

map<const BasicBlock * , set<unsigned> >BB_gen;
map<const BasicBlock * , set<unsigned> >BB_kill;
	

class liveVars : public FunctionPass {
	private:
	//map block to its live_after and live_before	
	set<unsigned> useless_regs;

	bool doMap(llvm::Instruction *pinst, const unsigned int mapVal){
		inst_map[pinst] = mapVal;
		return true;
	}

	void printSet(const regSet &inSet){
		for( regSet::iterator it = inSet.begin(), it_end = inSet.end();
				it != it_end; it++){
			cerr << " %" << (*it);
		}	
	}

	void printSet(const string cmdName, const string blkName, const regSet &setName){
		cerr << cmdName << blkName <<":" ;
		for(regSet::iterator it = setName.begin(), it_end = setName.end();it!=it_end; it++){
				cerr <<" "<< *it;
		}
		cerr << endl;
		return;
	}


	void compute_live(Function &F ){
		SmallVector<BasicBlock *, 32> worklist;		
		//push in all the basic blocks
		for(Function::iterator it = F.begin(), it_end = F.end();
				it != it_end ; it++ ){
			worklist.push_back( it );	
		}

		//worklist algorithms
		while(!worklist.empty()){
			BasicBlock * b_ptr = worklist.pop_back_val();
			regSet beforeSet =  BB_liveBefore[b_ptr];
			regSet afterSet  =  BB_liveAfter[b_ptr];
			regSet genSet = BB_gen[b_ptr];
			regSet killSet = BB_kill[b_ptr];

			//???
			bool shouldAddPred = !BB_liveBefore.count(b_ptr);
	
			set<unsigned> succ_set;
			for(succ_iterator succ_it = succ_begin(b_ptr), succ_it_end = succ_end(b_ptr);
					succ_it != succ_it_end; succ_it++){
				set<unsigned> t_set = BB_liveBefore[(*succ_it)] ;
				succ_set.insert(t_set.begin(), t_set.end());
			}

			beforeSet.clear();
			set_difference(succ_set.begin(), succ_set.end(), 
					killSet.begin(), killSet.end(),
                    inserter( beforeSet, beforeSet.end()));
        	beforeSet.insert(genSet.begin(), genSet.end());

			if(succ_set != afterSet){
				shouldAddPred = true;
				afterSet = succ_set;
				//beforeSet.clear();
				//set_difference(succ_set.begin(), succ_set.end(), 
				//		killSet.begin(), killSet.end(),
                //      inserter( beforeSet, beforeSet.end()));
          		//beforeSet.insert(genSet.begin(), genSet.end());
			}

			if(shouldAddPred){
				 for (pred_iterator PI = pred_begin(b_ptr), E = pred_end(b_ptr); PI != E; ++PI)
            			worklist.push_back(*PI);
			}

			BB_liveBefore[b_ptr] = beforeSet;
			BB_liveAfter[b_ptr] = afterSet;
		}
		return;
	}
/*
	set<unsigned> compute_liveAfter(Function &F, const Function::iterator &f_it){
		set<unsigned int> liveAfter_set;
		for(succ_iterator succ_it = succ_begin(f_it), succ_it_end = succ_end(f_it); 
				succ_it != succ_it_end; succ_it++){
			regSet succ_liveBefore_set = 
				BB_liveBefore[(BasicBlock*)(*succ_it)];
			for(set<unsigned>::iterator it_set = succ_liveBefore_set.begin(), 
					it_set_end = succ_liveBefore_set.end(); 
					it_set != it_set_end ; 
					it_set++){
				liveAfter_set.insert( (*it_set) );	
			}
		}

		//printSet("liveAfter", (*f_it).getName().str(), liveAfter_set);
		return liveAfter_set;
	}

	set<unsigned> compute_liveBefore(const Function::iterator &f_it, const set<unsigned> &liveAfter_set, const set<unsigned> &gen_set, const set<unsigned> &kill_set){
		//Before = after + gen - kill
		set<unsigned> liveBefore_set;
		set<unsigned>::iterator it_gen = gen_set.begin();
		
		liveBefore_set = liveAfter_set;
		for( set<unsigned>::iterator it = kill_set.begin(), it_end = kill_set.end(); it!=it_end; it++ ){
			liveBefore_set.erase( (*it) );
		}

		for( set<unsigned>::iterator it = gen_set.begin(), it_end = gen_set.end(); it!=it_end; it++ ){
			liveBefore_set.insert( (*it) );
		}


		BB_liveBefore[(BasicBlock *)f_it] = liveBefore_set;

		//printSet("liveBefore", (*f_it).getName().str(), liveBefore_set);
		return liveBefore_set;
	}
*/
	void compute_killSet(Function::iterator &f_it, set<unsigned> &kill_set){
		BasicBlock::iterator b_it = (*f_it).begin(), b_it_rev = (*f_it).end();
		do{
			b_it_rev --;
			unsigned dest_reg = inst_map.find(b_it_rev)->second ;
			kill_set.insert(dest_reg);
		}while(b_it_rev != b_it);
		return;
	}

	void compute_genSet(Function::iterator &f_it, set<unsigned> &gen_set ){
		BasicBlock::iterator b_it = (*f_it).begin(), b_it_rev = (*f_it).end();
		do{
			b_it_rev --;
			int dest_reg = inst_map.find(b_it_rev)->second ;
			gen_set.erase(dest_reg);
			for(unsigned int i=0; i < (*b_it_rev).getNumOperands(); i++){
				if( isa<Instruction>( (*b_it_rev).getOperand(i)) ){
					int used_reg = inst_map.find( (Instruction *) (*b_it_rev).getOperand(i) )->second; 
					gen_set.insert(used_reg);	
				}
			}
			//gen_set.erase(dest_reg);
		}while(b_it_rev != b_it);
		return;
	}

	void compute_genKill(Function &F){
	  	Function::iterator f_it_begin = F.begin(), f_it_rev = F.end(); 
		do{
			f_it_rev--;
			set<unsigned> gen_set, kill_set;

			compute_genSet(f_it_rev, gen_set);
			compute_killSet(f_it_rev, kill_set);

			BB_gen[f_it_rev]=gen_set;
			BB_kill[f_it_rev]=kill_set;
		}while( f_it_rev != f_it_begin);
	}

	regSet compute_killSet_inst(Instruction *b_it){
		unsigned dest_reg = inst_map.find(b_it)->second ;
		regSet kill_set;
		kill_set.insert(dest_reg);
		return kill_set;
	}

	regSet compute_genSet_inst(Instruction *b_it){
		//unsigned dest_reg = inst_map.find(b_it)->second ;
		regSet gen_set_inst;
		for(unsigned i=0; i < (*b_it).getNumOperands(); i++){
			if( isa<Instruction>( (*b_it).getOperand(i)) ){
				unsigned used_reg = inst_map.find( (Instruction *) (*b_it).getOperand(i) )->second;
				gen_set_inst.insert(used_reg);	
			}
		}
		//gen_set_inst.erase(dest_reg);
		return gen_set_inst;
	}

	regSet compute_liveAfter_inst( const regSet &succ_liveBefore, BasicBlock::iterator b_it_cur){
		regSet liveAfter_set_inst(succ_liveBefore);
		BB_liveAfter_inst[b_it_cur] = liveAfter_set_inst;
		return liveAfter_set_inst;
	}

	regSet compute_liveBefore_inst(const regSet &liveAfter_set, regSet &gen_set, 
									regSet &kill_set, BasicBlock::iterator b_it_cur){
		regSet liveBefore = liveAfter_set;
		for(regSet::iterator k_it = kill_set.begin(), k_it_end = kill_set.end();k_it!=k_it_end; k_it ++){
			liveBefore.erase( *k_it);	
		}
		regSet::iterator g_it = gen_set.begin(), g_it_end = gen_set.end();
		liveBefore.insert( g_it, g_it_end );	
		BB_liveBefore_inst[b_it_cur] = liveBefore;
		return liveBefore;
		//return;
	}

	void compute_live_inst(Function &F){
	  	Function::iterator f_it_begin = F.begin(), f_it_rev = F.end(); 
		do{
			f_it_rev--;
			BasicBlock::iterator b_it_begin = (*f_it_rev).begin(), b_it_rev = (*f_it_rev).end();
			regSet liveAfter_set(BB_liveAfter[f_it_rev]);
			regSet succ_before(liveAfter_set);
			do{
				b_it_rev--;

				regSet kill_set_inst = compute_killSet_inst( b_it_rev);
				regSet gen_set_inst = compute_genSet_inst( b_it_rev);	

				compute_liveAfter_inst(succ_before, b_it_rev);
				succ_before = compute_liveBefore_inst( succ_before, gen_set_inst, kill_set_inst, 
											b_it_rev);
			}while(b_it_rev != b_it_begin);
		}while(f_it_rev != f_it_begin);
	}

	void itMap(Function &F){
	  	//steve************************************************************
	  	//1. iterator over inst, creat a map from inst addr to int
		for(Function::iterator f_it = F.begin(), f_it_end = F.end();f_it != f_it_end; f_it++){
			for(BasicBlock::iterator b_it = (*f_it).begin(), b_it_end = (*f_it).end(); b_it != b_it_end; b_it++){
				doMap(b_it, inst_num);
				inst_num ++;
			}
		}
	}


	void itBasicBlock(Function &F){
	  	//2. iterator over basic blocks
	  	for(Function::iterator f_it = F.begin(), f_it_end = F.end(); f_it != f_it_end; f_it++){
			cerr << endl;
			cerr << "BASIC BLOCK " << (*f_it).getName().str() << "\n";
			//insert the gen into the map
			BasicBlock::iterator b_it = (*f_it).begin(), b_it_rev = (*f_it).end();
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

	bool isAssign(Instruction* it){
		if( it->isBinaryOp() ) 
			return true;
		if( it->isShift() )
			return true;
		if( it->isCast() )
			return true;
		switch( it->getOpcode() ){
			case 26:
			case 27:
			case 29:
			case 45:
			case 46:
			case 49:
			case 53:
			case 56:
				return true;
			default:
				return false; break;
		}
		return false;	
	}

	list<Instruction *> compute_useless_inst(Function &F){
		list<Instruction *> useless_inst;
	  	for(Function::iterator f_it = F.begin(), f_it_end = F.end(); f_it != f_it_end; f_it++){
			BasicBlock::iterator b_it = (*f_it).begin(), b_it_rev = (*f_it).end();
			do{
				b_it_rev --;
				if( isAssign(b_it_rev) == false)
					continue;
				regSet liveAfter_set_inst = BB_liveAfter_inst[b_it_rev];
				unsigned dest_reg = inst_map.find(b_it_rev)->second ;
				if( !liveAfter_set_inst.count(dest_reg) ){
					useless_inst.push_back(b_it_rev);
					RemovedInstructionCount++;
				}
	  		}while( b_it_rev != b_it );	
		}
		return useless_inst;
	}

	void print_anal_result(Function &F){
		if(PRINT_ANAL_RESULTS == true ){
      		std::cerr << "FUNCTION " << F.getName().str() << "\n";
	  		for(Function::iterator f_it = F.begin(), f_it_end = F.end(); f_it != f_it_end; f_it++){
				cerr << std::endl;
				cerr << "BASIC BLOCK " << (*f_it).getName().str() << "  ";
				cerr << "L-Before: {" ;
				printSet(BB_liveBefore[f_it]);
				cerr << " }  L-After: {" ;
				printSet(BB_liveAfter[f_it]);
				cerr << " }" << endl;

				for(BasicBlock::iterator b_it = (*f_it).begin(), b_it_end = (*f_it).end(); b_it != b_it_end; b_it++){
					cerr << "%" << inst_map[b_it] << ":   L-Before: {";
					printSet(BB_liveBefore_inst[b_it]);
					cerr << " }\tL-After: {";
					printSet(BB_liveAfter_inst[b_it]);
					cerr << " }" << endl;
	  			}	
			}
		}
		return;
	}

	void print_anal_removing(list<Instruction *> useless_inst){
		if(PRINT_REMOVING == true){
			cerr << endl;
			for(list<Instruction *>::iterator it = useless_inst.begin(), it_end = useless_inst.end();
					it!=it_end; it++){
				cerr << "removing useless assignment %" << inst_map[*it] << endl;
			}
		}
	}

	bool remove_useless_inst(list<Instruction *> useless_inst){
		for(list<Instruction *>::iterator it = useless_inst.begin(); it != useless_inst.end(); it++){
				(*it)->eraseFromParent();
		}
		return !useless_inst.empty();
	}

    public:

    static char ID; // Pass identification, replacement for typeid

    liveVars() : FunctionPass(ID) {
			//inst_num = 0;
	}
    
    //**********************************************************************
    // runOnFunction
    //**********************************************************************
    virtual bool runOnFunction(Function &F) {
      	// print fn name
      	bool isModified = false;	

		itMap(F);
		//itBasicBlock(F);
		compute_genKill(F);
		compute_live(F);	  	

		compute_live_inst(F);
		list<Instruction *> useless_inst = compute_useless_inst(F);
		
		print_anal_result(F);
		print_anal_removing(useless_inst);
		
		isModified = remove_useless_inst(useless_inst);
      	return isModified;  // because we have NOT changed this function
    }

    //**********************************************************************
    // print (do not change this method)
    //
    // If this pass is run with -f -analyze, this method will be called
    // after each call to runOnFunction.
    //**********************************************************************
    virtual void print(std::ostream &O, const Module *M) const {
        O << "This is printCode.\n";
    }

    //**********************************************************************
    // getAnalysisUsage
    //**********************************************************************

    // We don't modify the program, so we preserve all analyses
    virtual void getAnalysisUsage(AnalysisUsage &AU) const {
      //AU.setPreservesAll();
    };

};
char liveVars::ID = 0;

// register the liveVars class: 
//  - give it a command-line argument (liveVars)
//  - a name ("live Vars")
//  - a flag saying that we don't modify the CFG
//  - a flag saying this is not an analysis pass
RegisterPass<liveVars> X("liveVars", "live vars analysis", false, true);

}
