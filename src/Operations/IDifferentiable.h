#ifndef IDIFFERENTIABLE_H
#define IDIFFERENTIABLE_H

#include <vector>

using namespace std;

class IDifferentiable {
    public:
        virtual vector<float>* Backward(vector<float>* prevInputs) = 0;
};

#endif
