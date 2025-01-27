#include "header.h"

MyClass* MyClassFactory::create(int a, int b, const ArithOps* ops) {
    const MyClassParams myParams = {a, b, ops};
    auto* retVal = new MyClass(myParams);
    return retVal;
}

int MyClass::doComplexOp() const {
    return (this->_ops->getDiff(_a, _b) * this->_ops->getSum(_a, _b));
}

int ArithOps::getSum(int a, int b) const {
    return (a + b);
}

int ArithOps::getDiff(int a, int b) const {
    if (b > a) {
        return b - a;
    }

    return a - b;
}

