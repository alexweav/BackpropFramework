#include "src/Operations/Base/Input.h"
#include <vector>

Input::Input(): Node({}, true) { }

DataObject Input::GetDefaultOutput() {
    return _defaultOutput;
}

DataObject Input::Forward(const std::vector<DataObject>& inputs) const {
    return _defaultOutput;
}

std::vector<DataObject> Input::Backward(const std::vector<DataObject>& prevInputs) const {
    std::vector<DataObject> gradsOut;
    return gradsOut;
}

void Input::RegisterNewDefaultValue(float value) {
    RegisterNewDefaultValue(Scalar(value));
}

void Input::RegisterNewDefaultValue(const Eigen::MatrixXf& matrix) {
    RegisterNewDefaultValue(Mat(matrix));
}

void Input::RegisterNewDefaultValue(const DataObject& newValue) {
    _defaultOutput = newValue;
}

Input* Var(void) {
    return new Input();
}
