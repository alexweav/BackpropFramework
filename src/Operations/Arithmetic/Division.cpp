#include "src/Operations/Arithmetic/Division.h"
#include <vector>

Division::Division(Node* i1, Node* i2) : Node({i1, i2}, true) { }

DataObject Division::Forward(const std::vector<DataObject>& inputs) const {
    DataObject result(inputs.at(0).ToScalar() / inputs.at(1).ToScalar());
    return result;
}

std::vector<DataObject> Division::Backward(const std::vector<DataObject>& prevInputs) const {
    std::vector<DataObject> grads(this->_arity);
    DataObject grad0(1.0 / prevInputs.at(1).ToScalar());
    DataObject grad1(prevInputs.at(0).ToScalar() * -(1.0 / (prevInputs.at(1).ToScalar() * prevInputs.at(1).ToScalar())));
    grads.at(0) = grad0;
    grads.at(1) = grad1;
    return grads;
}
