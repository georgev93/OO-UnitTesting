#include "header.h"

int MyClass::doComplexOp() const {
    return (this->getDiff() * this->getSum());
}

int MyClass::getSum() const {
  return (_a + _b);
}

int MyClass::getDiff() const {
  if(_b > _a) {
    return _b - _a;
  }

  return _a - _b;
}

