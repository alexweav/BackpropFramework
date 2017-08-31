#ifndef ADDITION_H
#define ADDITION_H

#include "Operations/Base/Operation.h"
#include "Operations/Base/Differentiable.h"

class Addition: public Operation, public Differentiable {
    public:
        Addition(Node* input1, Node* input2);
        DataObject Forward(const std::vector<DataObject>& inputs) const;
        std::vector<DataObject> Backward(const std::vector<DataObject>& prevInputs) const;

    private:
        std::vector<DataObject> HandleBackward(const DataObject&, const DataObject&) const;
        std::vector<DataObject> DifferentiateScalarAddition(const DataObject&, const DataObject&) const;
        std::vector<DataObject> DifferentiateMatrixAddition(const DataObject&, const DataObject&) const;
};

#endif
