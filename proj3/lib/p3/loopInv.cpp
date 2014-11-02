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
#include "llvm/Support/CFG.h"
#include "llvm/ADT/SmallVector.h"
#include "llvm/Analysis/Dominators.h"
#include "llvm/Transforms/Utils/BasicBlockUtils.h"
#include "llvm/ADT/ArrayRef.h"

#include "flags.h"
#include <assert.h>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <list>
#include <stack>

//#define STEVE_DEBUG

using namespace llvm;
using namespace std;

namespace {
STATISTIC(LoopInvariantInstructionCount, "Number of loop-invariant instructions moved");
class naturalLoop;

class naturalLoop{
private:
    set<const BasicBlock*> body;
    const BasicBlock* head;
    set<const Instruction*> loopInvInsts;

public:
    naturalLoop(){
    }

    naturalLoop(const BasicBlock *loopHead){
        setHead(loopHead);
        insertBody(loopHead);
    }

    void insertLoopInvInst(const Instruction * inst){
        loopInvInsts.insert(inst);
    }

    set<const Instruction *> *getLoopInvInsts(){
        return &(this->loopInvInsts);
    }

    const set<const Instruction *> *getLoopInvInsts() const{
        return &(this->loopInvInsts);
    }

    bool isInLoopInvInsts(const Instruction * cmpInst) const{
        if( loopInvInsts.find(cmpInst) == loopInvInsts.end()){
            return false;
        }
        return true;
    }

    void setHead(const BasicBlock *loopHead){
        this->head = loopHead;
    }

    void insertBody(const BasicBlock *bodyBB){
        this->body.insert(bodyBB);
    }

    set<const BasicBlock*> *getBody() {
        return &(this->body);
    }

    const set<const BasicBlock*> *getBody() const{
        return &(this->body);
    }

    const BasicBlock* getHead() const{
        return this->head;
    }
/*
    BasicBlock* getHead() {
        BasicBlock * newHead = this->head;
        return newHead;
    }
    */

    int getSize(){
        return (this->body).size();
    }

    bool isInBody(const BasicBlock * findBB){
        return (body.find(findBB)==body.end() )?false:true;
    }

    void printBody(){
        cerr<<" Body: { ";
        for(set<const BasicBlock*>::const_iterator it = body.begin();it != body.end(); it++){
            if( *it == head )
                continue;
            cerr << (*it)->getName().str() << " ";
        }
        cerr<<"}"<<endl;
    }

    void printHead(){
        cerr << "Head: " <<  head->getName().str();
    }
};

struct comp_NL{
    bool operator()(naturalLoop* const NL1, naturalLoop* const NL2)const{
        string name1 = (NL1->getHead())->getName().str();
        string name2 = (NL2->getHead())->getName().str();
        if(NL1->getSize()!=NL2->getSize()){
            return (NL1->getSize() > NL2->getSize())?true:false;
        }else{
            return lexicographical_compare(name1.begin(), name1.end(),
                    name2.begin(), name2.end());
        }
    }
};

unsigned int inst_num = 1  ;
unsigned int BB_num = 1  ;

map<const Instruction* , unsigned int> inst_map;
//a map for block B to dom(B)
typedef set<const BasicBlock *> domSet ;
typedef map<const BasicBlock *, domSet > BBDomSet;
typedef deque<const BasicBlock *> BBworklist;
typedef map<const BasicBlock*, const BasicBlock *> BBBackedgeMap;
typedef set<naturalLoop*, comp_NL> naturalLoopSet;
//typedef multiset<naturalLoop*, comp_NL> naturalLoopSet;
typedef list<naturalLoop* > naturalLoopList;
typedef map<const BasicBlock *,  naturalLoopList> naturalLoopMap;


class loopInv : public FunctionPass {
	private:
    map<const BasicBlock* , unsigned int> BB_map;
    //BBDomSet BB_dom;
    //BBBackedgeMap BB_backedge;
    //naturalLoopMap naturalLoops;
    //naturalLoopSet sortedNaturalLoops;
    set<const Instruction *> loopInvInst;

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
			for(BasicBlock::const_iterator b_it = (*f_it).begin(), b_it_rev = (*f_it).end();
                    b_it != b_it_rev ; b_it++){
				//dest seudo reg
				int dest_reg = inst_map.find(b_it)->second ;
				cerr << "%" << dest_reg << ":\t" ;
				//op
				cerr << (*b_it).getOpcodeName() <<"\t" ;
				for(unsigned int i=0; i < (*b_it).getNumOperands(); i++){
					if( isa<Instruction>( (*b_it).getOperand(i)) ){
						cerr << " %" << inst_map.find( (Instruction *) (*b_it).getOperand(i) )->second;
					}
					else if( (*b_it).getOperand(i)->hasName() ){
						errs() << " " << (*b_it).getOperand(i)->getName();// << "\t";
					}
					else {
						cerr << " XXX";
					}
				}
				cerr << endl;
	  		}
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

