#include "Node.h"

Node::Node(int arity): _arity(arity) {
    this->_predecessors = new vector<Node*>(arity);
    this->_successors = new vector<Node*>();
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

