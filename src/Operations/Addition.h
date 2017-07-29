#ifndef ADDITION_H
#define ADDITION_H

#include "Operation.h"
#include "IDifferentiable.h"

class Addition: public Operation, public IDifferentiable {
    public:
        Addition(Node* input1, Node* input2);
        float Forward(const vector<float>& inputs) const;
        vector<float>* Backward(vector<float>* prevInputs);
};

#endif
