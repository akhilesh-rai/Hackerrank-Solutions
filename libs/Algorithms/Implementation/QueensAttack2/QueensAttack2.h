#pragma once
/* QUESTION : https://www.hackerrank.com/challenges/queens-attack-2/problem  */


#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <algorithm>

using namespace std;

enum class Direction
{
    NORTH,
    SOUTH,
    EAST,
    WEST,
    NORTHWEST,
    NORTHEAST,
    SOUTHWEST,
    SOUTHEAST
};

int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles);
