#ifndef CONSTANT_H
#define CONSTANT_H

#include "Node.h"
#include "Differentiable.h"

class Constant: public Differentiable {
    public:
        Constant(const DataObject& value);
        DataObject Forward(const vector<DataObject>&) const;
        vector<DataObject> Backward(const vector<DataObject>&) const;
        DataObject getValue();

    private:
        DataObject _value;
};

#endif
