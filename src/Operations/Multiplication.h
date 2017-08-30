#ifndef MULTIPLICATION_H
#define MULTIPLICATION_H

#include "Operation.h"
#include "Differentiable.h"

class Multiplication: public Operation, public Differentiable {
    public:
        Multiplication(Node* i1, Node* i2);
        DataObject Forward(const vector<DataObject>& inputs) const;
        vector<DataObject> Backward(const vector<DataObject>& prevInputs) const;

    private:
        DataObject HandleMultiply(const DataObject&, const DataObject&) const;
        DataObject ScalarMultiply(const DataObject&, const DataObject&) const;
        DataObject MatrixMultiply(const DataObject&, const DataObject&) const;
};

#endif
