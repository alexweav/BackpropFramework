#ifndef SRC_OPERATIONS_ARITHMETIC_SUBTRACTION_H_
#define SRC_OPERATIONS_ARITHMETIC_SUBTRACTION_H_

#include <vector>
#include "Operations/Base/Operation.h"
#include "Operations/Base/Differentiable.h"

class Subtraction: public Operation, public Differentiable {
 public:
    Subtraction(Node* i1, Node* i2);
    DataObject Forward(const std::vector<DataObject>& inputs) const;
    std::vector<DataObject> Backward(const std::vector<DataObject>& prevInputs, const DataObject& dout) const;
};

Subtraction* Subtract(Node*, Node*);

#endif  // SRC_OPERATIONS_ARITHMETIC_SUBTRACTION_H_
