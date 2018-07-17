#ifndef SRC_SPIKE_TESTNODE_H_
#define SRC_SPIKE_TESTNODE_H_

#include "Data/Datatypes.h"
#include "Core/IChannelProvider.h"
#include "Core/IDifferentiableExecutor.h"
#include "Core/NodeFacade.h"

class TestOpExecutor: public IExecutor {
 public:
    TestOpExecutor(int add);
    DataObject operator() (const ExecutionContext& context) const;
    std::vector<DataObject> Differentiate(const ExecutionContext& context) const;

 private:
    int _add;
};

class TestOp: public NodeFacade {
 public:
    TestOp(const IChannelProvider& i1, const IChannelProvider& i2, int ref);
    TestOp(const IChannelProviderPtr& i1, const IChannelProviderPtr& i2, int ref);
};

#endif  // SRC_SPIKE_TESTNODE_H_
