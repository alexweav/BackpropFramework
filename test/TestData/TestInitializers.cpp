#include "TestData.h"

TEST(InitializerTests, ZeroInitGivesScalarZero) {
    DataObject zeroScalar = Initializers::Zeros();
    EXPECT_EQ(zeroScalar.Dim(), 0);
    EXPECT_EQ(zeroScalar.Shape(), std::vector<int64_t>());
    EXPECT_FLOAT_EQ(zeroScalar.ToScalar(), 0.0);
    zeroScalar = Initializers::Zeros({});
    EXPECT_EQ(zeroScalar.Dim(), 0);
    EXPECT_EQ(zeroScalar.Shape(), std::vector<int64_t>());
    EXPECT_FLOAT_EQ(zeroScalar.ToScalar(), 0.0);
}

TEST(InitializerTests, ZeroInitGivesMatrixZero) {
    DataObject zeroMatrix = Initializers::Zeros(2, 3);
    EXPECT_EQ(zeroMatrix.Dim(), 2);
    EXPECT_EQ(zeroMatrix.Shape(), std::vector<int64_t>({2, 3}));
    EXPECT_EQ(zeroMatrix.ToMatrix(), Eigen::MatrixXf::Zero(2, 3));
    zeroMatrix = Initializers::Zeros({2, 3});
    EXPECT_EQ(zeroMatrix.Dim(), 2);
    EXPECT_EQ(zeroMatrix.Shape(), std::vector<int64_t>({2, 3}));
    EXPECT_EQ(zeroMatrix.ToMatrix(), Eigen::MatrixXf::Zero(2, 3));
}
