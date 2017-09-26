#ifndef SRC_OPTIMIZERS_GRADIENTDESCENTOPTIMIZER_H_
#define SRC_OPTIMIZERS_GRADIENTDESCENTOPTIMIZER_H_

#include "Data/Datatypes.h"
#include "IOptimizer.h"

struct GradientDescentFunctor {
    DataObject operator()(float learningRate, const DataObject& parameter, const DataObject& grad){
        return Mat(parameter.ToMatrix() - (learningRate * grad.ToMatrix()));
    }
};

class GradientDescentOptimizer: public IOptimizer {
 public:
    GradientDescentOptimizer(float learningRate);
    DataObject Optimize(const DataObject& parameter, const DataObject& grad);

 private:
    float _learningRate;
};

#endif  // SRC_OPTIMIZERS_GRADIENTDESCENTOPTIMIZER_H_
