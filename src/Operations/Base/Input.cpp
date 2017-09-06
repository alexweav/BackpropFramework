#include "src/Operations/Base/Input.h"
#include <vector>
#include <memory>

Input::Input(): Node({}, true) { }

DataObject Input::GetDefaultOutput() {
    return _defaultOutput;
}

DataObject Input::Forward(const std::vector<DataObject>& inputs) const {
    return _defaultOutput;
}

std::vector<DataObject> Input::Backward(const std::vector<DataObject>& prevInputs, const DataObject& dout) const {
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

std::shared_ptr<Input> Var(void) {
    return std::shared_ptr<Input>(new Input());
}
