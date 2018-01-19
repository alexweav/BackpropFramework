#ifndef SRC_OPERATIONS_ARITHMETIC_DIVISION_H_
#define SRC_OPERATIONS_ARITHMETIC_DIVISION_H_

#include <vector>
#include "Operations/Base/Operation.h"
#include "Operations/Base/Differentiable.h"
#include "Operations/Base/IDifferentiableExecutor.h"

class DivisionExecutor: public IDifferentiableExecutor {
 public:
    DataObject operator() (const std::vector<DataObject>& inputs) const;
    std::vector<DataObject> Differentiate(const std::vector<DataObject>& prevInputs, const DataObject& dOut) const;
};

class Division: public Operation, public Differentiable {
 public:
    Division(const NodePtr& i1, const NodePtr& i2);
    DataObject Forward(const std::vector<DataObject>& inputs) const;
    std::vector<DataObject> Backward(const std::vector<DataObject>& prevInputs, const DataObject& dout) const;

 private:
    DivisionExecutor _executor;
};

std::shared_ptr<Division> Divide(const NodePtr&, const NodePtr&);
std::shared_ptr<Division> operator/(const NodePtr&, const NodePtr&);

#endif  // SRC_OPERATIONS_ARITHMETIC_DIVISION_H_
