#include "GradientDescentOptimizer.h"

GradientDescentOptimizer::GradientDescentOptimizer(float learningRate) {
    _learningRate = learningRate;
}

DataObject GradientDescentOptimizer::Optimize(const DataObject& parameter, const DataObject& grad) {
    if (parameter.Shape() == grad.Shape()) {
        GradientDescentFunctor functor;
        return functor(_learningRate, parameter, grad);
    }
    // error
}

