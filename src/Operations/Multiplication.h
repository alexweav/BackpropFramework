#ifndef MULTIPLICATION_H
#define MULTIPLICATION_H

#include "Operation.h"
#include "IDifferentiable.h"

class Multiplication: public Operation, public IDifferentiable {
    public:
        Multiplication(Node* i1, Node* i2);
        float Forward(vector<float>* inputs);
        vector<float>* Backward(vector<float>* prevInputs);
};

#endif
