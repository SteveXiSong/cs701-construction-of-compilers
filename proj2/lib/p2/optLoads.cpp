//===--------------- optLoads.cpp - Project 1 for CS 701 ---------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file is a skeleton of an implementation for the optCode
// pass of Univ. Wisconsin-Madison's CS 701 Project 1.
//
//===----------------------------------------------------------------------===//

#define DEBUG_TYPE "optLoads"
#include "llvm/Pass.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/Instruction.h"
#include "llvm/ADT/StringExtras.h"
#include "llvm/ADT/Statistic.h"
#include "llvm/Support/InstIterator.h"
#include "llvm/Support/raw_ostream.h"

#include "llvm/IR/Value.h"

#include <iostream>
#include <vector>
#include <list>

using namespace llvm;
namespace {
	std::map<llvm::Instruction* , unsigned int> inst_map;
	unsigned int inst_num = 1;

  class optLoads : public FunctionPass {
		private:
		//std::map<llvm::Instruction* , unsigned int> inst_map;
		//unsigned int inst_num ;
		bool doMap(llvm::Instruction *pinst, const unsigned int mapVal){
			//std::cerr << "###mapping inst ptr" << pinst << "-->" << mapVal << std::endl;
			inst_map[pinst] = mapVal;
			return true;
		}
    public:
    static char ID; // Pass identification, replacement for typeid

    optLoads() : FunctionPass(ID) {
			//inst_num =0;
		}
    
    //**********************************************************************
    // runOnFunction
    //**********************************************************************
    virtual bool runOnFunction(Function &F) {
      // print fn name
      //std::cerr << "FUNCTION " << F.getName().str() << "\n";

			for(Function::iterator f_it = F.begin(), f_it_end = F.end();f_it != f_it_end; f_it++){
				for(BasicBlock::iterator b_it = (*f_it).begin(), b_it_end = (*f_it).end(); b_it != b_it_end; b_it++){
					//errs() << *b_it << "\n";
					doMap(b_it, inst_num);
					inst_num ++;
				}
			}
		
#define RUN_TIME
#ifdef RUN_TIME
			std::list<Instruction *> unnc_inst_p_list;
			bool is_changed= false;

			for(Function::iterator f_it = F.begin(), f_it_end = F.end(); f_it != f_it_end; f_it++){
				//from the seconde instruction


				BasicBlock::iterator b_it_next;
				for(BasicBlock::iterator b_it = (*f_it).begin(), b_it_next = b_it, b_it_end = (*f_it).end(); b_it !=b_it_end; b_it++){
					b_it_next++;

					if(  (*(b_it)).getOpcode() == Instruction::Store 
						&& (*(b_it_next)).getOpcode() == Instruction::Load ){
						assert( (*(b_it)).getNumOperands() >=2 );

						if(  (*(b_it)).getOperand(1) ==  (*b_it_next).getOperand(0) ){

							std::cerr << "%"<< inst_map.find( b_it_next )->second << " is a useless load" <<std::endl;
							inst_map.erase( b_it_next );
							b_it_next->replaceAllUsesWith( (*b_it).getOperand(0) );
							unnc_inst_p_list.push_back( b_it_next );

							is_changed = true;
						}	
					}
				}
			}

			for(std::list<Instruction *>::iterator it = unnc_inst_p_list.begin(); it != unnc_inst_p_list.end(); it++){
				(*it)->eraseFromParent();
			}
#endif

		if(is_changed == true)
			return true;
		else
      		return false;  
    }

    //**********************************************************************
    // print (do not change this method)
    //
    // If this pass is run with -f -analyze, this method will be called
    // after each call to runOnFunction.
    //**********************************************************************
    virtual void print(std::ostream &O, const Module *M) const {
        O << "This is optLoads.\n";
    }

    //**********************************************************************
    // getAnalysisUsage
    //**********************************************************************

    // We don't modify the program, so we preserve all analyses
    virtual void getAnalysisUsage(AnalysisUsage &AU) const {
      AU.setPreservesAll();
    };

  };
  char optLoads::ID = 0;

  // register the printCode class: 
  //  - give it a command-line argument (printCode)
  //  - a name ("opt loads")
  //  - a flag saying that we don't modify the CFG
  //  - a flag saying this is not an analysis pass
  RegisterPass<optLoads> X("optLoads", "optimize unnecessary loads",
			   false, false);
}
