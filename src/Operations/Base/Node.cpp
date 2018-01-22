#include "Node.h"
#include "src/Operations/Arithmetic/Addition.h"

Node::Node(std::initializer_list<NodePtr> inputs, bool isDifferentiable): 
        _arity(inputs.size()),
        _isDifferentiable(isDifferentiable),
        _hasDifferentiableTree(isDifferentiable) {
    for (NodePtr node : inputs) {
        if (node->NumChannels() > 1) {
            throw std::invalid_argument("Predecessor node has multiple known channels.");
        }
        _predecessors.push_back(std::pair<NodePtr, Channel>(node, node->Channels(0)));
        _hasDifferentiableTree &= node->HasDifferentiableTree();
    }
    _numChannels = 0;
    //_channels.push_back(Channel(this, 0));
}

Node::Node(std::vector<Channel> inputs, bool isDifferentiable):
        _arity(inputs.size()),
        _isDifferentiable(isDifferentiable),
        _hasDifferentiableTree(isDifferentiable) {
    for (Channel channel : inputs) {
        NodePtr node = std::shared_ptr<Node>(channel.ParentNode());
        _predecessors.push_back(std::pair<NodePtr, Channel>(node, channel)); 
        _hasDifferentiableTree &= node->HasDifferentiableTree();
    }
    _numChannels = 0;
    //_channels.push_back(Channel(this, 0));
}

ChannelDictionary Node::Execute(const std::vector<DataObject>& inputs) {
    ChannelDictionary results;
    for (Channel channel : _channels) {
        if (_executors.find(channel) != _executors.end()) {
            auto executor = _executors[channel];
            results[channel] = (*executor)(inputs);
        }
        if (_differentiableExecutors.find(channel) != _differentiableExecutors.end()) {
            auto executor = _executors[channel];
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

bool Node::IsDifferentiable(void) const {
    return _isDifferentiable;
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

void Node::RegisterExecutor(const std::shared_ptr<IExecutor> executor) {
    _channels.push_back(Channel(this, _numChannels));
    _executors[_channels.at(_numChannels)] = executor;
    _numChannels++;
    _isDifferentiable = false;
}
void Node::RegisterDifferentiableExecutor(const std::shared_ptr<IDifferentiableExecutor> executor) {
    if (_channels.size() == 0) {
        _isDifferentiable = true;
    }
    _channels.push_back(Channel(this, _numChannels));
    _differentiableExecutors[_channels.at(_numChannels)] = executor;
    _numChannels++;
}

Channel::Channel(Node* node, int index) {
    _node = node;
    _index = index;
}

bool Channel::operator==(const Channel& other) const {
    return _node == other.ParentNode() && _index == other.Index();
}

Node* Channel::ParentNode(void) const {
    return _node;
}

int Channel::Index(void) const {
    return _index;
}
