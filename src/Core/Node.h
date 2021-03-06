#ifndef SRC_CORE_NODE_H_
#define SRC_CORE_NODE_H_

#include <initializer_list>
#include <memory>
#include <vector>
#include <utility>

#include "Data/Datatypes.h"
#include "Utils/Dictionary.h"

#include "Channel.h"
#include "IChannelProvider.h"
#include "IExecutor.h"
#include "IDifferentiableExecutor.h"

class Node;
using NodePtr = std::shared_ptr<Node>;

class Node: public IChannelProvider, public std::enable_shared_from_this<Node> {
 public:
    Node() {}
    Node(std::initializer_list<std::shared_ptr<IChannelProvider>> inputs);
    Node(std::vector<std::shared_ptr<IChannelProvider>> inputs);
    ChannelDictionary Execute(const std::vector<DataObject>& inputs);
    int Arity(void);
    std::vector<Channel> Channels(void) const;
    Channel Channels(int index) const;
    std::vector<std::pair<NodePtr, Channel>> Predecessors(void);
    bool HasDifferentiableTree(void) const;
    int NumChannels(void);
    Channel GetChannel(void) const;
    std::shared_ptr<Node> GetPtr(void);

 protected:
    void RegisterExecutor(const std::shared_ptr<IExecutor> executor);
    void RegisterDifferentiableExecutor(const std::shared_ptr<IDifferentiableExecutor> executor);

    int _arity;
    int _numChannels = 0;
    bool _hasDifferentiableTree = true;
    std::vector<std::pair<NodePtr, Channel>> _predecessors;
    std::vector<Channel> _channels;
    std::unordered_map<Channel, std::shared_ptr<IExecutor>, ChannelHash> _executors;
    std::unordered_map<Channel, std::shared_ptr<IDifferentiableExecutor>, ChannelHash> _differentiableExecutors;
};

using ResultDictionary = utils::Dictionary<Node, DataObject>;

#endif  // SRC_CORE_NODE_H_
