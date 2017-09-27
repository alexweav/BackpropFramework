#include "Variable.h"

Variable::Variable(): Variable(Scalar(0)) { }

Variable::Variable(float value): Variable(Scalar(value)) { }

Variable::Variable(const Eigen::MatrixXf& value): Variable(Mat(value)) { }

Variable::Variable(const DataObject& value): Node({}, true) {
    _value = value;
}

DataObject Variable::GetValue() {
    return _value;
}

DataObject Variable::Forward(const std::vector<DataObject>& inputs) const {
    return _value;
}

std::vector<DataObject> Variable::Backward(const std::vector<DataObject>& prevInputs, const DataObject& dout) const {
    std::vector<DataObject> gradsOut;
    return gradsOut;
}

void Variable::Update(const IOptimizer& optimizer, const DataObject& grad) {
    _value = optimizer.AdjustNode(_value, grad);
}