    void initDom(const BasicBlock *blk, BBDomSet &BB_dom, domSet &init_domN,
            set<const BasicBlock *> &visitedBB){
        BB_dom[blk] = init_domN;
        visitedBB.insert(blk);
        for( succ_const_iterator it = succ_begin(blk);
                it!=succ_end(blk); it++){
            if( visitedBB.find(*it) != visitedBB.end() )
                continue;
            initDom(*it, BB_dom, init_domN, visitedBB);
        }
        return;
    }

    BBDomSet findBBDom(const Function &F){
        BBDomSet BB_dom;
        BBworklist worklist;
        //dom(N0) = {N0}, never change
        domSet domN0;
        domN0.insert(F.begin());

        BB_dom[F.begin()] = domN0;

        //dom(N) = {all nodes}
        domSet init_domN;
        //set all blank ********
		for(Function::const_iterator f_it = (++F.begin()), f_it_end = F.end();
                f_it != f_it_end; f_it++){
            BB_dom[f_it] = init_domN;
		}

		for(Function::const_iterator f_it = F.begin(), f_it_end = F.end();
                f_it != f_it_end; f_it++){
            init_domN.insert(f_it);
		}
        //except N0

        //push all nodes but N0 into worklist
        //initialize the worklist with the successors of entry block instead
        //of all blocks
        set<const BasicBlock *> visitedBB;
        for(succ_const_iterator it = succ_begin(F.begin());
                it != succ_end(F.begin()); it++){
            initDom( *it, BB_dom, init_domN, visitedBB);
            worklist.push_back(*it);
        }

#ifdef STEVE_DEBUG
        cerr << "before worklist algo: " <<endl;
        printWorklist(worklist);
        cerr << "worklist algo start...  " <<endl;
#endif

        do{
            if( worklist.empty() )
                break;

            const BasicBlock * BBN = worklist.front();
            worklist.pop_front();

#ifdef STEVE_DEBUG
            printWorklist(worklist);
#endif

            //dom(Z) = Z U ( ^<Y in pred(Z)> dom(Y) )
            domSet domZ(BB_dom[BBN]);
            if( pred_begin(BBN) == pred_end(BBN))
                break;
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

        return BB_dom;
    }

    void printBB_backedge(const BBBackedgeMap &BB_backedge){
        cerr<<"Backedge: "<<endl;
        for(BBBackedgeMap::const_iterator it = BB_backedge.begin(), it_e = BB_backedge.end();
                it!=it_e; it++){
            cerr<< BB_map[it->first] << "->"
                << BB_map[it->second]<<endl;
        }
    }

    BBBackedgeMap findBackedges(const Function &F, BBDomSet &BB_dom){
#ifdef STEVE_DEBUG
        cerr<< "findBackedges ... "<<endl;
#endif
        //const DominatorTree & DT = getAnalysis<DominatorTree>();
        //do DFS to traverse the tree and find back edges
        BBBackedgeMap BB_backedge;
        for(Function::const_iterator it = F.begin(), it_e = F.end();it!=it_e;it++){
            //cerr<<BB_map[it]<< ": ";
            for(succ_const_iterator succ_it = succ_begin(it), succ_it_e = succ_end(it);
                    succ_it!=succ_it_e;succ_it++){
                const BasicBlock *succBBptr = *succ_it;

                domSet domThis = BB_dom[it];
                if( domThis.find( succBBptr )!=domThis.end() ){
                    BB_backedge[it] = succBBptr;
                }
            }
        }

#ifdef STEVE_DEBUG
        printBB_backedge(BB_backedge);
#endif
        return BB_backedge;
    }

    void printNL(string header, const naturalLoopMap &naturalLoops){
        cerr<< header <<endl;
        for(naturalLoopMap::const_iterator it=naturalLoops.begin();
                it!=naturalLoops.end();it++){

            cerr << BB_map[it->first] << ": ";
            naturalLoopList curList = it->second;

            for(naturalLoopList::const_iterator it = curList.begin();
                    it != curList.end(); it++){
                const set<const BasicBlock *> *body = (*it)->getBody();

                for(set<const BasicBlock*>::const_iterator it_BB = body->begin();
                        it_BB!= body->end();it_BB++){
                    cerr<< BB_map[*it_BB] << " ";
                }
                cerr<<endl;
            }
        }
    }

    naturalLoopMap findNaturalLoops(const BBBackedgeMap &BB_backedge){
#ifdef STEVE_DEBUG
        cerr<< "findNaturalLoops ... "<<endl;
#endif
        naturalLoopMap naturalLoops;

        cout<<"***Warning: didn't take care of irreducible CFG" <<endl;
        for(BBBackedgeMap::const_iterator it_BEmap = BB_backedge.begin();
                it_BEmap != BB_backedge.end(); it_BEmap++){

            const BasicBlock *loopHead = it_BEmap->second;
            const BasicBlock *loopEnd  = it_BEmap->first;
            stack<const BasicBlock *> bodyStack;

            //body = {H}
            naturalLoop *NL = new naturalLoop(loopHead);
            bodyStack.push(loopEnd);

            while(!bodyStack.empty()){
                const BasicBlock *curBB = bodyStack.top(); bodyStack.pop();
                if( !NL->isInBody(curBB) ){
                    NL->insertBody(curBB);
                    for(const_pred_iterator pred_it = pred_begin(curBB);
                            pred_it != pred_end(curBB); pred_it++){
                        bodyStack.push(*pred_it);
                    }
                }
            }

            if( !(naturalLoops.find( loopHead)==naturalLoops.end()) ){
                (naturalLoops.find(loopHead)->second).push_back(NL);
            }else{
                naturalLoopList newNLList;
                newNLList.push_back(NL);
                naturalLoops[loopHead] = newNLList;
            }
        }
#ifdef STEVE_DEBUG
        printNL("Natural loops(pre-combination): ", naturalLoops);
#endif
        return naturalLoops;
    }

    void printSortedNL(string str, const naturalLoopSet &sortedNaturalLoops){
        cerr << str << endl;
        for( naturalLoopSet::const_iterator it = sortedNaturalLoops.begin();
                it!=sortedNaturalLoops.end(); it ++){
            cerr << BB_map[ (*it)->getHead() ] << ": " << (*it)->getSize() << endl;
        }
    }

    naturalLoopSet combineLoops(naturalLoopMap &naturalLoops){
#ifdef STEVE_DEBUG
        cerr<< "combineLoops ... "<<endl;
#endif
        naturalLoopSet sortedNaturalLoops;
        for(naturalLoopMap::iterator it_NL = naturalLoops.begin();
                it_NL!=naturalLoops.end(); it_NL++){

            naturalLoopList *curList = &(it_NL->second);
            if(curList->size() > 1){
#ifdef PRINTMERGE
                cerr << "merging " << curList->size() << " loops with header "
                    << (it_NL->first)->getName().str() << endl;
#endif
                //add header to the combined Nloop
                naturalLoop *combinedNL = new naturalLoop(it_NL->first);

                for(naturalLoopList::iterator it_list = curList->begin();
                        it_list!=curList->end();it_list++){

                    set<const BasicBlock *> *curBody = (*it_list)->getBody();
                    for(set<const BasicBlock *>::const_iterator it = curBody->begin();
                            it!=curBody->end();it++){
                        combinedNL->insertBody( *it );
                    }
                    //remove cur NL from the list
                    delete *it_list;
                }
                curList->clear();
                sortedNaturalLoops.insert(combinedNL);
            }
            else if(curList->size()==1){
                sortedNaturalLoops.insert( *(curList->begin()) );
            }
        }
#ifdef STEVE_DEBUG
        printNL("Natural loops(post-combination): ", naturalLoops);
        printSortedNL("Sorted natural loops: ", sortedNaturalLoops);
#endif
        return sortedNaturalLoops;
    }

    void printLoopInv(const naturalLoop* NL){
        const set<const Instruction *> *loopInvInsts = NL->getLoopInvInsts();
        cerr<< "[ ";
        for(set<const Instruction *>::const_iterator it= loopInvInsts->begin();
                it != loopInvInsts->end();it++){
            cerr << inst_map[*it] << " ";
        }
        cerr<< "]" << endl;
    }

    //all operands are either literals or are defined outside the loop
    //the opcode is neither a division nor a remainder opcode
    //the instruction does not involve a memory operation
    //the instruction is not a terminator
    //the instruction is not a call or invoke
    //the instruction is not a Phi
    void findLoopInv(naturalLoopSet &sortedNaturalLoops){
#ifdef STEVE_DEBUG
        cerr << "Loop invariant: "<<endl;
#endif
        for(naturalLoopSet::iterator it = sortedNaturalLoops.begin();
                it != sortedNaturalLoops.end(); it++){
            naturalLoop * NL = (*it); //ptr to naturalLoop
            for(set<const BasicBlock *>::const_iterator it_BBset = NL->getBody()->begin();
                    it_BBset != NL->getBody()->end(); it_BBset++){

                for(BasicBlock::const_iterator it_BB = (*it_BBset)->begin();
                        it_BB != (*it_BBset)->end(); it_BB++){

                    bool isInv = true, isInvDefOut = true;
                    switch(it_BB->getOpcode()){
                        case 14:case 15: case 16: //division
                        case 17:case 18: case 19: //remainder
                        case 26: case 27: case 28: case 29: case 30: case 31: case 32://mem
                        case 48: //call
                        case 5:  //invoke
                        case 47: //phi
                            continue;
                        default:
                            break;
                    }
                    if(it_BB->isTerminator())
                        continue;

                    //operands are literals or def outside loop
                    for( unsigned i =0; i < it_BB->getNumOperands();i++){
                        //whether inst def outside
					    if( isa<Instruction>( (*it_BB).getOperand(i)) ){
                            for(set<const BasicBlock *>::const_iterator it_loop = NL->getBody()->begin();
                                    it_loop != NL->getBody()->end(); it_loop++){
                                for(BasicBlock::const_iterator it_loopBB = (*it_loop)->begin();
                                        it_loopBB != (*it_loop)->end(); it_loopBB++){
                                    const Instruction * op = (Instruction *)(*it_BB).getOperand(i);
                                    if( (const Instruction *)it_loopBB == op ){
                                        if( NL->isInLoopInvInsts((const Instruction *)it_loopBB) ){
                                            continue;
                                        }
                                        isInv = false;
                                    }
                                }
                            }
					    }
                        //not literal
					    else if( (*it_BB).getOperand(i)->hasName() ){
                            if( (*it_BB).getOperand(i)->getName().str() == "argv"){
                                //cerr << "argv" << endl;
                                continue;
                            }
                            if( (*it_BB).getOperand(i)->getName().str() == "argc"){
                                //cerr << "argc" << endl;
                                continue;
                            }
                            isInv = false;
                            break;
					    }
                    }

                    if(isInv){
                        NL->insertLoopInvInst( it_BB );
                    }
                }
            }
#ifdef STEVE_DEBUG
            printLoopInv(NL);
#endif
        }
    }

    bool moveLoopInvInstOut(naturalLoopSet &sortedNaturalLoops){
#ifdef STEVE_DEBUG
        cerr<< "moveLoopInvInstOut ... "<<endl;
#endif
        //creat and fill the a Preds array, an array of blocks, preds should be BB**
        bool isModified = false;

        for(naturalLoopSet::iterator it_NL = sortedNaturalLoops.begin();
                it_NL != sortedNaturalLoops.end(); it_NL++){

            BasicBlock* headBB =(BasicBlock *) (*it_NL)->getHead();
            set<const Instruction*> * loopInvInsts = (*it_NL)->getLoopInvInsts();

            if(loopInvInsts->empty())
                continue;

            //fill int the Preds
            //for(pred_iterator pred_it =pred_begin(headBB);
            //        pred_it != pred_end(headBB); pred_it++){
            //    asize++;
            //}
            int asize=0;
            for(pred_iterator pred_it =pred_begin(headBB);
                    pred_it != pred_end(headBB) ; pred_it++){
                if( (*it_NL)->getBody()->find(*pred_it) == (*it_NL)->getBody()->end()){
                    asize++;
                }
            }

            BasicBlock *Preds[asize];
            int i = 0;
            for(pred_iterator pred_it =pred_begin(headBB);
                    pred_it != pred_end(headBB) ; pred_it++){
                if( (*it_NL)->getBody()->find(*pred_it) == (*it_NL)->getBody()->end()){
                    //cerr << "Here:" << BB_map[*pred_it] << endl;
                    Preds[i] = *pred_it;
                    i++;
                }
            }

            BasicBlock * preHeader;
            if( asize > 1 ){
                //find pred of the header
                //add preheader
                preHeader = SplitBlockPredecessors(headBB, ArrayRef<BasicBlock *>(Preds, asize), "PreHeader", 0);
#ifdef PRINTPRE
                cerr << "adding preheader for loop with header " << headBB->getName().str()<<endl;
#endif
            } else if( asize == 1 ){
                preHeader = Preds[0];
                //cerr << "preHeader:"<<BB_map[preHeader] << endl;
            } else {
                cerr << "pred header error" << endl;
                exit(0);
            }

            //insert the instruction into the basic block, before the terminator,
            //using getTerminator()
            Instruction * terminator = preHeader->getTerminator();

            for(set<const Instruction *>::iterator it_IS = loopInvInsts->begin();
                    it_IS != loopInvInsts->end(); it_IS++){
                ((Instruction*)(*it_IS))->moveBefore(terminator);
#ifdef PRINTMOVING
                cerr << "moving instruction %" << inst_map[(*it_IS)] << endl;
#endif
                LoopInvariantInstructionCount++;
                isModified = true;

            }
        }
        return isModified;
    }

    void print_BeforedomSet(const domSet &inSet, const BasicBlock * thisBB){
        cerr << "DOM-Before: { " ;
        for(domSet::const_iterator it=inSet.begin(), it_end = inSet.end();it!=it_end;it++){
            if( (*it) == thisBB)
                continue;

            cerr << (*it)->getName().str();
#ifdef STEVE_DEBUG
            cerr << "( "<< BB_map[(*it)] << " )";
#endif
            cerr << " ";
        }
        cerr << "} ";
    }

    void print_AfterdomSet(const domSet &inSet){
        cerr << " DOM-After: { " ;
        for(domSet::const_iterator it=inSet.begin(), it_end = inSet.end();it!=it_end;it++){
            cerr << (*it)->getName().str();
#ifdef STEVE_DEBUG
            cerr << "( "<< BB_map[(*it)] << " )";
#endif
            cerr << " ";
        }
        cerr << "}";
    }

    void print_BB_dom(BBDomSet &BB_dom){
        cerr<<endl;
        for(BBDomSet::const_iterator it = BB_dom.begin(), it_end = BB_dom.end();
            it!= it_end; it++){
            cerr <<"BASIC BLOCK "<< (it->first)->getName().str() << " "
#ifdef STEVE_DEBUG
                << BB_map[it->first]
#endif
            << " ";
            print_BeforedomSet( it->second, it->first );
            print_AfterdomSet( it->second );
            cerr<<endl;
        }
        cerr << endl;
    }

    void printLoops(const naturalLoopSet &sortedNaturalLoops){
        cerr << "LOOPS" << endl;
        for( naturalLoopSet::const_iterator it = sortedNaturalLoops.begin();
                it!=sortedNaturalLoops.end(); it ++){
                (*it)->printHead();
                (*it)->printBody();
        }
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
#ifdef STEVE_DEBUG
		itBasicBlock(F);
#endif

        //find loops
        BBDomSet BB_dom = findBBDom(F);

#ifdef PRINTDOM
        cerr << "FUNCTION " << F.getName().str() << "\n";
        print_BB_dom(BB_dom);
#endif
        //find back edges
        BBBackedgeMap BB_backedge  = findBackedges(F, BB_dom);

        //find natural loops
        naturalLoopMap naturalLoops = findNaturalLoops(BB_backedge);

        //combine loops with the same header
        naturalLoopSet sortedLoops = combineLoops( naturalLoops );

#ifdef PRINTLOOPS
        cerr << "FUNCTION " << F.getName().str() << "\n";
        printLoops(sortedLoops);
#endif

        //find loop invariant instructions
        findLoopInv(sortedLoops);

        //move them out of loops
        isModified = moveLoopInvInstOut(sortedLoops);

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

