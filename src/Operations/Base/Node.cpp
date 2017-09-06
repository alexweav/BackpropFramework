#include "src/Operations/Base/Node.h"
#include "src/Operations/Arithmetic/Addition.h"

Node::Node(std::initializer_list<Node*> inputs, bool isDifferentiable): _arity(inputs.size()),
         _hasDifferentiableTree(isDifferentiable) {
    //this->_predecessors = new std::vector<Node*>(_arity);
    //this->_successors = new std::vector<Node*>();
    for (Node* node : inputs) {
        _predecessors.push_back(node);
        _hasDifferentiableTree &= node->HasDifferentiableTree();
        node->RegisterSuccessor(this);
    }
}

int Node::Arity() {
    return this->_arity;
}

std::vector<Node*> Node::Predecessors() {
    return _predecessors;
}

void Node::RegisterSuccessor(Node* node) {
    this->_successors.push_back(node);
}

bool Node::HasDifferentiableTree() const {
    return this->_hasDifferentiableTree;
}

Node* Node::operator+(Node* const& other) {
    return new Addition(this, other);
}
