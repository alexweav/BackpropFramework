#include "Core/NodeFacade.h"

NodeFacade::NodeFacade(std::initializer_list<std::shared_ptr<IChannelProvider>> predecessors) {
    _node = std::shared_ptr<Node>(new Node(predecessors));
}

NodePtr NodeFacade::GetNode(void) const {
    return _node;
}

void NodeFacade::AttachExecutor(const std::shared_ptr<IExecutor> executor) {
    _node->RegisterExecutor(executor);
}

void NodeFacade::AttachDifferentiableExecutor(const std::shared_ptr<IDifferentiableExecutor> executor) {
    _node->RegisterDifferentiableExecutor(executor);
}
