#include "Constant.h"

Constant::Constant(float value): Node({}) {
    _value = value;
}

float Constant::Forward(const vector<float>& inputs) const {
    return _value;
}

float Constant::getValue() {
    return _value;
}
