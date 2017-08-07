#ifndef INPUT_H
#define INPUT_H

#include "IDifferentiable.h"

class Input: public IDifferentiable {
    public:
        Input();
        float Forward(const vector<float>& inputs) const;
        vector<float> Backward(const vector<float>&) const;
        void RegisterNewDefaultValue(float);
        float GetDefaultOutput();
    private:
        float _defaultOutput = 0;
};
#endif
