#ifndef SRC_OPERATIONS_BASE_PARAMETERIZED_H_
#define SRC_OPERATIONS_BASE_PARAMETERIZED_H_

#include "Optimizers/IOptimizer.h"

class Parameterized: public virtual Node {
 public:
    Parameterized(): Node() {}
    virtual DataObject FindParameterGradients(const DataObject& dout) const = 0;
    virtual void Update(const IOptimizer& optimizer) const = 0;
};

#endif
