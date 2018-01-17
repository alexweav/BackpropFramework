#ifndef SRC_OPERATIONS_ARITHMETIC_ADDITION_H_
#define SRC_OPERATIONS_ARITHMETIC_ADDITION_H_

#include <vector>
#include "Operations/Base/Operation.h"
#include "Operations/Base/Differentiable.h"
#include "Operations/Base/IDifferentiableExecutor.h"

class AdditionExecutor: public IDifferentiableExecutor {
 public:
    DataObject operator() (const std::vector<DataObject>& inputs) const;
    std::vector<DataObject> Differentiate(const std::vector<DataObject>& prevInputs, const DataObject& dOut) const;

 private:
    std::vector<DataObject> HandleBackward(const DataObject&, const DataObject&, const DataObject&) const;
    std::vector<DataObject> DifferentiateScalarAddition(const DataObject&, const DataObject&, const DataObject&) const;
    std::vector<DataObject> DifferentiateMatrixAddition(const DataObject&, const DataObject&, const DataObject&) const;

};

class Addition: public Operation, public Differentiable {
 public:
    Addition(const NodePtr& input1, const NodePtr& input2);
    DataObject Forward(const std::vector<DataObject>& inputs) const;
    std::vector<DataObject> Backward(const std::vector<DataObject>& prevInputs, const DataObject& dout) const;

 private:
    AdditionExecutor _executor;
};

std::shared_ptr<Addition> Add(const NodePtr&, const NodePtr&);
std::shared_ptr<Addition> operator+(const NodePtr& i1, const NodePtr& i2);

#endif  // SRC_OPERATIONS_ARITHMETIC_ADDITION_H_
