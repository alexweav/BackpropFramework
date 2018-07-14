#include "TestOp.h"

DataObject TestOpExecutor::operator()(const ExecutionContext& context) const {

}

TestOp::TestOp(const IChannelProviderPtr& i1, const IChannelProviderPtr& i2, int ref): NodeFacade({i1, i2}) {

}
