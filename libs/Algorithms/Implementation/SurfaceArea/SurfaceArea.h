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

//#define DEBUG

/**
* @brief Enumeration for possible neighbor cells for given cell
*/
enum class dir
{
    UP,    ///< in height direction or k++
    DOWN,  ///< in height direction or k--
    NORTH, ///< in row direction(H) or i++
    SOUTH, ///< in row direction(H) or i--
    EAST,  ///< in col direction(W) or j++
    WEST   ///< in col direction(W) or j++
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
