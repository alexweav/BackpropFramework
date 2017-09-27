#include "GradientDescentOptimizer.h"

GradientDescentOptimizer::GradientDescentOptimizer(float learningRate) {
    _learningRate = learningRate;
}

DataObject GradientDescentOptimizer::AdjustNode(const DataObject& parameter, const DataObject& grad) const {
    if (parameter.Shape() == grad.Shape()) {
        GradientDescentFunctor functor;
        return functor(_learningRate, parameter, grad);
    }
    // error
}

