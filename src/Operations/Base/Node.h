#ifndef SRC_OPERATIONS_BASE_NODE_H_
#define SRC_OPERATIONS_BASE_NODE_H_

#include <vector>
#include <initializer_list>
#include <iostream>
#include <memory>
#include "Utils/Dictionary.h"
#include "Utils/Datatypes.h"

class Node;
typedef std::shared_ptr<Node> NodePtr;

class Node {
 public:
    Node() {}
    Node(std::initializer_list<NodePtr>, bool isDifferentiable);
    virtual DataObject Forward(const std::vector<DataObject>&) const = 0;
    int Arity();
    std::vector<NodePtr> Predecessors();
    bool HasDifferentiableTree() const;

 protected:
    int _arity;
    bool _hasDifferentiableTree = false;
    std::vector<NodePtr> _predecessors;
};

typedef utils::Dictionary<Node, DataObject> Overrides;

namespace std {

template<> struct hash<Node> {
    size_t operator()(const Node& node) const {
        auto addr = reinterpret_cast<uintptr_t>(&node);
        return addr;

    }
};

}   // namespace std

//template<typename V>
//using NodeMap = std::unordered_map<Node, V, std::hash<Node>>;

#endif  // SRC_OPERATIONS_BASE_NODE_H_
