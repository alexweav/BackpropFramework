#ifndef SUBTRACTION_H
#define SUBTRACTION_H

#include "Operation.h"
#include "IDifferentiable.h"

class Subtraction: public Operation, public IDifferentiable {
    public:
        Subtraction(Node* i1, Node* i2);
        float Forward(const vector<float>& inputs) const;
        vector<float>* Backward(vector<float>* prevInputs);
};

#endif
