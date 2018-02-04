#ifndef SRC_OPERATIONS_BASE_NODE_H_
#define SRC_OPERATIONS_BASE_NODE_H_

#include <initializer_list>
#include <iostream>
#include <memory>
#include <vector>
#include <utility>

#include "Utils/Dictionary.h"
#include "Data/Datatypes.h"

#include "IChannelProvider.h"
#include "IExecutor.h"
#include "IDifferentiableExecutor.h"

class Node;
class Channel;
struct ChannelHash;
typedef std::shared_ptr<Node> NodePtr;
typedef std::shared_ptr<Channel> ChannelPtr;

class Channel: public IChannelProvider {
 public:
    Channel(Node* node, int index);
    Node* ParentNode(void) const;
    int Index(void) const;
    Channel GetChannel(void) const;
    bool operator==(const Channel& other) const;
 protected:
    Node* _node;
    int _index;
};

struct ChannelHash {
    std::size_t operator()(const Channel& channel) const {
        return utils::HashCombine(std::hash<Node*>()(channel.ParentNode()),
                                  std::hash<int>()(channel.Index()));
    }
};

using ChannelDictionary = std::unordered_map<Channel, DataObject, ChannelHash>;

class Node: public IChannelProvider, public std::enable_shared_from_this<Node> {
 public:
    Node() {}
    Node(std::vector<Channel>, bool isDifferentiable);
    Node(std::initializer_list<std::shared_ptr<IChannelProvider>> inputs, bool isDifferentiable);
    Node(std::vector<std::shared_ptr<IChannelProvider>> inputs, bool isDifferentiable);
    virtual DataObject Forward(const std::vector<DataObject>& inputs) const = 0;
    ChannelDictionary Execute(const std::vector<DataObject>& inputs);
    int Arity(void);
    std::vector<Channel> Channels(void) const;
    Channel Channels(int index) const;
    std::vector<std::pair<NodePtr, Channel>> Predecessors(void);
    bool IsDifferentiable(void) const;
    bool HasDifferentiableTree(void) const;
    int NumChannels(void);
    Channel GetChannel(void) const;
    std::shared_ptr<Node> GetPtr(void);

 protected:
    void RegisterExecutor(const std::shared_ptr<IExecutor> executor);
    void RegisterDifferentiableExecutor(const std::shared_ptr<IDifferentiableExecutor> executor);

    int _arity;
    int _numChannels = 0;
    bool _isDifferentiable = true;
    bool _hasDifferentiableTree = false;
    std::vector<std::pair<NodePtr, Channel>> _predecessors;
    std::vector<Channel> _channels;
    std::unordered_map<Channel, std::shared_ptr<IExecutor>, ChannelHash> _executors;
    std::unordered_map<Channel, std::shared_ptr<IDifferentiableExecutor>, ChannelHash> _differentiableExecutors;
};

using ResultDictionary = utils::Dictionary<Node, DataObject>;

#endif  // SRC_OPERATIONS_BASE_NODE_H_
