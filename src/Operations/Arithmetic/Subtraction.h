#ifndef SRC_OPERATIONS_ARITHMETIC_SUBTRACTION_H_
#define SRC_OPERATIONS_ARITHMETIC_SUBTRACTION_H_

#include <vector>
#include "Operations/Base/Operation.h"
#include "Operations/Base/Differentiable.h"

class Subtraction: public Operation, public Differentiable {
 public:
    Subtraction(NodePtr i1, NodePtr i2);
    DataObject Forward(const std::vector<DataObject>& inputs) const;
    std::vector<DataObject> Backward(const std::vector<DataObject>& prevInputs, const DataObject& dout) const;
};

std::shared_ptr<Subtraction> Subtract(NodePtr, NodePtr);

#endif  // SRC_OPERATIONS_ARITHMETIC_SUBTRACTION_H_
