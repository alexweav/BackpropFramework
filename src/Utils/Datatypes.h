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
        DataObject(void);
        DataObject(const std::initializer_list<int64_t>&);
        DataObject(float);
        DataObject(const MatrixXf&);
        uint8_t Dim(void) const;
        std::vector<int64_t> Shape(void) const;
        DataKind GetKind(void) const;
        template<typename T>
        T GetData(void) const;
        bool operator==(const DataObject&);
        
    private:
        uint8_t _dimension;
        std::vector<int64_t> _shape;
        DataKind _kind;
        MatrixXf _matrix;

        void AllocateScalar(float);
};

DataObject Scalar(float);
DataObject Mat(const MatrixXf&);

#endif
