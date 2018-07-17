#include "Core/NodeFacade.h"

NodeFacade::NodeFacade(std::initializer_list<std::shared_ptr<IChannelProvider>> predecessors) {
    _node = std::shared_ptr<Node>(new Node(predecessors));
}

NodePtr NodeFacade::GetNode(void) const {
    return _node;
}

int NodeFacade::Arity(void) {
    return _node->Arity();
}

std::vector<Channel> NodeFacade::Channels(void) const {
    return _node->Channels();
}

Channel NodeFacade::Channels(int index) const {
    return _node->Channels(index);
}

int NodeFacade::NumChannels(void) {
    return _node->NumChannels();
}

Channel NodeFacade::GetChannel(void) const {
    return _node->GetChannel();
}

void NodeFacade::AttachExecutor(const std::shared_ptr<IExecutor> executor) {
    _node->AttachExecutor(executor);
}

void NodeFacade::AttachDifferentiableExecutor(const std::shared_ptr<IDifferentiableExecutor> executor) {
    _node->AttachDifferentiableExecutor(executor);
}

