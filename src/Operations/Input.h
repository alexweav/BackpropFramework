#ifndef INPUT_H
#define INPUT_H

#include "Node.h"

class Input: public Node {
    public:
        Input();
        float Forward(const vector<float>& inputs) const;
        void RegisterNewDefaultValue(float);
        float GetDefaultOutput();
    private:
        float _defaultOutput = 0;
};
#endif
