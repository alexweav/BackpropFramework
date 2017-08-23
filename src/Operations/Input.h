#ifndef INPUT_H
#define INPUT_H

#include "Differentiable.h"

class Input: public Differentiable {
    public:
        Input();
        float Forward(const vector<float>& inputs) const;
        vector<float> Backward(const vector<float>&) const;
        void RegisterNewDefaultValue(float);
        float GetDefaultOutput();
    private:
        float _defaultOutput = 0;
};

typedef Dictionary<Input*, DataObject> Variables;

#endif
