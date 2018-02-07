#include "Evaluation/Utils.h"

void AddChannelDictionaries(ChannelDictionary& target, const ChannelDictionary& source) {
    for (std::pair<Channel, DataObject> element : source) {
        target[element.first] = element.second;
    }
}

void LoadVariableOverrides(const Variables& variables, ChannelDictionary& overrides) {
    for (std::pair<InputPtr, DataObject> element : variables) {
        overrides[element.first->Channels(0)] = element.second;  // Inputs only have one Channel
    }
}


