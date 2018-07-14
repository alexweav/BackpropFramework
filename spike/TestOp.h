#ifndef SRC_SPIKE_TESTNODE_H_
#define SRC_SPIKE_TESTNODE_H_

#include "Core/IDifferentiableExecutor.h"
#include "Core/NodeFacade.h"

class TestOpExecutor: public IExecutor {
 public:
    DataObject operator() (const ExecutionContext& context) const;
    std::vector<DataObject> Differentiate(const ExecutionContext& context) const;
};

class TestOp: public NodeFacade {
 public:
    TestOp(const IChannelProviderPtr& i1, const IChannelProviderPtr& i2, int ref);
};

#endif  // SRC_SPIKE_TESTNODE_H_
