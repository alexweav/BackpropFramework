#ifndef SRC_OPTIMIZERS_GRADIENTDESCENTOPTIMIZER_H_
#define SRC_OPTIMIZERS_GRADIENTDESCENTOPTIMIZER_H_

#include "Data/Datatypes.h"

struct GradientDescentFunctor {
    DataObject operator()(float learningRate, const DataObject& parameter){
        return Mat(parameter.ToMatrix() * learningRate);
    }
};

#endif  // SRC_OPTIMIZERS_GRADIENTDESCENTOPTIMIZER_H_
