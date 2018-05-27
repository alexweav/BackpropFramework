#ifndef SRC_CORE_FORWARDEXECUTIONCONTEXT_H_
#define SRC_CORE_FORWARDEXECUTIONCONTEXT_H_

#include "Core/IExecutionContext.h"

class ForwardExecutionContext: public IExecutionContext {
 public:
    ForwardExecutionContext(void);
    ForwardExecutionContext(const std::vector<DataObject>& inputs);
    std::vector<DataObject> Inputs(void) const;
    DataObject DownstreamGradient(void) const;
    void PushInput(const DataObject& input);

 protected:
    std::vector<DataObject> _inputs;
};

#endif  // SRC_CORE_FORWARDEXECUTIONCONTEXT_H_
