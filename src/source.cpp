#include "header.h"

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

