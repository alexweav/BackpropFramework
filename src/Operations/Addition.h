#ifndef ADDITION_H
#define ADDITION_H

#include "Operation.h"
#include "IDifferentiable.h"

class Addition: public Operation, public IDifferentiable {
    public:
        Addition(Node* input1, Node* input2);
        float Forward(vector<float>* inputs);
        vector<float>* Backward(float grad, vector<float>* prevInputs);
};

#endif
