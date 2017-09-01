#include "src/Operations/Arithmetic/Division.h"
#include <vector>

Division::Division(Node* i1, Node* i2) : Node({i1, i2}, true) { }

DataObject Division::Forward(const std::vector<DataObject>& inputs) const {
    DataObject result(inputs.at(0).ToScalar() / inputs.at(1).ToScalar());
    return result;
}

std::vector<DataObject> Division::Backward(const std::vector<DataObject>& prevInputs, const DataObject& dout) const {
    std::vector<DataObject> grads(this->_arity);
    grads.at(0) = Scalar(dout.ToScalar() / prevInputs.at(1).ToScalar());
    grads.at(1) = Scalar(prevInputs.at(0).ToScalar() * -(dout.ToScalar() / (prevInputs.at(1).ToScalar() * prevInputs.at(1).ToScalar())));
    return grads;
}

Division* Divide(Node* i1, Node* i2) {
    return new Division(i1, i2);
}
