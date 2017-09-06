#include "src/Operations/Base/Node.h"
#include "src/Operations/Arithmetic/Addition.h"

Node::Node(std::initializer_list<NodePtr> inputs, bool isDifferentiable): _arity(inputs.size()),
         _hasDifferentiableTree(isDifferentiable) {
    for (NodePtr node : inputs) {
        _predecessors.push_back(node);
        _hasDifferentiableTree &= node->HasDifferentiableTree();
    }
}

int Node::Arity() {
    return this->_arity;
}

std::vector<NodePtr> Node::Predecessors() {
    return _predecessors;
}

bool Node::HasDifferentiableTree() const {
    return this->_hasDifferentiableTree;
}
