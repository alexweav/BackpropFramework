#ifndef SRC_OPERATIONS_ARITHMETIC_MULTIPLICATION_H_
#define SRC_OPERATIONS_ARITHMETIC_MULTIPLICATION_H_

#include <vector>
#include "Operations/Base/Operation.h"
#include "Operations/Base/Differentiable.h"

class Multiplication: public Operation, public Differentiable {
 public:
    Multiplication(Node* i1, Node* i2);
    DataObject Forward(const std::vector<DataObject>& inputs) const;
    std::vector<DataObject> Backward(const std::vector<DataObject>& prevInputs, const DataObject& dout) const;

 private:
    DataObject HandleMultiply(const DataObject&, const DataObject&) const;
    DataObject ScalarMultiply(const DataObject&, const DataObject&) const;
    DataObject MatrixMultiply(const DataObject&, const DataObject&) const;
    std::vector<DataObject> HandleBackward(const DataObject&, const DataObject&, const DataObject&) const;
    std::vector<DataObject> DifferentiateScalarMultiplication(const DataObject&, const DataObject&, const DataObject&) const;
    std::vector<DataObject> DifferentiateMatrixMultiplication(const DataObject&, const DataObject&, const DataObject&) const;
};

#endif  // SRC_OPERATIONS_ARITHMETIC_MULTIPLICATION_H_
