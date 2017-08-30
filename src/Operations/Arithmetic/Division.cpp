#include "Division.h"

Division::Division(Node* i1, Node* i2) : Node({i1, i2}, true) { }

DataObject Division::Forward(const vector<DataObject>& inputs) const {
    DataObject result(inputs.at(0).GetData<float>() / inputs.at(1).GetData<float>());
    return result;
}

vector<DataObject> Division::Backward(const vector<DataObject>& prevInputs) const {
    vector<DataObject> grads(this->_arity);
    DataObject grad0(1.0 / prevInputs.at(1).GetData<float>());
    DataObject grad1(prevInputs.at(0).GetData<float>() * -(1.0 / (prevInputs.at(1).GetData<float>() * prevInputs.at(1).GetData<float>())));
    grads.at(0) = grad0;
    grads.at(1) = grad1;
    return grads;
}