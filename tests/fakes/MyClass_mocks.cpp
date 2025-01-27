#include "MyClass_mocks.h"
#include "fff/fff.h"

DEFINE_FAKE_VALUE_FUNC(int, getSum_f)  // NOLINT
DEFINE_FAKE_VALUE_FUNC(int, getDiff_f) // NOLINT

int MyMockClass::getSum() const {
    return getSum_f();
}

int MyMockClass::getDiff() const {
    return getDiff_f();
}
