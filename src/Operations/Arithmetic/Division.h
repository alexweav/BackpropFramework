#ifndef SRC_OPERATIONS_ARITHMETIC_DIVISION_H_
#define SRC_OPERATIONS_ARITHMETIC_DIVISION_H_

#include <vector>
#include "Operations/Base/Operation.h"
#include "Operations/Base/Differentiable.h"

class Division: public Operation, public Differentiable {
 public:
    Division(Node* i1, Node* i2);
    DataObject Forward(const std::vector<DataObject>& inputs) const;
    std::vector<DataObject> Backward(const std::vector<DataObject>& prevInputs, const DataObject& dout) const;
};

Division* Divide(Node*, Node*);

#endif  // SRC_OPERATIONS_ARITHMETIC_DIVISION_H_
