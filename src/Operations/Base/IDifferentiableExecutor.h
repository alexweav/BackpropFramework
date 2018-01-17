#ifndef SRC_OPERATIONS_BASE_IDIFFERENTIABLEEXECUTOR_H_
#define SRC_OPERATIONS_BASE_IDIFFERENTIABLEEXECUTOR_H_

#include "Operations/Base/IExecutor.h"

class IDifferentiableExecutor: public virtual IExecutor {
 public:
    virtual DataObject operator() (const std::vector<DataObject>& inputs) const = 0;
    virtual std::vector<DataObject> Differentiate(const std::vector<DataObject>& prevInputs, const DataObject& dOut) const = 0;
};

#endif  // SRC_OPERATIONS_BASE_IDIFFERENTIABLEEXECUTOR_H_
