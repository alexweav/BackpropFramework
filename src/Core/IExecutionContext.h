#ifndef SRC_CORE_IEXECUTIONCONTEXT_H_
#define SRC_CORE_IEXECUTIONCONTEXT_H_

#include <vector>

#include "Data/Datatypes.h"

class IExecutionContext {
 public:
    virtual std::vector<DataObject> Inputs(void) const;
    virtual DataObject DownstreamGradient(void) const;
};

#endif  // SRC_CORE_IEXECUTIONCONTEXT_H_
