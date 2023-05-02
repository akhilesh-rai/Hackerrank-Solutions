#include"..\libs\Algorithms\Implementation\OrganizeContainer\OrganizeContainer.h"
#include "gtest/gtest.h"

TEST(TestOrganizeContainer, Possible_2Container) {
    
    vector<vector<int>> container = { {999336263,998799923},{998799923,999763019} };
    string res = organizingContainers(container);
    EXPECT_EQ("Possible", res);
}

TEST(TestOrganizeContainer, Possible_4Container) {

    vector<vector<int>> container = { {997612619, 934920795, 998879231, 999926463},{960369681, 997828120, 999792735, 979622676},{ 999013654, 998634077, 997988323, 958769423 },{ 997409523, 999301350, 940952923, 993020546} };
    string res = organizingContainers(container);
    EXPECT_EQ("Possible", res);
}

TEST(TestOrganizeContainer, Impossible_2Container1) {
    
    vector<vector<int>> container = { {1,4},{2,3} };
    string res = organizingContainers(container);
    EXPECT_EQ("Impossible", res);
}

TEST(TestOrganizeContainer, Impossible_2Container2) {
    
    vector<vector<int>> container = { {0,2},{1,1} };
    string res = organizingContainers(container);
    EXPECT_EQ("Impossible", res);
}