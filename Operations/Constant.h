#ifndef CONSTANT_H
#define CONSTANT_H

#include "Node.h"

class Constant: public Node {
    public:
        Constant(float value);
        float Forward(vector<float>*);
        float getValue();

    private:
        float _value;
};

#endif
