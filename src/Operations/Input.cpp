#include "Input.h"

Input::Input(): Node({}) { }

float Input::GetDefaultOutput() {
    return _defaultOutput;
}

float Input::Forward(vector<float>* inputs) {
    return _defaultOutput;
}

void Input::RegisterNewDefaultValue(float newValue) {
    _defaultOutput = newValue;
}
