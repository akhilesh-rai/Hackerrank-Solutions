#include"../libs/Algorithms/Implementation/AlmostSorted/AlmostSorted.h"
#include "gtest/gtest.h"

TEST(TestAlmostSorted, NoSolution) {
    
    vector<int> arr = { 3,1,2 };
    string res = almostSorted(arr);
    EXPECT_EQ("no", res);
}

TEST(TestAlmostSorted, SwapSolution) {
    
    vector<int> arr = { 1,5,4,3,2,6};
    string res = almostSorted(arr);
    EXPECT_EQ("yes\nreverse 2 5", res);
}

TEST(TestAlmostSorted, ReverseSolution) {
    
    vector<int> arr = { 1,2,3,4,6,5};
    string res = almostSorted(arr);
    EXPECT_EQ("yes\nswap 5 6", res);
}

TEST(TestAlmostSorted, SwapSolution1) {

    vector<int> arr = { 1,6,3,4,5,2 };
    string res = almostSorted(arr);
    EXPECT_EQ("yes\nswap 2 6", res);
}