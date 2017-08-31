#ifndef INPUT_H
#define INPUT_H

#include "Differentiable.h"

class Input: public Differentiable {
    public:
        Input();
        DataObject Forward(const vector<DataObject>& inputs) const;
        vector<DataObject> Backward(const vector<DataObject>&) const;
        void RegisterNewDefaultValue(float);
        void RegisterNewDefaultValue(const Eigen::MatrixXf&);
        void RegisterNewDefaultValue(const DataObject&);
        DataObject GetDefaultOutput();
    private:
        DataObject _defaultOutput;
};

typedef Dictionary<Input*, DataObject> Variables;

#endif
