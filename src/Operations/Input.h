#ifndef INPUT_H
#define INPUT_H

#include "Differentiable.h"

class Input: public Differentiable {
    public:
        Input();
        DataObject Forward(const vector<DataObject>& inputs) const;
        vector<DataObject> Backward(const vector<DataObject>&) const;
        void RegisterNewDefaultValue(float);
        float GetDefaultOutput();
    private:
        float _defaultOutput = 0;
};

typedef Dictionary<Input*, DataObject> Variables;

#endif
