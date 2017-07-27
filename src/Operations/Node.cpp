#include "Node.h"

Node::Node(initializer_list<Node*> inputs): _arity(inputs.size()) {
    this->_predecessors = new vector<Node*>(_arity);
    this->_successors = new vector<Node*>();
    int i = 0;
    for (Node* node : inputs) {
        _predecessors->at(i++) = node;
        node->RegisterSuccessor(this);
    }
}

int Node::Arity() {
    return this->_arity;
}

vector<Node*>* Node::Predecessors() {
    return this->_predecessors;
}

void Node::RegisterSuccessor(Node* node) {
    this->_successors->push_back(node);
}

