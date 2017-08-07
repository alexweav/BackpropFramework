#ifndef SUBTRACTION_H
#define SUBTRACTION_H

#include "Operation.h"
#include "Differentiable.h"

class Subtraction: public Operation, public Differentiable {
    public:
        Subtraction(Node* i1, Node* i2);
        float Forward(const vector<float>& inputs) const;
        vector<float> Backward(const vector<float>& prevInputs) const;
};

#endif
