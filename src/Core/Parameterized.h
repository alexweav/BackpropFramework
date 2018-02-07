#ifndef SRC_CORE_PARAMETERIZED_H_
#define SRC_CORE_PARAMETERIZED_H_

#include "Optimizers/IOptimizer.h"

class Parameterized: public virtual Node {
 public:
    Parameterized(): Node() {}
    virtual void Update(const IOptimizer& optimizer, const DataObject& gradOut) = 0;
};

#endif  // SRC_CORE_PARAMETERIZED_H_
