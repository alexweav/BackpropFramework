#include "Constant.h"

Constant::Constant(float value): Node({}) {
    _value = value;
}

float Constant::Forward(vector<float>* inputs) {
    return _value;
}

float Constant::getValue() {
    return _value;
}
