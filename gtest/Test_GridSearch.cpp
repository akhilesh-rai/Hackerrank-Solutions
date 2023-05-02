#include"..\libs\Algorithms\Implementation\GridSearch\GridSearch.h"
#include "gtest/gtest.h"

TEST(TestGridSearch, NoPatternMatch) {
    
    vector<string> G1 = { {1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15} };
    vector<string> P1 = { {1,3},{1,8},{1,13} };
    string res = gridSearch(G1, P1);
    EXPECT_EQ("NO", res);
}

TEST(TestGridSearch, PatternMatch) {

    vector<string> G1 = { {1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15} };
    vector<string> P1 = { {2,3},{7,8},{12,13} };
    string res = gridSearch(G1, P1);
    EXPECT_EQ("YES", res);
}