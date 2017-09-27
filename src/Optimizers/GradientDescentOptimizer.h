#ifndef SRC_OPTIMIZERS_GRADIENTDESCENTOPTIMIZER_H_
#define SRC_OPTIMIZERS_GRADIENTDESCENTOPTIMIZER_H_

#include "Data/Datatypes.h"
#include "IOptimizer.h"

struct GradientDescentFunctor {
    DataObject operator()(float learningRate, const DataObject& parameter, const DataObject& grad){
        if (parameter.Dim() == 0) {
            return Scalar(parameter.ToScalar() - (learningRate * grad.ToScalar()));
        }
        return Mat(parameter.ToMatrix() - (learningRate * grad.ToMatrix()));
    }
};

class GradientDescentOptimizer: public IOptimizer {
 public:
    GradientDescentOptimizer(float learningRate);
    DataObject AdjustNode(const DataObject& parameter, const DataObject& grad) const;

 private:
    float _learningRate;
};

#endif  // SRC_OPTIMIZERS_GRADIENTDESCENTOPTIMIZER_H_
