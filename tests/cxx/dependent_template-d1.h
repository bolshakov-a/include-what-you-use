//===--- dependent_template-d1.h - test input file for iwyu ---------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#include "tests/cxx/dependent_template-i1.h"
#include "tests/cxx/dependent_template-i2.h"
#include "tests/cxx/dependent_template-i4.h"

template <typename>
struct NonProvided;

template <typename T>
struct TemplateWithTypedefs {
  typedef typename Provided<T>::Type TypeFromProvidedTemplate;
  typedef typename NonProvided<T>::Type TypeFromNonProvidedTemplate;
};

/**** IWYU_SUMMARY

tests/cxx/dependent_template-d1.h should add these lines:

tests/cxx/dependent_template-d1.h should remove these lines:
- #include "tests/cxx/dependent_template-i2.h"  // lines XX-XX
- #include "tests/cxx/dependent_template-i4.h"  // lines XX-XX

The full include-list for tests/cxx/dependent_template-d1.h:
#include "tests/cxx/dependent_template-i1.h"  // for Provided
template <typename> struct NonProvided;  // lines XX-XX+1

***** IWYU_SUMMARY */
