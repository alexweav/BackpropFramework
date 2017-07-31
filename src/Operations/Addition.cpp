#include "Addition.h"

using namespace std;

Addition::Addition(Node* i1, Node* i2): Operation({i1, i2}, true) { }

float Addition::Forward(const vector<float>& inputs) const {
    return inputs.at(0) + inputs.at(1);
}

vector<float> Addition::Backward(const vector<float>& prevInputs) const {
    vector<float> grads(this->_arity);
    grads.at(0) = 1.0;
    grads.at(1) = 1.0;
    return grads;
}
