#ifndef CONSTANT_H
#define CONSTANT_H

#include "Node.h"
#include "Differentiable.h"

class Constant: public Differentiable {
    public:
        Constant(float value);
        DataObject Forward(const vector<DataObject>&) const;
        vector<DataObject> Backward(const vector<DataObject>&) const;
        float getValue();

    private:
        float _value;
};

#endif
