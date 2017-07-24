#include "Subtraction.h"

Subtraction::Subtraction(Node* i1, Node* i2): Operation(2) {
    _predecessors->at(0) = i1;
    _predecessors->at(1) = i2;
}

float Subtraction::Forward(vector<float>* inputs) {
    return inputs->at(0) - inputs->at(1);
}

vector<float>* Subtraction::Backward(vector<float>* prevInputs) {
    vector<float>* grads = new vector<float>(this->_arity);
    grads->at(0) = 1.0;
    grads->at(1) = -1.0;
    return grads;
}
