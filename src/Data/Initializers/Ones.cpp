#include <vector>
#include "Data/Initializers/Ones.h"

namespace Initializers {
    DataObject OnesInitializer::Initialize(std::initializer_list<int64_t> shape) {
        if (shape.size() == 0) {
            return Scalar(1.0);
        }
        std::vector<int64_t> vShape(shape);
        return Mat(Eigen::MatrixXf::Constant(vShape.at(0), vShape.at(1), 1.0));
    }

    DataObject Ones(void) {
        return Ones({});
    }

    DataObject Ones(int64_t rows, int64_t cols) {
        return Ones({rows, cols});
    }

    DataObject Ones(std::initializer_list<int64_t> shape) {
        OnesInitializer initializer;
        return initializer.Initialize(shape);
    }
}
