#ifndef NODE_H
#define NODE_H

#include <vector>
#include "../Utils/Dictionary.h"

using namespace std;

class Node {
    public:
        Node(int);
        virtual float Forward(vector<float>*) = 0;
        int Arity();
        vector<Node*>* Predecessors();
    protected:
        int _arity;
        vector<Node*>* _predecessors;
};

#endif
