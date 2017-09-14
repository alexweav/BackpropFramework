#include "TestData.h"

TEST(DataObjectTests, ScalarDataObjectHasCorrectProperties) {
    float scalarValue = 5.0;
    DataObject five(scalarValue);
    EXPECT_EQ(five.Dim(), 0);
    std::vector<int64_t> expectedShape;
    EXPECT_EQ(five.Shape(), expectedShape);
    EXPECT_EQ(five.GetKind(), DataKind::SCALAR);
}

TEST(DataObjectTests, MatrixDataObjectHasCorrectProperties) {
    Eigen::MatrixXf m(3, 2);
    DataObject matrix(m);
    EXPECT_EQ(matrix.Dim(), 2);
    std::vector<int64_t> expectedShape({3, 2});
    EXPECT_EQ(matrix.Shape(), expectedShape);
    EXPECT_EQ(matrix.GetKind(), DataKind::MATRIX);
}

TEST(DataObjectTests, ScalarDataObjectGivesCorrectScalarConversion) {
    DataObject five = Scalar(5.0);
    EXPECT_FLOAT_EQ(five.ToScalar(), 5.0);
    bool comparatorWorks = five == 5.0;
    EXPECT_EQ(comparatorWorks, true);
}

TEST(DataObjectTests, MatrixDataObjectGivesCorrectMatrixConversion) {
    Eigen::MatrixXf m(3, 2);
    DataObject matrix = Mat(m);
    EXPECT_EQ(matrix.ToMatrix(), m);
    bool comparatorWorks = matrix == m;
    EXPECT_EQ(comparatorWorks, true);
}
