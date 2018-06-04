#include "FakeMultichannelNode.h"

DataObject FakeAddExecutor::operator() (const ExecutionContext& context) const {
    ++_numEvaluations;
    return context.Inputs().at(0).Add(context.Inputs().at(1));
}

DataObject FakeSubtractExecutor::operator() (const ExecutionContext& context) const {
    ++_numEvaluations;
    return DataObject(context.Inputs().at(0).ToScalar() - context.Inputs().at(2).ToScalar());
}

FakeMultichannelNode::FakeMultichannelNode(const NodePtr& base, const NodePtr& add, const NodePtr& subtract):
        Node({base, add, subtract}),
        _addExecutor(new FakeAddExecutor()),
        _subtractExecutor(new FakeSubtractExecutor()) {
    RegisterExecutor(std::shared_ptr<IExecutor>(_addExecutor));
    RegisterExecutor(std::shared_ptr<IExecutor>(_subtractExecutor));
}

int FakeMultichannelNode::GetNumAdds(void) {
    return _addExecutor->GetNumEvaluations();
}

int FakeMultichannelNode::GetNumSubtracts(void) {
    return _subtractExecutor->GetNumEvaluations();
}

void FakeMultichannelNode::ResetCounter(void) {
    _addExecutor->ResetCounter();
    _subtractExecutor->ResetCounter();
}
