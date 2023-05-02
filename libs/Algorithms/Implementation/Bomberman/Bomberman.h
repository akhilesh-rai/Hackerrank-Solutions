/**
 * @file Bomberman.h
 * @brief https://www.hackerrank.com/challenges/bomber-man/problem
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#ifndef BOMBERMAN_H
#define BOMBERMAN_H

typedef struct Point {
    int i;
    int j;
}Point;

/**
* @brief Find if pattern P is found in G.
*
*
* @param  n    time to which 'grid' map is to be predicted
* @param  grid vector of strings, initial map
* @return map after 'n' secs
*/
vector<string> bomberMan(int n, vector<string> grid);

#endif /* BOMBERMAN_H */
