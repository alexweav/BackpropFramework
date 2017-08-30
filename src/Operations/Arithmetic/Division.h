#ifndef DIVISION_H
#define DIVISION_H

#include "Operations/Base/Operation.h"
#include "Operations/Base/Differentiable.h"

class Division: public Operation, public Differentiable {
    public:
        Division(Node* i1, Node* i2);
        DataObject Forward(const vector<DataObject>& inputs) const;
        vector<DataObject> Backward(const vector<DataObject>& prevInputs) const;
};

#endif
