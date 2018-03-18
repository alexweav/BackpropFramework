#include "TestCore.h"

TEST_F(DifferentiabilityTest, LeafNodesHaveDifferentiableTree) {
    EXPECT_TRUE(cons1->HasDifferentiableTree());
    EXPECT_TRUE(cons2->HasDifferentiableTree());
}

TEST_F(DifferentiabilityTest, ConstantChannelDifferentiable) {
    EXPECT_TRUE(cons1->Channels(0).IsDifferentiableFunctor());
    EXPECT_TRUE(cons2->Channels(0).IsDifferentiableFunctor());
}

TEST_F(DifferentiabilityTest, NonDifferentiableNodeNotDifferentiable) {
    EXPECT_TRUE(nonDiffCons1->HasDifferentiableTree());
    EXPECT_FALSE(nonDiffCons1->Channels(0).IsDifferentiableFunctor());
}

TEST_F(DifferentiabilityTest, TestDifferentiableTreeFunction) {
    EXPECT_TRUE(addDiff->HasDifferentiableTree());
    EXPECT_TRUE(addDiff->Channels(0).IsDifferentiableFunctor());
}

TEST_F(DifferentiabilityTest, TestNonDifferentiableTreeFunction) {
    EXPECT_FALSE(addNonDiffComposition->HasDifferentiableTree());
    EXPECT_TRUE(addNonDiffComposition->Channels(0).IsDifferentiableFunctor());
}

