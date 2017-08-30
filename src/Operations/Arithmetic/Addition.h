#ifndef ADDITION_H
#define ADDITION_H

#include "Operations/Base/Operation.h"
#include "Operations/Base/Differentiable.h"

class Addition: public Operation, public Differentiable {
    public:
        Addition(Node* input1, Node* input2);
        DataObject Forward(const vector<DataObject>& inputs) const;
        vector<DataObject> Backward(const vector<DataObject>& prevInputs) const;

    private:
        vector<DataObject> HandleBackward(const DataObject&, const DataObject&) const;
        vector<DataObject> DifferentiateScalarAddition(const DataObject&, const DataObject&) const;
        vector<DataObject> DifferentiateMatrixAddition(const DataObject&, const DataObject&) const;
};

#endif
