#include "header.h"

int MyClass::doComplexOp() const {
    int sum = _a + _b; 
    int diff = 0;
    if (_b > _a) {
        diff = _b - _a;
    } else {
        diff = _a - _b;
    }
    return (diff * sum);
}

