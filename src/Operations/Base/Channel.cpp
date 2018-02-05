#include "Operations/Base/Channel.h"

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

Channel Channel::GetChannel(void) const {
    return *this;
}
