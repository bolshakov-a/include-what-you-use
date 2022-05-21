//===--- pointer_typedefs-i3.h - test input file for iwyu -----------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

struct UsedStruct;

typedef UsedStruct* NonProvidingPtrAlias;

/**** IWYU_SUMMARY

(tests/cxx/pointer_typedefs-i3.h has correct #includes/fwd-decls)

***** IWYU_SUMMARY */
