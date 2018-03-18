#include "TestCore.h"

TEST_F(DifferentiabilityTest, LeafNodesHaveDifferentiableTree) {
    EXPECT_TRUE(cons1->HasDifferentiableTree());
    EXPECT_TRUE(cons2->HasDifferentiableTree());
}

TEST_F(DifferentiabilityTest, LeafNodeChannelDifferentiable) {
    EXPECT_TRUE(cons1->Channels(0).IsDifferentiableFunctor());
    EXPECT_TRUE(cons2->Channels(0).IsDifferentiableFunctor());
}
