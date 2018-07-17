#include "Operations/Value/Input.h"

InputExecutor::InputExecutor(void) { }

InputExecutor::InputExecutor(const DataObject& defaultOutput) {
    _defaultOutput = defaultOutput;
}

DataObject InputExecutor::operator() (const ExecutionContext& context) const {
    return _defaultOutput;
}

std::vector<DataObject> InputExecutor::Differentiate(const ExecutionContext& context) const {
    return std::vector<DataObject>();
}

void InputExecutor::RegisterNewDefaultValue(const DataObject& newValue) {
    _defaultOutput = newValue;
}

DataObject InputExecutor::GetDefaultOutput(void) {
    return _defaultOutput;
}

Input::Input(void): Node({}), _executor(new InputExecutor()) {
    AttachDifferentiableExecutor(_executor);
}

Input::Input(const DataObject& defaultOutput): Node({}), _executor(new InputExecutor(defaultOutput)) {
    AttachDifferentiableExecutor(_executor);
}

DataObject Input::GetDefaultOutput(void) {
    return _executor->GetDefaultOutput();
}

void Input::RegisterNewDefaultValue(float value) {
    RegisterNewDefaultValue(Scalar(value));
}

void Input::RegisterNewDefaultValue(const Eigen::MatrixXf& matrix) {
    RegisterNewDefaultValue(Mat(matrix));
}

void Input::RegisterNewDefaultValue(const DataObject& newValue) {
    return _executor->RegisterNewDefaultValue(newValue);
}

std::shared_ptr<Input> Var(void) {
    return std::shared_ptr<Input>(new Input());
}
