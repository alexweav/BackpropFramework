#include "Input.h"

Input::Input(): Node({}, true) { }

float Input::GetDefaultOutput() {
    return _defaultOutput;
}

float Input::Forward(const vector<float>& inputs) const {
    return _defaultOutput;
}

vector<float> Input::Backward(const vector<float>& prevInputs) const {
    vector<float> gradsOut;
    return gradsOut;
}

void Input::RegisterNewDefaultValue(float newValue) {
    _defaultOutput = newValue;
}
