#ifndef SUBTRACTION_H
#define SUBTRACTION_H

#include "Operations/Base/Operation.h"
#include "Operations/Base/Differentiable.h"

class Subtraction: public Operation, public Differentiable {
    public:
        Subtraction(Node* i1, Node* i2);
        DataObject Forward(const vector<DataObject>& inputs) const;
        vector<DataObject> Backward(const vector<DataObject>& prevInputs) const;
};

#endif
