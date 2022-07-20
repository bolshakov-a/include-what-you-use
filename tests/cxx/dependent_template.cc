//===--- dependent_template.cc - test input file for iwyu -----------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// IWYU_ARGS: -I . -Xiwyu --check_also=tests/cxx/dependent_template-d1.h

// Test dependent template specialization handling.

#include "tests/cxx/dependent_template-d1.h"
#include "tests/cxx/dependent_template-d2.h"

template <typename T>
void TemplateFn() {
  // IWYU: Template is...*dependent_template-i1.h
  Template<T> t;
}

void Fn() {
  // IWYU: Template is...*dependent_template-i1.h
  TemplateFn<int>();
  // 'Template' specialization for char type is in dependent_template-i2.h
  // IWYU: Template is...*dependent_template-i2.h
  TemplateFn<char>();
}

// IWYU: NonProvided is...*dependent_template-i3.h
TemplateWithTypedefs<float>::TypeFromNonProvidedTemplate i2;
// Despite it isn't directly used here, NonProvided type info is still needed to
// fully instantiate TemplateWithTypedefs.
// IWYU: NonProvided is...*dependent_template-i3.h
TemplateWithTypedefs<float>::TypeFromProvidedTemplate i1;

// TODO(bolshakov): move into more appropriate test case.
template <typename T>
class TemplateWithFwdDeclUse {
  T* t;
};

// IWYU: Template needs a declaration
TemplateWithFwdDeclUse<Template<int>> c;

/**** IWYU_SUMMARY

tests/cxx/dependent_template.cc should add these lines:
#include "tests/cxx/dependent_template-i1.h"
#include "tests/cxx/dependent_template-i2.h"
#include "tests/cxx/dependent_template-i3.h"

tests/cxx/dependent_template.cc should remove these lines:
- #include "tests/cxx/dependent_template-d2.h"  // lines XX-XX

The full include-list for tests/cxx/dependent_template.cc:
#include "tests/cxx/dependent_template-d1.h"  // for TemplateWithTypedefs
#include "tests/cxx/dependent_template-i1.h"  // for Template
#include "tests/cxx/dependent_template-i2.h"  // for Template
#include "tests/cxx/dependent_template-i3.h"  // for NonProvided

***** IWYU_SUMMARY */
