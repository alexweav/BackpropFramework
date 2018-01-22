#include "src/Operations/Base/Input.h"
#include <vector>
#include <memory>

InputExecutor::InputExecutor(void) { }

InputExecutor::InputExecutor(const DataObject& defaultOutput) {
    _defaultOutput = defaultOutput;
}

DataObject InputExecutor::operator() (const std::vector<DataObject>& inputs) const {
    return _defaultOutput;
}

std::vector<DataObject> InputExecutor::Differentiate(const std::vector<DataObject>& prevInputs, const DataObject& dOut) const {
    std::vector<DataObject> gradsOut;
    return gradsOut;
}

void InputExecutor::RegisterNewDefaultValue(const DataObject& newValue) {
    _defaultOutput = newValue;
}

DataObject InputExecutor::GetDefaultOutput(void) {
    return _defaultOutput;
}

Input::Input(void): Node({}, true), _executor() { 
    RegisterDifferentiableExecutor(std::make_shared<InputExecutor>(_executor));
}

Input::Input(const DataObject& defaultOutput): Node({}, true), _executor(defaultOutput) { 
    RegisterDifferentiableExecutor(std::make_shared<InputExecutor>(_executor));
}

DataObject Input::GetDefaultOutput(void) {
    return _executor.GetDefaultOutput();
}

DataObject Input::Forward(const std::vector<DataObject>& inputs) const {
    return _executor(inputs);
}

std::vector<DataObject> Input::Backward(const std::vector<DataObject>& prevInputs, const DataObject& dout) const {
    return _executor.Differentiate(prevInputs, dout);
}

void Input::RegisterNewDefaultValue(float value) {
    RegisterNewDefaultValue(Scalar(value));
}

void Input::RegisterNewDefaultValue(const Eigen::MatrixXf& matrix) {
    RegisterNewDefaultValue(Mat(matrix));
}

void Input::RegisterNewDefaultValue(const DataObject& newValue) {
    return _executor.RegisterNewDefaultValue(newValue);
}

std::shared_ptr<Input> Var(void) {
    return std::shared_ptr<Input>(new Input());
}
