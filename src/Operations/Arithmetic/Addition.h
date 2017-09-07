#ifndef SRC_OPERATIONS_ARITHMETIC_ADDITION_H_
#define SRC_OPERATIONS_ARITHMETIC_ADDITION_H_

#include <vector>
#include "Operations/Base/Operation.h"
#include "Operations/Base/Differentiable.h"

class Addition: public Operation, public Differentiable {
 public:
    Addition(const NodePtr& input1, const NodePtr& input2);
    DataObject Forward(const std::vector<DataObject>& inputs) const;
    std::vector<DataObject> Backward(const std::vector<DataObject>& prevInputs, const DataObject& dout) const;

 private:
    std::vector<DataObject> HandleBackward(const DataObject&, const DataObject&, const DataObject&) const;
    std::vector<DataObject> DifferentiateScalarAddition(const DataObject&, const DataObject&, const DataObject&) const;
    std::vector<DataObject> DifferentiateMatrixAddition(const DataObject&, const DataObject&, const DataObject&) const;
};

std::shared_ptr<Addition> Add(const NodePtr&, const NodePtr&);
std::shared_ptr<Addition> operator+(const NodePtr& i1, const NodePtr& i2);

#endif  // SRC_OPERATIONS_ARITHMETIC_ADDITION_H_
