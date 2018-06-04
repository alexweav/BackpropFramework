#ifndef SRC_CORE_IDIFFERENTIABLEEXECUTOR_H_
#define SRC_CORE_IDIFFERENTIABLEEXECUTOR_H_

#include <vector>

#include "Core/IExecutor.h"

class IDifferentiableExecutor: public IExecutor {
 public:
    virtual DataObject operator() (const ExecutionContext& context) const = 0;
    virtual std::vector<DataObject> Differentiate(const ExecutionContext& context) const = 0;
};

#endif  // SRC_CORE_IDIFFERENTIABLEEXECUTOR_H_
