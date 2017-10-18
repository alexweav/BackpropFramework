#ifndef SRC_OPERATIONS_BASE_NODE_H_
#define SRC_OPERATIONS_BASE_NODE_H_

#include <vector>
#include <initializer_list>
#include <iostream>
#include <memory>
#include "Utils/Dictionary.h"
#include "Data/Datatypes.h"

class Node;
class Channel;
typedef std::shared_ptr<Node> NodePtr;
typedef std::shared_ptr<Channel> ChannelPtr;

class Node {
 public:
    Node() {}
    Node(std::initializer_list<NodePtr>, bool isDifferentiable);
    Node(std::vector<ChannelPtr>, bool isDifferentiable);
    virtual DataObject Forward(const std::vector<DataObject>& inputs) const = 0;
    int Arity(void);
    std::vector<Channel> Channels(void);
    std::vector<NodePtr> Predecessors(void);
    bool HasDifferentiableTree(void) const;
    int NumChannels(void);

 protected:
    int _arity;
    int _numChannels;
    bool _hasDifferentiableTree = false;
    std::vector<NodePtr> _predecessors;
    std::vector<Channel> _channels;
};

using ResultDictionary = utils::Dictionary<Node, DataObject>;

class Channel {
 public:
    Channel(Node* node, int index);
    Node* ParentNode(void) const;
    int Index(void) const;
 protected:
    Node* _node;
    int _index;
};

struct ChannelHash {
    size_t operator()(const Channel& channel) const {
        return utils::HashCombine(std::hash<Node*>()(channel.ParentNode()),
                                  std::hash<int>()(channel.Index()));
    }
};

using ChannelDictionary = std::unordered_map<Channel, DataObject, ChannelHash>;

#endif  // SRC_OPERATIONS_BASE_NODE_H_
