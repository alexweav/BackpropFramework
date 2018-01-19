#include "Variable.h"

VariableExecutor::VariableExecutor(void): VariableExecutor(Scalar(0)) { }

VariableExecutor::VariableExecutor(const DataObject& value) {
    _value = value;
}

DataObject VariableExecutor::GetValue(void) const {
    return _value;
}

DataObject VariableExecutor::operator() (const std::vector<DataObject>& inputs) const {
    return _value;
}

std::vector<DataObject> VariableExecutor::Differentiate(const std::vector<DataObject>& prevInputs, const DataObject& dOut) const {
    std::vector<DataObject> gradsOut;
    return gradsOut;
}

void VariableExecutor::Update(const IOptimizer& optimizer, const DataObject& grad) {
    _value = optimizer.AdjustNode(_value, grad);
}

Variable::Variable(void): _executor() { }

Variable::Variable(float value): Variable(Scalar(value)) { }

Variable::Variable(const Eigen::MatrixXf& value): Variable(Mat(value)) { }

Variable::Variable(const DataObject& value): Node({}, true), _executor(value) { }

DataObject Variable::GetValue() {
    return _executor.GetValue();
}

DataObject Variable::Forward(const std::vector<DataObject>& inputs) const {
    return _executor(inputs);
}

std::vector<DataObject> Variable::Backward(const std::vector<DataObject>& prevInputs, const DataObject& dout) const {
    return _executor.Differentiate(prevInputs, dout);
}

void Variable::Update(const IOptimizer& optimizer, const DataObject& grad) {
    _executor.Update(optimizer, grad);
}
