#ifndef SRC_OPERATIONS_BASE_DIFFERENTIABLE_H_
#define SRC_OPERATIONS_BASE_DIFFERENTIABLE_H_

#include "Node.h"
#include <vector>
#include <memory>

class Differentiable: public virtual Node {
 public:
    Differentiable(): Node() {}
    virtual std::vector<DataObject> Backward(const std::vector<DataObject>& prevInputs, const DataObject& dout) const = 0;
};

typedef std::shared_ptr<Differentiable> DifferentiablePtr;

#endif  // SRC_OPERATIONS_BASE_DIFFERENTIABLE_H_
