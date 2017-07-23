#include "Node.h"

Node::Node(int arity): _arity(arity) {
    this->_predecessors = new vector<Node*>(arity);
}

int Node::Arity() {
    return this->_arity;
}

vector<Node*>* Node::Predecessors() {
    return this->_predecessors;
}

