#ifndef IDIFFERENTIABLE_H
#define IDIFFERENTIABLE_H

#include <vector>

using namespace std;

class IDifferentiable {
    public:
        virtual vector<float> Backward(const vector<float>& prevInputs) const = 0;
};

#endif
