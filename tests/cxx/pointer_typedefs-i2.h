//===--- pointer_typedefs-i2.h - test input file for iwyu -----------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#include "tests/cxx/pointer_typedefs-i1.h"

typedef UsedStruct* ProvidingPtrAlias;
