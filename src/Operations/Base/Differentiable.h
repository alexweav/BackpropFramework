#ifndef DIFFERENTIABLE_H
#define DIFFERENTIABLE_H

#include <vector>
#include "Node.h"

using namespace std;

class Differentiable: public virtual Node {
    public:
        Differentiable(): Node() {}
        virtual vector<DataObject> Backward(const vector<DataObject>& prevInputs) const = 0;
};

#endif
