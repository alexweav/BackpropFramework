#ifndef MULTIPLICATION_H
#define MULTIPLICATION_H

#include "Operation.h"
#include "IDifferentiable.h"

class Multiplication: public Operation, public IDifferentiable {
    public:
        Multiplication(Node* i1, Node* i2);
        float Forward(const vector<float>& inputs) const;
        vector<float> Backward(const vector<float>& prevInputs) const;
};

#endif
