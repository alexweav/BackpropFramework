#ifndef NODE_H
#define NODE_H

#include <vector>
#include <initializer_list>
#include <iostream>
#include "../Utils/Dictionary.h"

using namespace std;

class Node {
    public:
        Node(initializer_list<Node*>);
        virtual float Forward(vector<float>*) = 0;
        int Arity();
        vector<Node*>* Predecessors();
        void RegisterSuccessor(Node* node);
    protected:
        int _arity;
        vector<Node*>* _predecessors;
        vector<Node*>* _successors;
};

#endif
