//===--- precomputed_tpl_args_cpp17.cc - test input file for iwyu ---------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// IWYU_ARGS: -I . --std=c++17

// Tests full contained type requirements for STL containers in C++17.

#include <vector>
#include <set>
#include <map>
#include <list>
#include <forward_list>
#include "tests/cxx/direct.h"

void Fn() {
  // Since C++17, full contained type isn't needed for vector, list, and
  // forward-list instantiation.
  // IWYU: IndirectClass needs a declaration
  (void)sizeof(std::vector<IndirectClass>);
  // IWYU: IndirectClass needs a declaration
  (void)sizeof(std::list<IndirectClass>);
  // IWYU: IndirectClass needs a declaration
  (void)sizeof(std::forward_list<IndirectClass>);

  // Full type is still needed for other container types.
  // IWYU: IndirectClass needs a declaration
  // IWYU: IndirectClass is...*indirect.h
  (void)sizeof(std::set<IndirectClass>);
  // IWYU: IndirectClass needs a declaration
  // IWYU: IndirectClass is...*indirect.h
  (void)sizeof(std::multiset<IndirectClass>);
  // IWYU: IndirectClass needs a declaration
  // IWYU: IndirectClass is...*indirect.h
  (void)sizeof(std::map<IndirectClass, int>);
  // IWYU: IndirectClass needs a declaration
  // IWYU: IndirectClass is...*indirect.h
  (void)sizeof(std::multimap<IndirectClass, int>);

  // Full type is required for, e.g., destroying sequence containers.
  // IWYU: IndirectClass needs a declaration
  std::vector<IndirectClass>* v;
  // IWYU: IndirectClass is...*indirect.h
  delete v;
  // IWYU: IndirectClass needs a declaration
  std::list<IndirectClass>* l;
  // IWYU: IndirectClass is...*indirect.h
  delete l;
  // IWYU: IndirectClass needs a declaration
  std::forward_list<IndirectClass>* fl;
  // IWYU: IndirectClass is...*indirect.h
  delete fl;
}


/**** IWYU_SUMMARY

tests/cxx/precomputed_tpl_args_cpp17.cc should add these lines:
#include "tests/cxx/indirect.h"

tests/cxx/precomputed_tpl_args_cpp17.cc should remove these lines:
- #include "tests/cxx/direct.h"  // lines XX-XX

The full include-list for tests/cxx/precomputed_tpl_args_cpp17.cc:
#include <forward_list>  // for forward_list
#include <list>  // for list
#include <map>  // for map, multimap
#include <set>  // for multiset, set
#include <vector>  // for vector
#include "tests/cxx/indirect.h"  // for IndirectClass

***** IWYU_SUMMARY */
