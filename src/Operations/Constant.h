#ifndef CONSTANT_H
#define CONSTANT_H

#include "Node.h"
#include "IDifferentiable.h"

class Constant: public IDifferentiable {
    public:
        Constant(float value);
        float Forward(const vector<float>&) const;
        vector<float> Backward(const vector<float>&) const;
        float getValue();

    private:
        float _value;
};

#endif
