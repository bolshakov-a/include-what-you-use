//===--- dependent_template.cc - test input file for iwyu -----------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// IWYU_ARGS: -I .

#include "tests/cxx/direct.h"

template <typename>
class IndirectTemplate;

template <typename T>
void TplFn() {
  //TODO: IndirectTemplate<T>::StaticMethod();
  using Type = typename IndirectTemplate<T>::Type;
}

/**** IWYU_SUMMARY

tests/cxx/dependent_template.cc should add these lines:

tests/cxx/dependent_template.cc should remove these lines:
- #include "tests/cxx/direct.h"  // lines XX-XX

The full include-list for tests/cxx/dependent_template.cc:
template <typename> class IndirectTemplate;  // lines XX-XX+1

***** IWYU_SUMMARY */
