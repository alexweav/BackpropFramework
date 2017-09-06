#ifndef SRC_EVALUATION_EVALUATOR_H_
#define SRC_EVALUATION_EVALUATOR_H_

#include <vector>
#include "Operations/Base/Differentiable.h"
#include "Operations/Base/Input.h"
#include "Utils/Dictionary.h"
#include "Utils/Datatypes.h"

class Evaluator {
 public:
    DataObject ForwardEvaluate(NodePtr, const Variables& vars);
    utils::Dictionary<Node, DataObject> BackwardEvaluate(DifferentiablePtr, const Variables&);
 protected:
    DataObject ForwardEvaluate(NodePtr, utils::Dictionary<Node, DataObject>&, std::vector<NodePtr>*);
    std::vector<DataObject> EvaluatePredecessors(NodePtr, utils::Dictionary<Node, DataObject>&, std::vector<NodePtr>*);
};

#endif  // SRC_EVALUATION_EVALUATOR_H_
