#ifndef SRC_CORE_IEXECUTOR_H_
#define SRC_CORE_IEXECUTOR_H_

#include <vector>

#include "Data/Datatypes.h"

class IExecutor {
 public:
    virtual DataObject operator() (const std::vector<DataObject>& inputs) const = 0;
};

#endif  // SRC_CORE_IEXECUTOR_H_
