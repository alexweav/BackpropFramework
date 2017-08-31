#ifndef SRC_OPERATIONS_BASE_DIFFERENTIABLE_H_
#define SRC_OPERATIONS_BASE_DIFFERENTIABLE_H_

#include "Node.h"
#include <vector>

class Differentiable: public virtual Node {
 public:
    Differentiable(): Node() {}
    virtual std::vector<DataObject> Backward(const std::vector<DataObject>& prevInputs) const = 0;
};

#endif  // SRC_OPERATIONS_BASE_DIFFERENTIABLE_H_
