#ifndef SRC_EVALUATION_EVALUATOR_H_
#define SRC_EVALUATION_EVALUATOR_H_

#include <vector>
#include "Operations/Base/Differentiable.h"
#include "Operations/Base/Input.h"
#include "Utils/Dictionary.h"
#include "Data/Datatypes.h"

class Evaluator {
 public:
    DataObject ForwardEvaluate(const NodePtr&, const Variables& vars);
    utils::Dictionary<Node, DataObject> BackwardEvaluate(const DifferentiablePtr&, const Variables&);
 protected:
    DataObject ForwardEvaluate(const NodePtr&, utils::Dictionary<Node, DataObject>&, std::vector<NodePtr>*);
    std::vector<DataObject> EvaluatePredecessors(const NodePtr&, utils::Dictionary<Node, DataObject>&, std::vector<NodePtr>*);
};

#endif  // SRC_EVALUATION_EVALUATOR_H_
