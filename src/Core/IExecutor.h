#ifndef SRC_OPERATIONS_BASE_IEXECUTOR_H_
#define SRC_OPERATIONS_BASE_IEXECUTOR_H_

#include <vector>

#include "Data/Datatypes.h"

class IExecutor {
 public:
    virtual DataObject operator() (const std::vector<DataObject>& inputs) const = 0;
};

#endif  // SRC_OPERATIONS_BASE_IEXECUTOR_H_
