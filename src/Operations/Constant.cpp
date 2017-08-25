#include "Constant.h"

Constant::Constant(const DataObject& value): Node({}, true) {
    _value = value;
}

DataObject Constant::Forward(const vector<DataObject>& inputs) const {
    return _value;
}

vector<DataObject> Constant::Backward(const vector<DataObject>& prevInputs) const {
    vector<DataObject> gradsOut;
    return gradsOut;
}

DataObject Constant::getValue() {
    return _value;
}
