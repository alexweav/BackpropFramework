#include "Core/Channel.h"

Channel::Channel(Node* node, int index): Channel(node, index, false) { }

Channel::Channel(Node* node, int index, bool isDifferentiable) {
    _node = node;
    _index = index;
    _isDifferentiable = isDifferentiable;
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

bool Channel::IsDifferentiable(void) const {
    return _isDifferentiable;
}

Channel Channel::GetChannel(void) const {
    return *this;
}
