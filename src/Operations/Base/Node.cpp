#include "src/Operations/Base/Node.h"
#include "src/Operations/Arithmetic/Addition.h"

Node::Node(std::initializer_list<NodePtr> inputs, bool isDifferentiable): 
        _arity(inputs.size()),
        _hasDifferentiableTree(isDifferentiable) {
    for (NodePtr node : inputs) {
        _predecessors.push_back(node);
        _hasDifferentiableTree &= node->HasDifferentiableTree();
    }
    _numChannels = 1;
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

int Node::NumChannels(void) {
    return _numChannels;
}

