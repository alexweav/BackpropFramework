#ifndef MULTIPLICATION_H
#define MULTIPLICATION_H

#include "Operations/Base/Operation.h"
#include "Operations/Base/Differentiable.h"

class Multiplication: public Operation, public Differentiable {
    public:
        Multiplication(Node* i1, Node* i2);
        DataObject Forward(const std::vector<DataObject>& inputs) const;
        std::vector<DataObject> Backward(const std::vector<DataObject>& prevInputs) const;

    private:
        DataObject HandleMultiply(const DataObject&, const DataObject&) const;
        DataObject ScalarMultiply(const DataObject&, const DataObject&) const;
        DataObject MatrixMultiply(const DataObject&, const DataObject&) const;
};

#endif
