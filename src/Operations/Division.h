#ifndef DIVISION_H
#define DIVISION_H

#include "Operation.h"
#include "Differentiable.h"

class Division: public Operation, public Differentiable {
    public:
        Division(Node* i1, Node* i2);
        float Forward(const vector<float>& inputs) const;
        vector<float> Backward(const vector<float>& prevInputs) const;
};

#endif
