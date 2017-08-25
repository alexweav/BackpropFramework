#include "Input.h"

Input::Input(): Node({}, true) { }

float Input::GetDefaultOutput() {
    return _defaultOutput;
}

DataObject Input::Forward(const vector<DataObject>& inputs) const {
    DataObject result(_defaultOutput);
    return result;
}

vector<DataObject> Input::Backward(const vector<DataObject>& prevInputs) const {
    vector<DataObject> gradsOut;
    return gradsOut;
}

void Input::RegisterNewDefaultValue(float newValue) {
    _defaultOutput = newValue;
}
