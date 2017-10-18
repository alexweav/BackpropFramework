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

class Channel {
 public:
    Channel(Node* node);
    Node* ParentNode();
 protected:
    Node* _node;
};

typedef utils::Dictionary<Node, DataObject> ResultDictionary;
typedef utils::Dictionary<Channel, DataObject> ChannelDictionary;

#endif  // SRC_OPERATIONS_BASE_NODE_H_
