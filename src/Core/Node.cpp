#include "Core/Node.h"

template <class ...Args> Node::Node(const Args&... args) {
    std::vector<IChannelProvider*> inputs = {&args...};
    _arity = inputs.size();
    for (IChannelProvider* input : inputs) {
        try {
            Channel channel = input->GetChannel();
            NodePtr predecessorNode = channel.ParentNode()->GetPtr();
            _predecessors.push_back(std::pair<NodePtr, Channel>(predecessorNode, channel));
            _hasDifferentiableTree &= (channel.IsDifferentiableFunctor() && predecessorNode->HasDifferentiableTree());
        } catch (const std::invalid_argument& e) {
            throw std::invalid_argument("Predecessor node has multiple known channels.");
        }
    }
}

Node::Node(std::initializer_list<std::shared_ptr<IChannelProvider>> inputs):
    Node(std::vector<std::shared_ptr<IChannelProvider>>(inputs)) { }

Node::Node(std::vector<std::shared_ptr<IChannelProvider>> inputs):
        _arity(inputs.size()) {
    for (std::shared_ptr<IChannelProvider> input : inputs) {
        try {
            Channel channel = input->GetChannel();
            NodePtr predecessorNode = channel.ParentNode()->GetPtr();
            _predecessors.push_back(std::pair<NodePtr, Channel>(predecessorNode, channel));
            _hasDifferentiableTree &= (channel.IsDifferentiableFunctor() && predecessorNode->HasDifferentiableTree());
        } catch (const std::invalid_argument& e) {
            throw std::invalid_argument("Predecessor node has multiple known channels.");
        }
    }
}

ChannelDictionary Node::Execute(const std::vector<DataObject>& inputs) {
    ChannelDictionary results;
    for (Channel channel : _channels) {
        if (_executors.find(channel) != _executors.end()) {
            auto executor = _executors[channel];
            results[channel] = (*executor)(inputs);
        }
        if (_differentiableExecutors.find(channel) != _differentiableExecutors.end()) {
            auto executor = _differentiableExecutors[channel];
            results[channel] = (*executor)(inputs);
        }
    }
    return results;
}

int Node::Arity(void) {
    return this->_arity;
}

std::vector<std::pair<NodePtr, Channel>> Node::Predecessors(void) {
    return _predecessors;
}

bool Node::HasDifferentiableTree(void) const {
    return _hasDifferentiableTree;
}

std::vector<Channel> Node::Channels(void) const {
    return _channels;
}

Channel Node::Channels(int index) const {
    return _channels.at(index);
}

int Node::NumChannels(void) {
    return _numChannels;
}

void Node::AttachExecutor(const std::shared_ptr<IExecutor> executor) {
    _channels.push_back(Channel(this, _numChannels, false));
    _executors[_channels.at(_numChannels)] = executor;
    _numChannels++;
}
void Node::AttachDifferentiableExecutor(const std::shared_ptr<IDifferentiableExecutor> executor) {
    _channels.push_back(Channel(this, _numChannels, true));
    _differentiableExecutors[_channels.at(_numChannels)] = executor;
    _numChannels++;
}

Channel Node::GetChannel(void) const {
    if (_numChannels > 1) {
        throw std::invalid_argument("Node has multiple known channels.");
    }
    return Channels(0);
}

std::shared_ptr<Node> Node::GetPtr(void) {
    return shared_from_this();
}
