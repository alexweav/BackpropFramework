#include "Input.h"

Input::Input(): Node({}, true) { }

DataObject Input::GetDefaultOutput() {
    return _defaultOutput;
}

DataObject Input::Forward(const vector<DataObject>& inputs) const {
    return _defaultOutput;
}

vector<DataObject> Input::Backward(const vector<DataObject>& prevInputs) const {
    vector<DataObject> gradsOut;
    return gradsOut;
}

void Input::RegisterNewDefaultValue(float value) {
    RegisterNewDefaultValue(Scalar(value));
}

void Input::RegisterNewDefaultValue(const MatrixXf& matrix) {
    RegisterNewDefaultValue(Mat(matrix));
}

void Input::RegisterNewDefaultValue(const DataObject& newValue) {
    _defaultOutput = newValue;
}
