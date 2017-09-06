#include "src/Operations/Arithmetic/Addition.h"
#include <vector>

Addition::Addition(NodePtr i1, NodePtr i2): Node({i1, i2}, true) { }

DataObject Addition::Forward(const std::vector<DataObject>& inputs) const {
    return inputs.at(0).Add(inputs.at(1));
}

std::vector<DataObject> Addition::Backward(const std::vector<DataObject>& prevInputs, const DataObject& dout) const {
    return HandleBackward(prevInputs.at(0), prevInputs.at(1), dout);
}

std::vector<DataObject> Addition::HandleBackward(const DataObject& i1, const DataObject& i2, const DataObject& dout) const {
    if (i1.Dim() == 0 && i2.Dim() == 0) {
        return DifferentiateScalarAddition(i1, i2, dout);
    }
    if (i1.Dim() == i2.Dim() && i1.Shape() == i2.Shape()) {
        return DifferentiateMatrixAddition(i1, i2, dout);
    }
}

std::vector<DataObject> Addition::DifferentiateScalarAddition(const DataObject& i1, const DataObject& i2, const DataObject& dout) const {
    std::vector<DataObject> grads(this->_arity);
    grads.at(0) = Scalar(1.0).ElementwiseMultiply(dout);
    grads.at(1) = Scalar(1.0).ElementwiseMultiply(dout);
    return grads;
}

std::vector<DataObject> Addition::DifferentiateMatrixAddition(const DataObject& i1, const DataObject& i2, const DataObject& dout) const {
    std::vector<DataObject> grads(this->_arity);
    Eigen::MatrixXf mat = Eigen::MatrixXf::Constant(i1.ToMatrix().rows(), i1.ToMatrix().cols(), 1.0);
    grads.at(0) = Mat(mat).ElementwiseMultiply(dout);
    grads.at(1) = Mat(mat).ElementwiseMultiply(dout);
    return grads;
}

std::shared_ptr<Addition> Add(NodePtr i1, NodePtr i2) {
    std::shared_ptr<Addition> ptr(new Addition(i1, i2));
    return ptr;
}
