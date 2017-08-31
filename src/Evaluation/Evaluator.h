#ifndef SRC_EVALUATION_EVALUATOR_H_
#define SRC_EVALUATION_EVALUATOR_H_

#include <vector>
#include "Operations/Base/Differentiable.h"
#include "Operations/Base/Input.h"
#include "Utils/Dictionary.h"
#include "Utils/Datatypes.h"

class Evaluator {
 public:
    DataObject ForwardEvaluate(Node*, const Variables& vars);
    utils::Dictionary<Node*, DataObject> BackwardEvaluate(Differentiable*, const Variables&);
 protected:
    DataObject ForwardEvaluate(Node*, utils::Dictionary<Node*, DataObject>&, std::vector<Node*>*);
    std::vector<DataObject> EvaluatePredecessors(Node*, utils::Dictionary<Node*, DataObject>&, std::vector<Node*>*);
};

#endif  // SRC_EVALUATION_EVALUATOR_H_
