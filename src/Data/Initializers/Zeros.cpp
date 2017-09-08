#include <vector>
#include "Data/Initializers/Zeros.h"

namespace Initializers {
    DataObject ZeroInitializer::Initialize(std::initializer_list<int64_t> shape) {
        if (shape.size() == 0) {
            return Scalar(0.0);
        }
        std::vector<int64_t> vShape(shape);
        return Mat(Eigen::MatrixXf::Zero(vShape.at(0), vShape.at(1)));
    }

    DataObject Zeros(void) {
        return Zeros({});
    }

    DataObject Zeros(int64_t rows, int64_t cols) {
        return Zeros({rows, cols});
    }

    DataObject Zeros(std::initializer_list<int64_t> shape) {
        ZeroInitializer initializer;
        return initializer.Initialize(shape);
    }
}
