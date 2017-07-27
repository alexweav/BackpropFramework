#include "Addition.h"

using namespace std;

Addition::Addition(Node* i1, Node* i2): Operation({i1, i2}) { }

float Addition::Forward(vector<float>* inputs) {
    return inputs->at(0) + inputs->at(1);
}

vector<float>* Addition::Backward(vector<float>* prevInputs) {
    vector<float>* grads = new vector<float>(this->_arity);
    grads->at(0) = 1.0;
    grads->at(1) = 1.0;
    return grads;
}
