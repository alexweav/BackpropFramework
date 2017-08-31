#include "src/Operations/Arithmetic/Subtraction.h"
#include <vector>

Subtraction::Subtraction(Node* i1, Node* i2): Node({i1, i2}, true) { }

DataObject Subtraction::Forward(const std::vector<DataObject>& inputs) const {
    DataObject result(inputs.at(0).ToScalar() - inputs.at(1).ToScalar());
    return result;
}

std::vector<DataObject> Subtraction::Backward(const std::vector<DataObject>& prevInputs, const DataObject& dout) const {
    std::vector<DataObject> grads(this->_arity);
    DataObject grad0(1.0);
    DataObject grad1(-1.0);
    grads.at(0) = grad0;
    grads.at(1) = grad1;
    return grads;
}
