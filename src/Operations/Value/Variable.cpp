#include "Operations/Value/Variable.h"

VariableExecutor::VariableExecutor(void): VariableExecutor(Scalar(0)) { }

VariableExecutor::VariableExecutor(const DataObject& value) {
    _value = value;
}

DataObject VariableExecutor::GetValue(void) const {
    return _value;
}

DataObject VariableExecutor::operator() (const ExecutionContext& context) const {
    return _value;
}

std::vector<DataObject> VariableExecutor::Differentiate(const ExecutionContext& context) const {
    return std::vector<DataObject>();
}

void VariableExecutor::Update(const IOptimizer& optimizer, const DataObject& grad) {
    _value = optimizer.AdjustNode(_value, grad);
}

Variable::Variable(void): Node({}), _executor() {
    RegisterDifferentiableExecutor(std::make_shared<VariableExecutor>(_executor));
}

Variable::Variable(float value): Variable(Scalar(value)) { }

Variable::Variable(const Eigen::MatrixXf& value): Variable(Mat(value)) { }

Variable::Variable(const DataObject& value): Node({}), _executor(value) {
    RegisterDifferentiableExecutor(std::make_shared<VariableExecutor>(_executor));
}

DataObject Variable::GetValue() {
    return _executor.GetValue();
}

void Variable::Update(const IOptimizer& optimizer, const DataObject& grad) {
    _executor.Update(optimizer, grad);
}
