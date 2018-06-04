#ifndef SRC_CORE_EXECUTIONCONTEXT_H_
#define SRC_CORE_EXECUTIONCONTEXT_H_

#include <vector>

#include "Data/Datatypes.h"

class ExecutionContext {
 public:
    ExecutionContext(void);
    ExecutionContext(const std::vector<DataObject>& inputs);
    ExecutionContext(const DataObject& grad);
    ExecutionContext(const std::vector<DataObject>& inputs, const DataObject& grad);
    std::vector<DataObject> Inputs(void) const;
    DataObject DownstreamGradient(void) const;
    void PushInput(const DataObject& input);
    void SetGradient(const DataObject& grad);

 protected:
    std::vector<DataObject> _inputs;
    DataObject _downstreamGradient;
};

#endif  // SRC_CORE_EXECUTIONCONTEXT_H_
