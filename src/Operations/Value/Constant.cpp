#include "Operations/Value/Constant.h"

ConstantExecutor::ConstantExecutor(const DataObject& value) {
    _value = value;
}

DataObject ConstantExecutor::operator() (const ExecutionContext& context) const {
    return _value;
}

std::vector<DataObject> ConstantExecutor::Differentiate(const ExecutionContext& context) const {
    return std::vector<DataObject>();
}

DataObject ConstantExecutor::GetValue(void) const {
    return _value;
}

Constant::Constant(const float value): Constant(Scalar(value)) { }

Constant::Constant(const Eigen::MatrixXf& value): Constant(Mat(value)) { }

Constant::Constant(const DataObject& value): Node({}), _executor(value) {
    RegisterDifferentiableExecutor(std::make_shared<ConstantExecutor>(_executor));
}

DataObject Constant::GetValue(void) const {
    return _executor.GetValue();
}

std::shared_ptr<Constant> Value(float value) {
    std::shared_ptr<Constant> ptr(new Constant(value));
    return ptr;
}

std::shared_ptr<Constant> Value(const Eigen::MatrixXf& value) {
    std::shared_ptr<Constant> ptr(new Constant(value));
    return ptr;
}

std::shared_ptr<Constant> Value(const DataObject& value) {
    std::shared_ptr<Constant> ptr(new Constant(value));
    return ptr;
}
