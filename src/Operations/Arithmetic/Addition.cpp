#include "src/Operations/Arithmetic/Addition.h"
#include <vector>

DataObject AdditionExecutor::operator()(const std::vector<DataObject>& inputs) const {
    return inputs.at(0).Add(inputs.at(1));
}

std::vector<DataObject> AdditionExecutor::Differentiate(const std::vector<DataObject>& prevInputs, const DataObject& dOut) const {
    return HandleBackward(prevInputs.at(0), prevInputs.at(1), dOut);
}

std::vector<DataObject> AdditionExecutor::HandleBackward(const DataObject& i1, const DataObject& i2, const DataObject& dout) const {
    if (i1.Dim() == 0 && i2.Dim() == 0) {
        return DifferentiateScalarAddition(i1, i2, dout);
    }
    if (i1.Dim() == i2.Dim() && i1.Shape() == i2.Shape()) {
        return DifferentiateMatrixAddition(i1, i2, dout);
    }
}

std::vector<DataObject> AdditionExecutor::DifferentiateScalarAddition(const DataObject& i1, const DataObject& i2, const DataObject& dout) const {
    std::vector<DataObject> grads(2);
    grads.at(0) = Scalar(1.0).ElementwiseMultiply(dout);
    grads.at(1) = Scalar(1.0).ElementwiseMultiply(dout);
    return grads;
}

std::vector<DataObject> AdditionExecutor::DifferentiateMatrixAddition(const DataObject& i1, const DataObject& i2, const DataObject& dout) const {
    std::vector<DataObject> grads(2);
    Eigen::MatrixXf mat = Eigen::MatrixXf::Constant(i1.ToMatrix().rows(), i1.ToMatrix().cols(), 1.0);
    grads.at(0) = Mat(mat).ElementwiseMultiply(dout);
    grads.at(1) = Mat(mat).ElementwiseMultiply(dout);
    return grads;
}

Addition::Addition(const NodePtr& i1, const NodePtr& i2): Node({i1, i2}, true) { }

DataObject Addition::Forward(const std::vector<DataObject>& inputs) const {
    return _executor(inputs);
}

std::vector<DataObject> Addition::Backward(const std::vector<DataObject>& prevInputs, const DataObject& dout) const {
    return _executor.Differentiate(prevInputs, dout);
}

std::shared_ptr<Addition> Add(const NodePtr& i1, const NodePtr& i2) {
    std::shared_ptr<Addition> ptr(new Addition(i1, i2));
    return ptr;
}

std::shared_ptr<Addition> operator+(const NodePtr& i1, const NodePtr& i2) {
    return Add(i1, i2);
}
