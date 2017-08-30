#include "Subtraction.h"

Subtraction::Subtraction(Node* i1, Node* i2): Node({i1, i2}, true) { }

DataObject Subtraction::Forward(const vector<DataObject>& inputs) const {
    DataObject result(inputs.at(0).GetData<float>() - inputs.at(1).GetData<float>());
    return result;
}

vector<DataObject> Subtraction::Backward(const vector<DataObject>& prevInputs) const {
    vector<DataObject> grads(this->_arity);
    DataObject grad0(1.0);
    DataObject grad1(-1.0);
    grads.at(0) = grad0;
    grads.at(1) = grad1;
    return grads;
}
