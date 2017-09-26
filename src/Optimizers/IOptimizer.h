#ifndef SRC_OPTIMIZERS_IOPTIMIZER_H_
#define SRC_OPTIMIZERS_IOPTIMIZER_H_

class IOptimizer {
 public:
    virtual DataObject Optimize(const DataObject& parameter, const DataObject& grad) = 0;
};

#endif  // SRC_OPTIMIZERS_IOPTIMIZER_H_
