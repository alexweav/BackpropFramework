#include "Input.h"

Input::Input(): Node(0) { }

float Input::GetDefaultOutput() {
    return _defaultOutput;
}

float Input::Forward(vector<float>* inputs) {
    return _defaultOutput;
}

void Input::RegisterNewDefaultValue(float newValue) {
    _defaultOutput = newValue;
}
