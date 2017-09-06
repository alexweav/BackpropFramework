#ifndef SRC_OPERATIONS_ARITHMETIC_ADDITION_H_
#define SRC_OPERATIONS_ARITHMETIC_ADDITION_H_

#include <vector>
#include "Operations/Base/Operation.h"
#include "Operations/Base/Differentiable.h"

class Addition: public Operation, public Differentiable {
 public:
    Addition(NodePtr input1, NodePtr input2);
    DataObject Forward(const std::vector<DataObject>& inputs) const;
    std::vector<DataObject> Backward(const std::vector<DataObject>& prevInputs, const DataObject& dout) const;

 private:
    std::vector<DataObject> HandleBackward(const DataObject&, const DataObject&, const DataObject&) const;
    std::vector<DataObject> DifferentiateScalarAddition(const DataObject&, const DataObject&, const DataObject&) const;
    std::vector<DataObject> DifferentiateMatrixAddition(const DataObject&, const DataObject&, const DataObject&) const;
};

std::shared_ptr<Addition> Add(NodePtr, NodePtr);

#endif  // SRC_OPERATIONS_ARITHMETIC_ADDITION_H_
