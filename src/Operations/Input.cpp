#include "Input.h"

Input::Input(): Node({}) { }

float Input::GetDefaultOutput() {
    return _defaultOutput;
}

float Input::Forward(const vector<float>& inputs) const {
    return _defaultOutput;
}

void Input::RegisterNewDefaultValue(float newValue) {
    _defaultOutput = newValue;
}
