//===--- member_type_reexport.c - test input file for iwyu ----------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// IWYU_ARGS: -I . -Xiwyu --check_also=tests/c/*-i1.h

// Tests that types of structure or union members can be considered as provided
// in C (because C has no references or static members, in contrast to C++) and
// need not to be reported where those fields are used.

#include "tests/c/member_type_reexport-d1.h"

void Test() {
  extern struct Struct s;
  extern struct Struct* ps;
  extern union Union u;
  extern union Union* pu;

  // IWYU: Struct is...*-i1.h
  s.i.a = 1;
  // IWYU: Struct is...*-i1.h
  (void)sizeof(s.i);
  // IWYU: Union is...*-i1.h
  u.i.a = 1;
  // IWYU: Union is...*-i1.h
  (void)sizeof(u.i);

  // IWYU: Struct is...*-i1.h
  ps->i.a = 1;
  // IWYU: Struct is...*-i1.h
  (void)sizeof(ps->i);
  // IWYU: Union is...*-i1.h
  pu->i.a = 1;
  // IWYU: Union is...*-i1.h
  (void)sizeof(pu->i);

  // Pointer members still need the #include for Indirect.
  // IWYU: Indirect is...*indirect.h
  // IWYU: Struct is...*-i1.h
  s.pi->a = 1;
  // IWYU: Indirect is...*indirect.h
  // IWYU: Struct is...*-i1.h
  (void)sizeof(*s.pi);
  // IWYU: Union is...*-i1.h
  // IWYU: Indirect is...*indirect.h
  u.pi->a = 1;
  // IWYU: Indirect is...*indirect.h
  // IWYU: Union is...*-i1.h
  (void)sizeof(*u.pi);
}

/**** IWYU_SUMMARY

tests/c/member_type_reexport.c should add these lines:
#include "tests/c/indirect.h"
#include "tests/c/member_type_reexport-i1.h"

tests/c/member_type_reexport.c should remove these lines:
- #include "tests/c/member_type_reexport-d1.h"  // lines XX-XX

The full include-list for tests/c/member_type_reexport.c:
#include "tests/c/indirect.h"  // for Indirect
#include "tests/c/member_type_reexport-i1.h"  // for Struct, Union

***** IWYU_SUMMARY */
