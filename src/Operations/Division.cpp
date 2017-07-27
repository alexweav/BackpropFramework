#include "Division.h"

Division::Division(Node* i1, Node* i2): Operation({i1, i2}) { }

float Division::Forward(vector<float>* inputs) {
    return inputs->at(0) / inputs->at(1);
}

vector<float>* Division::Backward(vector<float>* prevInputs) {
    vector<float>* grads = new vector<float>(this->_arity);
    grads->at(0) = 1.0 / prevInputs->at(1);
    grads->at(1) = prevInputs->at(0) * -(1.0 / (prevInputs->at(1) * prevInputs->at(1)));
    return grads;
}
