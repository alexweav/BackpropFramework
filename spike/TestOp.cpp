#include "TestOp.h"

TestOpExecutor::TestOpExecutor(int add) {
    _add = add;
}

DataObject TestOpExecutor::operator()(const ExecutionContext& context) const {
    return context.Inputs().at(0).Add(context.Inputs().at(1));
}

TestOp::TestOp(const IChannelProviderPtr& i1, const IChannelProviderPtr& i2, int ref): NodeFacade({i1, i2}) {
    AttachExecutor(std::shared_ptr<TestOpExecutor>(new TestOpExecutor(ref)));
}
