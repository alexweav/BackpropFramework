#ifndef SRC_CORE_IEXECUTOR_H_
#define SRC_CORE_IEXECUTOR_H_

#include <vector>

#include "Core/ExecutionContext.h"
#include "Data/Datatypes.h"

class IExecutor {
 public:
    virtual DataObject operator() (const ExecutionContext& context) const = 0;
};

#endif  // SRC_CORE_IEXECUTOR_H_
