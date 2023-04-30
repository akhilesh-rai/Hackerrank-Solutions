/**
 * @file QueensAttack2.h
 * @brief Solution to the hacker rank question : Queens Attack 2 is implemented here.
 *
 *  Link: https://www.hackerrank.com/challenges/queens-attack-2/problem
 */

#ifndef QUEENSATTACK2_H
#define QUEENSATTACK2_H

#include <cstdint> //uint16_t

//#define DEBUG /*uncomment for some debug info*/

constexpr uint16_t ROW = 0u;
constexpr uint16_t COL = 1u;

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

/**
*@brief Call this function to compute number of cells the Queen can move to.
*
*
* @param n         size of chess board (nXn)
* @param k         num of obstacles in the board (also same as obstacles.size() )
* @param r_q       row number of queen's current pos [1..n]
* @param c_q       col number of queen's current pos [1..n]
* @param obstacles cell position of all k obstacles ex. {{1,1}, [2,4}}
*
* @return num of free cells available for the queen to move to
*/
uint16_t queensAttack(uint16_t n, uint16_t k, uint16_t r_q, uint16_t c_q, vector<vector<uint16_t>> obstacles);

#endif /* QUEENSATTACK2_H */
