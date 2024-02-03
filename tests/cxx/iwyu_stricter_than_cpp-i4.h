//===--- iwyu_stricter_than_cpp-i4.h - test input file for iwyu -----------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#ifndef IWYU_STRICTER_THAN_CPP_I4_H_
#define IWYU_STRICTER_THAN_CPP_I4_H_

class IndirectClass;

struct IndirectStruct4 {
  typedef IndirectClass IndirectClassNonProvidingTypedef;

  using IndirectClassNonProvidingAl = IndirectClass;
};

#endif  // IWYU_STRICTER_THAN_CPP_I4_H_
