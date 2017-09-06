#include "src/Operations/Arithmetic/Subtraction.h"
#include <vector>

Subtraction::Subtraction(NodePtr i1, NodePtr i2): Node({i1, i2}, true) { }

DataObject Subtraction::Forward(const std::vector<DataObject>& inputs) const {
    DataObject result(inputs.at(0).ToScalar() - inputs.at(1).ToScalar());
    return result;
}

std::vector<DataObject> Subtraction::Backward(const std::vector<DataObject>& prevInputs, const DataObject& dout) const {
    std::vector<DataObject> grads(this->_arity);
    grads.at(0) = Scalar(1.0).ElementwiseMultiply(dout);
    grads.at(1) = Scalar(-1.0).ElementwiseMultiply(dout);
    return grads;
}

std::shared_ptr<Subtraction> Subtract(NodePtr i1, NodePtr i2) {
    std::shared_ptr<Subtraction> ptr(new Subtraction(i1, i2));
    return ptr;
}
