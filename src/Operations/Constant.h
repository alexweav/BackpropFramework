#ifndef CONSTANT_H
#define CONSTANT_H

#include "Node.h"
#include "Differentiable.h"

class Constant: public Differentiable {
    public:
        Constant(float);
        Constant(const MatrixXf&);
        Constant(const DataObject&);
        DataObject Forward(const vector<DataObject>&) const;
        vector<DataObject> Backward(const vector<DataObject>&) const;
        DataObject getValue();

    private:
        DataObject _value;
};

#endif
