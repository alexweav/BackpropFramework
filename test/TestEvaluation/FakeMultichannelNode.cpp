#include "FakeMultichannelNode.h"

DataObject FakeAddExecutor::operator() (const std::vector<DataObject>& inputs) const {
    return inputs.at(0).Add(inputs.at(1));
}

DataObject FakeSubtractExecutor::operator() (const std::vector<DataObject>& inputs) const {
    return DataObject(inputs.at(0).ToScalar() - inputs.at(2).ToScalar());
}

FakeMultichannelNode::FakeMultichannelNode(const NodePtr& base, const NodePtr& add, const NodePtr& subtract): Node({base, add, subtract}, false) {
    RegisterExecutor(std::shared_ptr<IExecutor>(new FakeAddExecutor()));
    RegisterExecutor(std::shared_ptr<IExecutor>(new FakeSubtractExecutor()));
}

DataObject FakeMultichannelNode::Forward(const std::vector<DataObject>& inputs) const { }
