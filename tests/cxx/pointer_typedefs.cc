//===--- pointer_typedefs.cc - test input file for iwyu -------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// IWYU_ARGS: -I . -Wno-unused-value                                \
//            -Xiwyu --check_also="tests/cxx/pointer_typedefs-d2.h" \
//            -Xiwyu --check_also="tests/cxx/pointer_typedefs-i3.h"

// Tests that using of typedef of pointer type may or may not constitute
// underlying type usage

#include "tests/cxx/pointer_typedefs-d1.h"
#include "tests/cxx/pointer_typedefs-d2.h"
#include "tests/cxx/pointer_typedefs-d3.h"

void fn() {
  UnusedStructPtr unused_struct_ptr;

  UsedStructPtr used_struct_ptr;
  // IWYU: UsedStruct is...*pointer_typedefs-i1.h
  used_struct_ptr->i;

  UnusedStructAlias* unused_struct_alias_ptr;

  UsedStructAlias* used_struct_alias_ptr;
  // IWYU: UsedStruct is...*pointer_typedefs-i1.h
  used_struct_alias_ptr->i;

  IndirectProvidingPtrAlias indirect_providing_ptr;
  // pointer_typedefs-i2.h provides UsedStruct through '#include',
  // hence no reporting here
  indirect_providing_ptr->i;

  IndirectNonProvidingPtrAlias indirect_non_providing_ptr;
  // IWYU: UsedStruct is...*pointer_typedefs-i1.h
  indirect_non_providing_ptr->i;
}

/**** IWYU_SUMMARY

tests/cxx/pointer_typedefs.cc should add these lines:
#include "tests/cxx/pointer_typedefs-i1.h"

tests/cxx/pointer_typedefs.cc should remove these lines:
- #include "tests/cxx/pointer_typedefs-d1.h"  // lines XX-XX
- #include "tests/cxx/pointer_typedefs-d3.h"  // lines XX-XX

The full include-list for tests/cxx/pointer_typedefs.cc:
#include "tests/cxx/pointer_typedefs-d2.h"  // for IndirectNonProvidingPtrAlias, IndirectProvidingPtrAlias, UnusedStructAlias, UnusedStructPtr, UsedStructAlias, UsedStructPtr
#include "tests/cxx/pointer_typedefs-i1.h"  // for UsedStruct

***** IWYU_SUMMARY */
