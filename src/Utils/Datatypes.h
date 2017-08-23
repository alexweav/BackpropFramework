#ifndef DATATYPES_H
#define DATATYPES_H

#include <memory>
#include "Eigen/Dense"

using namespace Eigen;

typedef enum dataKind {
    SCALAR,
    MATRIX
} DataKind;

typedef union dataPtr {
    float scalar;
    std::shared_ptr<MatrixXf> matrix;
} DataPtr;

class DataObject {
    public:
        DataObject(float);
        DataObject(std::shared_ptr<MatrixXf>);
        DataKind GetKind(void);
        template<typename T>
        T GetData(void);

        
    private:
        DataKind _kind;
        union {
            float _scalar;
            std::shared_ptr<MatrixXf> _matrix;
        };
};

#endif
