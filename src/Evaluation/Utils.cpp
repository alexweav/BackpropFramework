#include "Utils.h"

void AddChannelDictionaries(ChannelDictionary& target, const ChannelDictionary& source) {
    for (std::pair<Channel, DataObject> element : source) {
        target[element.first] = element.second;
    }
}

