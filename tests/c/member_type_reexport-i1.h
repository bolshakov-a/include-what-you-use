//===--- member_type_reexport-i1.h - test input file for iwyu -------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#include "tests/c/direct.h"

struct Struct {
  // IWYU: Indirect is...*indirect.h
  struct Indirect i;
  struct Indirect* pi;
};

union Union {
  // IWYU: Indirect is...*indirect.h
  struct Indirect i;
  struct Indirect* pi;
};

/**** IWYU_SUMMARY

tests/c/member_type_reexport-i1.h should add these lines:
#include "tests/c/indirect.h"

tests/c/member_type_reexport-i1.h should remove these lines:
- #include "tests/c/direct.h"  // lines XX-XX

The full include-list for tests/c/member_type_reexport-i1.h:
#include "tests/c/indirect.h"  // for Indirect

***** IWYU_SUMMARY */
