#ifndef DATATYPES_H
#define DATATYPES_H

#include <memory>
#include "Eigen/Dense"

using namespace Eigen;

typedef enum dataKind {
    SCALAR,
    MATRIX
} DataKind;

class DataObject {
    public:
        DataObject(float);
        DataObject(MatrixXf*);
        ~DataObject();
        DataKind GetKind(void);
        template<typename T>
        T GetData(void);
        
    private:
        DataKind _kind;
        union {
            float _scalar;
            MatrixXf* _matrix;
        };
};

#endif
