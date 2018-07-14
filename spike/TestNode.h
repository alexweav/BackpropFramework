#ifndef SRC_SPIKE_TESTNODE_H_
#define SRC_SPIKE_TESTNODE_H_

#include "Core/IDifferentiableExecutor.h"

class TestOpExecutor: public IExecutor {
 public:
    DataObject operator() (const ExecutionContext& context) const;
    std::vector<DataObject> Differentiate(const ExecutionContext& context) const;
};

class TestOp: public NodeFacade {

};

#endif  // SRC_SPIKE_TESTNODE_H_
