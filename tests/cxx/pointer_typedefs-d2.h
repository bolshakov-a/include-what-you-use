//===--- pointer_typedefs-d2.h - test input file for iwyu -----------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#include "tests/cxx/pointer_typedefs-i2.h"
#include "tests/cxx/pointer_typedefs-i3.h"

struct UnusedStruct;
struct UsedStruct;

typedef UnusedStruct* UnusedStructPtr;
typedef UsedStruct* UsedStructPtr;

typedef UnusedStruct UnusedStructAlias;
typedef UsedStruct UsedStructAlias;

typedef ProvidingPtrAlias IndirectProvidingPtrAlias;
typedef NonProvidingPtrAlias IndirectNonProvidingPtrAlias;

/**** IWYU_SUMMARY

(tests/cxx/pointer_typedefs-d2.h has correct #includes/fwd-decls)

***** IWYU_SUMMARY */
