#pragma once
#include "Test_GridSearch.cpp"
#include "Test_QueensAttack2.cpp"
#include "Test_OrganizeContainers.cpp"

#include "gtest/gtest.h"

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}