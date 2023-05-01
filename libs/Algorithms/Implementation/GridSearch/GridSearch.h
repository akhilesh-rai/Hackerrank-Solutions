/**
 * @file GridSearch.h
 * @brief https://www.hackerrank.com/challenges/the-grid-search/problem
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#ifndef GRIDSEARCH_H
#define GRIDSEARCH_H

/**
* @brief Find if pattern P is found in G.
*
*
* @param  G vector of strings, where the pattern is to be searched
* @param  P vector of strings, denotes the pattern to be searched
* @return "YES" if pattern is found, otherwise "NO"
*/

string gridSearch(vector<string> G, vector<string> P);

#endif /* GRIDSEARCH_H */
