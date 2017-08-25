#ifndef SUBTRACTION_H
#define SUBTRACTION_H

#include "Operation.h"
#include "Differentiable.h"

class Subtraction: public Operation, public Differentiable {
    public:
        Subtraction(Node* i1, Node* i2);
        DataObject Forward(const vector<DataObject>& inputs) const;
        vector<DataObject> Backward(const vector<DataObject>& prevInputs) const;
};

#endif
