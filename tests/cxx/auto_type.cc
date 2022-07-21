//===--- auto_type.cc - test input file for iwyu --------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// IWYU_ARGS: -I .

// Tests initializing variables of deduced type.

#include "tests/cxx/direct.h"

// IWYU: IndirectClass needs a declaration
const IndirectClass& Fn();

// Variable of deduced type 'IndirectClass' is initialized from reference, hence
// full type is needed.
// IWYU: IndirectClass is...*indirect.h
auto var = Fn();
// Even no fwd-decl usage for initializing reference of deduced type.
auto& ref1 = Fn();
// 'decltype(auto)' is deduced as reference in this case, hence no reporting.
decltype(auto) ref2 = Fn();

/**** IWYU_SUMMARY

tests/cxx/auto_type.cc should add these lines:
#include "tests/cxx/indirect.h"

tests/cxx/auto_type.cc should remove these lines:
- #include "tests/cxx/direct.h"  // lines XX-XX

The full include-list for tests/cxx/auto_type.cc:
#include "tests/cxx/indirect.h"  // for IndirectClass

***** IWYU_SUMMARY */
