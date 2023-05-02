#include"../libs/Algorithms/Implementation/QueensAttack2/QueensAttack2.h"
#include "gtest/gtest.h"

TEST(TestQueensAttack2, QueenAtLeftBottomCornerNoObstacles) {
    
    int res = queensAttack(8, 0, 1, 1, { });
    EXPECT_EQ(21, res);
}

TEST(TestQueensAttack2, QueenAtRightTopCornerNoObstacles) {

    int res = queensAttack(8, 0, 8, 8, { });
    EXPECT_EQ(21, res);
}

TEST(TestQueensAttack2, QueenAtPenultimateTopRow_3Obstacles) {

    int res = queensAttack(5, 3, 4, 3, { {5,5},{4,2},{2,3} });
    EXPECT_EQ(10, res);
}

TEST(TestQueensAttack2, QueenAtMiddle_3Obstacles) {

    int res = queensAttack(5, 3, 3, 3, { {5,5},{4,2},{2,3} });
    EXPECT_EQ(11, res);
}

TEST(TestQueensAttack2, QueenAtMiddle_NoObstacles) {

    int res = queensAttack(5, 0, 3, 3, { });
    EXPECT_EQ(16, res);
}

