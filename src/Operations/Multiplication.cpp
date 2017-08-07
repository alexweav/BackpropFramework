#include "Multiplication.h"

Multiplication::Multiplication(Node* i1, Node* i2): Node({i1, i2}, true) { }

float Multiplication::Forward(const vector<float>& inputs) const {
    return inputs.at(0) * inputs.at(1);
}

vector<float> Multiplication::Backward(const vector<float>& prevInputs) const {
    vector<float> grads(this->_arity);
    grads.at(0) = prevInputs.at(1);
    grads.at(1) = prevInputs.at(0);
    return grads;
}
