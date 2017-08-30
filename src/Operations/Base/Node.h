#ifndef NODE_H
#define NODE_H

#include <vector>
#include <initializer_list>
#include <iostream>
#include "Utils/Dictionary.h"
#include "Utils/Datatypes.h"

using namespace std;
using namespace utils;

class Node {
    public:
        Node() {}
        Node(initializer_list<Node*>, bool isDifferentiable);
        virtual DataObject Forward(const vector<DataObject>&) const = 0;
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

typedef Dictionary<Node*, DataObject> Overrides;

#endif