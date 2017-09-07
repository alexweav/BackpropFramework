#ifndef SRC_OPERATIONS_ARITHMETIC_DIVISION_H_
#define SRC_OPERATIONS_ARITHMETIC_DIVISION_H_

#include <vector>
#include "Operations/Base/Operation.h"
#include "Operations/Base/Differentiable.h"

class Division: public Operation, public Differentiable {
 public:
    Division(NodePtr i1, NodePtr i2);
    DataObject Forward(const std::vector<DataObject>& inputs) const;
    std::vector<DataObject> Backward(const std::vector<DataObject>& prevInputs, const DataObject& dout) const;
};

std::shared_ptr<Division> Divide(NodePtr, NodePtr);
std::shared_ptr<Division> operator/(const NodePtr&, const NodePtr&);

#endif  // SRC_OPERATIONS_ARITHMETIC_DIVISION_H_
