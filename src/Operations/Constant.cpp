#include "Constant.h"

Constant::Constant(float value): Node({}, true) {
    _value = value;
}

float Constant::Forward(const vector<float>& inputs) const {
    return _value;
}

vector<float> Constant::Backward(const vector<float>& prevInputs) const {
    vector<float> gradsOut;
    return gradsOut;
}

float Constant::getValue() {
    return _value;
}
