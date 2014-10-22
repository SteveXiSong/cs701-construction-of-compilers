//===--------------- printCode.cpp - Project 1 for CS 701 ---------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file is a skeleton of an implementation for the printCode
// pass of Univ. Wisconsin-Madison's CS 701 Project 1.
//
//===----------------------------------------------------------------------===//

#define DEBUG_TYPE "printCode"
#include "llvm/Pass.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/Instruction.h"
#include "llvm/ADT/StringExtras.h"
#include "llvm/ADT/Statistic.h"
#include "llvm/Support/InstIterator.h"
#include "llvm/Support/raw_ostream.h"
#include <iostream>
#include <vector>

//steve****************
//#include "instMapInt.h"
//*********************

using namespace llvm;
/*
class instMapInt{
	public:
		static std::map<llvm::Instruction* , unsigned int> inst_map;
		static bool doMap(llvm::Instruction *pinst, const unsigned int mapVal){
			std::cout << "mapping inst ptr (%p)" << pinst << "--> (%u)" << mapVal << std::endl;
			inst_map[pinst] = mapVal;
			return true;
		}
};
*/
namespace {
	unsigned int inst_num = 1  ;
	std::map<llvm::Instruction* , unsigned int> inst_map;

  class printCode : public FunctionPass {
		private:
		//std::map<llvm::Instruction* , unsigned int> inst_map;
		bool doMap(llvm::Instruction *pinst, const unsigned int mapVal){
			//std::cerr << "###mapping inst ptr" << pinst << "-->" << mapVal << std::endl;
			inst_map[pinst] = mapVal;
			return true;
		}

    public:

    static char ID; // Pass identification, replacement for typeid

    printCode() : FunctionPass(ID) {
			//inst_num = 0;
		}
    
    //**********************************************************************
    // runOnFunction
    //**********************************************************************
    virtual bool runOnFunction(Function &F) {
      // print fn name
      std::cerr << "FUNCTION " << F.getName().str() << "\n";

      // MISSING: Add code here to do the following:
      //          1. Iterate over the instructions in F, creating a
      //             map from instruction address to unique integer.
      //             (It is probably a good idea to put this code in
      //             a separate, private method.)
      //          2. Iterate over the basic blocks in the function and
      //             print each instruction in that block using the format
      //             given in the assignment.

	  	//steve************************************************************
	  	//1. iterator over inst, creat a map from inst addr to int
			for(Function::iterator f_it = F.begin(), f_it_end = F.end();f_it != f_it_end; f_it++){
				for(BasicBlock::iterator b_it = (*f_it).begin(), b_it_end = (*f_it).end(); b_it != b_it_end; b_it++){
					//errs() << *b_it << "\n";
					doMap(b_it, inst_num);
					inst_num ++;
				}
			}

	  	//2. iterator over basic blocks
	  	for(Function::iterator f_it = F.begin(), f_it_end = F.end(); f_it != f_it_end; f_it++){
				std::cerr << std::endl;
				std::cerr << "BASIC BLOCK " << (*f_it).getName().str() << "\n";

				for(BasicBlock::iterator b_it = (*f_it).begin(), b_it_end = (*f_it).end(); b_it != b_it_end; b_it++){

					std::cerr << "%" << inst_map.find(b_it)->second << ":\t" ;
					std::cerr << (*b_it).getOpcodeName() <<"\t" ;	

					for(unsigned int i=0; i < (*b_it).getNumOperands(); i++){
						if( isa<Instruction>( (*b_it).getOperand(i)) ){
							std::cerr << " %" << inst_map.find( (Instruction *) (*b_it).getOperand(i) )->second; // << "\t";
						}
						else if( (*b_it).getOperand(i)->hasName() ){
							errs() << " " << (*b_it).getOperand(i)->getName();// << "\t";	
						}
						else {
							std::cerr << " XXX";
						}
					}
					std::cerr << std::endl;
	  		}	
			}
	  	//*****************************************************************
		std::cerr << std::endl;

      return false;  // because we have NOT changed this function
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
      AU.setPreservesAll();
    };

  };
  char printCode::ID = 0;

  // register the printCode class: 
  //  - give it a command-line argument (printCode)
  //  - a name ("print code")
  //  - a flag saying that we don't modify the CFG
  //  - a flag saying this is not an analysis pass
  RegisterPass<printCode> X("printCode", "print code",
			   true, false);
}
