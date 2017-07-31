#ifndef NODE_H
#define NODE_H

#include <vector>
#include <initializer_list>
#include <iostream>
#include "IDifferentiable.h"
#include "../Utils/Dictionary.h"

using namespace std;

class Node {
    public:
        Node(initializer_list<Node*>, bool isDifferentiable);
        virtual float Forward(const vector<float>&) const = 0;
        int Arity();
        vector<Node*>* Predecessors();
        void RegisterSuccessor(Node* node);
        bool HasDifferentiableTree() const;

    protected:
        int _arity;
        bool _hasDifferentiableTree = false;
        vector<Node*>* _predecessors;
        vector<Node*>* _successors;
};

#endif
