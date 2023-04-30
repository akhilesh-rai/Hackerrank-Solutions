/**
 * @file OrganizeContainer.h
 * @brief Solution to the hacker rank question : Queens Attack 2 is implemented here.
 *
 *  Link: https://www.hackerrank.com/challenges/organizing-containers-of-balls/problem
 */
#ifndef ORGANIZECONTAINER_H
#define ORGANIZECONTAINER_H

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <algorithm>
#include <string>
#include <numeric>

using namespace std;

//#define DEBUG /*uncomment for some debug info*/

/**
* @brief Organizing containers of balls - Call this fxn.
* 
* @details  
* Below are few examples, when the algorithm shall return "Possible"* 
* @image html possibleExamples.png
* 
* One can observe, how the row sum matches the column sum. 
* Incase of Impossible case, this sum won't match, as seen in below examples
* @image html impossibleExamples.png
* 
* So solution is to check for the two arrays to be equal
*
* @param container Matrix M (rows denote containers, cols denote diferent types)
* @return "Possible" if swapping leads to segregations of types in unique containers, "Impossible" otherwise
*/
string organizingContainers(vector<vector<int>> container);

#endif /* ORGANIZECONTAINER_H */