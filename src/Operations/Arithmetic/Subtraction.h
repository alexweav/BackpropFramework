#ifndef SUBTRACTION_H
#define SUBTRACTION_H

#include "Operations/Base/Operation.h"
#include "Operations/Base/Differentiable.h"

class Subtraction: public Operation, public Differentiable {
    public:
        Subtraction(Node* i1, Node* i2);
        DataObject Forward(const std::vector<DataObject>& inputs) const;
        std::vector<DataObject> Backward(const std::vector<DataObject>& prevInputs) const;
};

#endif
