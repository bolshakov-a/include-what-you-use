//===--- typedef_chain_in_template-i1.h - test input file for iwyu --------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// This header mimics ext/alloc_traits.h in libstdc++.

#ifndef TYPEDEF_CHAIN_IN_TEMPLATE_I1_H_
#define TYPEDEF_CHAIN_IN_TEMPLATE_I1_H_

template<typename T>
struct TypedefWrapper {
  typedef T value_type;
  typedef value_type& reference;
};

#endif  // TYPEDEF_CHAIN_IN_TEMPLATE_I1_H_
