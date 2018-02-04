#ifndef SRC_EVALUATION_UTILS_H_
#define SRC_EVALUATION_UTILS_H_

#include <utility>

#include "Operations/Base/Input.h"
#include "Operations/Base/Node.h"

void AddChannelDictionaries(ChannelDictionary& target, const ChannelDictionary& source);
void LoadVariableOverrides(const Variables& variables, ChannelDictionary& overrides);

#endif  // SRC_EVALUATION_UTILS_H_
