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

TEST(InitializerTests, OnesInitGivesScalarOne) {
    DataObject one = Initializers::Ones();
    EXPECT_EQ(one.Dim(), 0);
    EXPECT_EQ(one.Shape(), std::vector<int64_t>());
    EXPECT_FLOAT_EQ(one.ToScalar(), 1.0);
    one = Initializers::Ones({});
    EXPECT_EQ(one.Dim(), 0);
    EXPECT_EQ(one.Shape(), std::vector<int64_t>());
    EXPECT_FLOAT_EQ(one.ToScalar(), 1.0);
}

TEST(InitializerTests, OnesInitGivesMatrixOnes) {
    DataObject ones = Initializers::Ones(2, 3);
    EXPECT_EQ(ones.Dim(), 2);
    EXPECT_EQ(ones.Shape(), std::vector<int64_t>({2, 3}));
    EXPECT_EQ(ones.ToMatrix(), Eigen::MatrixXf::Constant(2, 3, 1.0));
    ones = Initializers::Ones({2, 3});
    EXPECT_EQ(ones.Dim(), 2);
    EXPECT_EQ(ones.Shape(), std::vector<int64_t>({2, 3}));
    EXPECT_EQ(ones.ToMatrix(), Eigen::MatrixXf::Constant(2, 3, 1.0));
}

TEST(InitializerTests, ConstantInitGivesScalarConstant) {
    DataObject two = Initializers::Constant(2.0);
    EXPECT_EQ(two.Dim(), 0);
    EXPECT_EQ(two.Shape(), std::vector<int64_t>());
    EXPECT_FLOAT_EQ(two.ToScalar(), 2.0);
    two = Initializers::Constant({}, 2.0);
    EXPECT_EQ(two.Dim(), 0);
    EXPECT_EQ(two.Shape(), std::vector<int64_t>());
    EXPECT_FLOAT_EQ(two.ToScalar(), 2.0);
}

TEST(Initializertests, ConstantInitGivesMatrixConstant) {
    DataObject twos = Initializers::Constant(2, 3, 2.0);
    EXPECT_EQ(twos.Dim(), 2);
    EXPECT_EQ(twos.Shape(), std::vector<int64_t>({2, 3}));
    EXPECT_EQ(twos.ToMatrix(), Eigen::MatrixXf::Constant(2, 3, 2.0));
    twos = Initializers::Constant({2, 3}, 2.0);
    EXPECT_EQ(twos.Dim(), 2);
    EXPECT_EQ(twos.Shape(), std::vector<int64_t>({2, 3}));
    EXPECT_EQ(twos.ToMatrix(), Eigen::MatrixXf::Constant(2, 3, 2.0));
}
