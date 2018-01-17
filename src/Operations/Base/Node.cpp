#include "src/Operations/Base/Node.h"
#include "src/Operations/Arithmetic/Addition.h"

Node::Node(std::initializer_list<NodePtr> inputs, bool isDifferentiable): 
        _arity(inputs.size()),
        _hasDifferentiableTree(isDifferentiable) {
    for (NodePtr node : inputs) {
        if (node->NumChannels() > 1) {
            throw std::invalid_argument("Predecessor node has multiple known channels.");
        }
        _predecessors.push_back(node);
        _hasDifferentiableTree &= node->HasDifferentiableTree();
    }
    _numChannels = 1;
    _channels.push_back(Channel(this, 0));
}

Node::Node(std::vector<ChannelPtr> inputs, bool isDifferentiable):
        _arity(inputs.size()),
        _hasDifferentiableTree(isDifferentiable) {
    for (ChannelPtr channel : inputs) {
        NodePtr node = std::shared_ptr<Node>(channel->ParentNode());
        _predecessors.push_back(node);
        _hasDifferentiableTree &= node->HasDifferentiableTree();
    }
    _numChannels = 1;
    _channels.push_back(Channel(this, 0));
}

int Node::Arity(void) {
    return this->_arity;
}

std::vector<NodePtr> Node::Predecessors(void) {
    return _predecessors;
}

bool Node::HasDifferentiableTree(void) const {
    return this->_hasDifferentiableTree;
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
