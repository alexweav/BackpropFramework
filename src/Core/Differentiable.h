#ifndef SRC_CORE_DIFFERENTIABLE_H_
#define SRC_CORE_DIFFERENTIABLE_H_

#include <memory>
#include <vector>

#include "Node.h"

class Differentiable: public virtual Node {
 public:
    Differentiable(): Node() {}
    virtual std::vector<DataObject> Backward(const std::vector<DataObject>& prevInputs, const DataObject& dout) const = 0;
};

typedef std::shared_ptr<Differentiable> DifferentiablePtr;

#endif  // SRC_CORE_DIFFERENTIABLE_H_
