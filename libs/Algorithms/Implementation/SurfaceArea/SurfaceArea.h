/**
 * @file SurfaceArea.h
 * @brief https://www.hackerrank.com/challenges/3d-surface-area/problem
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map> 
#include <functional>

using namespace std;

#ifndef SURFACEAREA_H
#define SURFACEAREA_H

enum class dir
{
    UP,
    DOWN,
    NORTH,
    SOUTH,
    EAST,
    WEST
};

/**
* @brief Find surface area as defined in problem
*
*
* @param  A toy 
* @return surface area as defined in the probelm
*/
int surfaceArea(vector<vector<int>> A);


#endif /* SURFACEAREA_H */
