#ifndef DATATYPES_H
#define DATATYPES_H

#include "Eigen/Dense"

using namespace Eigen;

typedef enum dataType {
    float32,
    float64
} DataType;

typedef enum dataKind {
    SCALAR,
    MATRIX
} DataKind;

class DataObject {
    public:
        DataObject(const std::initializer_list<uint32_t>&);
        DataObject(float);
        DataObject(const MatrixXf&);
        uint8_t Dim(void);
        DataKind GetKind(void);
        template<typename T>
        T GetData(void);
        
    private:
        uint8_t _dimension;
        std::initializer_list<uint32_t> _shape;
        DataKind _kind;
        float _scalar;
        MatrixXf _matrix;
};

#endif
