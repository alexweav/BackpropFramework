#ifndef SRC_EVALUATION_UTILS_H_
#define SRC_EVALUATION_UTILS_H_

#include <utility>

#include "Core/Node.h"
#include "Operations/Value.h"

void AddChannelDictionaries(ChannelDictionary& target, const ChannelDictionary& source);
void LoadVariableOverrides(const Variables& variables, ChannelDictionary& overrides);

#endif  // SRC_EVALUATION_UTILS_H_
