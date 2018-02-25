#ifndef SRC_CORE_CHANNEL_H_
#define SRC_CORE_CHANNEL_H_

#include <memory>

#include "Data/Datatypes.h"
#include "Utils/Dictionary.h"

#include "IChannelProvider.h"

class Node;

class Channel: public IChannelProvider {
 public:
    Channel(Node* node, int index);
    Channel(Node* node, int index, bool isDifferentiable);
    Node* ParentNode(void) const;
    int Index(void) const;
    bool IsDifferentiable(void) const;
    Channel GetChannel(void) const;
    bool operator==(const Channel& other) const;

 protected:
    Node* _node;
    int _index;
    bool _isDifferentiable;
};

using ChannelPtr = std::shared_ptr<Channel>;

struct ChannelHash {
    std::size_t operator()(const Channel& channel) const {
        return utils::HashCombine(std::hash<Node*>()(channel.ParentNode()),
               utils::HashCombine(std::hash<int>()(channel.Index()),
                                  std::hash<bool>()(channel.IsDifferentiable())));
    }
};

using ChannelDictionary = std::unordered_map<Channel, DataObject, ChannelHash>;

#endif  // SRC_CORE_CHANNEL_H_
