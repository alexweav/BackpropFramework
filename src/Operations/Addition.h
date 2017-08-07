#ifndef ADDITION_H
#define ADDITION_H

#include "Operation.h"
#include "Differentiable.h"

class Addition: public Operation, public Differentiable {
    public:
        Addition(Node* input1, Node* input2);
        float Forward(const vector<float>& inputs) const;
        vector<float> Backward(const vector<float>& prevInputs) const;
};

#endif
