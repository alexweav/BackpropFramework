#ifndef IDIFFERENTIABLE_H
#define IDIFFERENTIABLE_H

#include <vector>
#include "Node.h"

using namespace std;

class IDifferentiable: public virtual Node {
    public:
        IDifferentiable(): Node() {}
        virtual vector<float> Backward(const vector<float>& prevInputs) const = 0;
};

#endif
