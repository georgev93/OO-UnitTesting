#ifndef MyClass_mocks_h
#define MyClass_mocks_h

#include "fff/fff.h"
#include "header.h"

DECLARE_FAKE_VALUE_FUNC(int, getSum_f)  // NOLINT
DECLARE_FAKE_VALUE_FUNC(int, getDiff_f) // NOLINT

class MyPublicClass : public MyClass {
  public:
    MyPublicClass(int a, int b) : MyClass(a, b) {} // NOLINT

  using MyClass::getSum;
  using MyClass::getDiff;
};

class MyMockClass : public MyClass {
  public:
    MyMockClass(int a, int b) : MyClass(a, b) {} // NOLINT

    int getSum() const override;
    int getDiff() const override;
};

#endif // MyClass_mocks_h

