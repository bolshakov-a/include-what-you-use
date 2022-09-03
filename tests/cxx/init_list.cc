//===--- init_list.cc - test input file for iwyu --------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// IWYU_ARGS: -I .

// Tests attributing initializer list to full type usage

#include "tests/cxx/init_list-d1.h"

// IWYU: PODStruct needs a declaration
void Fn1(PODStruct);

void Fn2() {
  // No reporting of PartAggregate or PartNonAggregate.
  // IWYU: PODStruct is...*init_list-i1.h
  Fn1({1, 2});
  // IWYU: PODStruct needs a declaration
  const PODStruct& ref
      // IWYU: PODStruct is...*init_list-i1.h
      = {3, 4};
}

/**** IWYU_SUMMARY

tests/cxx/init_list.cc should add these lines:
#include "tests/cxx/init_list-i1.h"

tests/cxx/init_list.cc should remove these lines:
- #include "tests/cxx/init_list-d1.h"  // lines XX-XX

The full include-list for tests/cxx/init_list.cc:
#include "tests/cxx/init_list-i1.h"  // for PODStruct

***** IWYU_SUMMARY */
