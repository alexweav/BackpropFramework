#ifndef SRC_DATA_DATATYPES_H_
#define SRC_DATA_DATATYPES_H_

#include <vector>
#include "Eigen/Dense"

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
    explicit DataObject(const std::initializer_list<int64_t>&);
    explicit DataObject(float);
    explicit DataObject(const Eigen::MatrixXf&);
    uint8_t Dim(void) const;
    std::vector<int64_t> Shape(void) const;
    DataKind GetKind(void) const;
    template<typename T>
    T GetData(void) const;
    float ToScalar(void) const;
    Eigen::MatrixXf ToMatrix(void) const;
    bool operator==(const DataObject&);
    bool operator==(const float);
    bool operator==(const Eigen::MatrixXf&);
    DataObject Add(const DataObject& other) const;
    DataObject ElementwiseMultiply(const DataObject& other) const;

 private:
    uint8_t _dimension;
    std::vector<int64_t> _shape;
    DataKind _kind;
    Eigen::MatrixXf _matrix;

    void AllocateScalar(float);
};

DataObject Scalar(float);
DataObject Mat(const Eigen::MatrixXf&);

std::ostream& operator<<(std::ostream& os, const DataObject& obj);

#endif  // SRC_DATA_DATATYPES_H_
