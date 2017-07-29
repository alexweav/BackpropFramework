#ifndef CONSTANT_H
#define CONSTANT_H

#include "Node.h"

class Constant: public Node {
    public:
        Constant(float value);
        float Forward(const vector<float>&) const;
        float getValue();

    private:
        float _value;
};

#endif
