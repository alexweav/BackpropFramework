#ifndef SRC_OPERATIONS_BASE_NODE_H_
#define SRC_OPERATIONS_BASE_NODE_H_

#include <vector>
#include <initializer_list>
#include <iostream>
#include "Utils/Dictionary.h"
#include "Utils/Datatypes.h"

class Node {
 public:
    Node() {}
    Node(std::initializer_list<Node*>, bool isDifferentiable);
    virtual DataObject Forward(const std::vector<DataObject>&) const = 0;
    int Arity();
    std::vector<Node*>* Predecessors();
    void RegisterSuccessor(Node* node);
    bool HasDifferentiableTree() const;
    Node* operator+(Node* const& other);

 protected:
    int _arity;
    bool _hasDifferentiableTree = false;
    std::vector<Node*>* _predecessors;
    std::vector<Node*>* _successors;
};

typedef utils::Dictionary<Node*, DataObject> Overrides;

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
