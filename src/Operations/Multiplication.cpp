#include "Multiplication.h"

Multiplication::Multiplication(Node* i1, Node* i2): Operation(2) {
    _predecessors->at(0) = i1;
    i1->RegisterSuccessor(this);
    _predecessors->at(1) = i2;
    i2->RegisterSuccessor(this);
}

float Multiplication::Forward(vector<float>* inputs) {
    return inputs->at(0) * inputs->at(1);
}

vector<float>* Multiplication::Backward(vector<float>* prevInputs) {
    vector<float>* grads = new vector<float>(this->_arity);
    grads->at(0) = prevInputs->at(1);
    grads->at(1) = prevInputs->at(0);
    return grads;
}
