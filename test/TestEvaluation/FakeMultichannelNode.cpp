#include "FakeMultichannelNode.h"

DataObject FakeAddExecutor::operator() (const std::vector<DataObject>& inputs) const {
    ++_numEvaluations;
    return inputs.at(0).Add(inputs.at(1));
}

DataObject FakeSubtractExecutor::operator() (const std::vector<DataObject>& inputs) const {
    ++_numEvaluations;
    return DataObject(inputs.at(0).ToScalar() - inputs.at(2).ToScalar());
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
