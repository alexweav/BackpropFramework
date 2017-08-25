#include "Constant.h"

Constant::Constant(float value): Node({}, true) {
    _value = value;
}

DataObject Constant::Forward(const vector<DataObject>& inputs) const {
    DataObject result(_value);
    return result;
}

vector<DataObject> Constant::Backward(const vector<DataObject>& prevInputs) const {
    vector<DataObject> gradsOut;
    return gradsOut;
}

float Constant::getValue() {
    return _value;
}
