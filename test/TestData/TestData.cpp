#include "TestData.h"

TEST(DataObjectTests, ScalarDataObjectHasCorrectProperties) {
    float scalarValue = 5.0;
    DataObject five(scalarValue);
    EXPECT_EQ(five.Dim(), 0);
    std::vector<int64_t> expectedShape;
    EXPECT_EQ(five.Shape(), expectedShape);
}

TEST(DataObjectTests, MatrixDataObjectHasCorrectProperties) {
    Eigen::MatrixXf m(3, 2);
    DataObject matrix(m);
    EXPECT_EQ(matrix.Dim(), 2);
    std::vector<int64_t> expectedShape({3, 2});
    EXPECT_EQ(matrix.Shape(), expectedShape);
}
