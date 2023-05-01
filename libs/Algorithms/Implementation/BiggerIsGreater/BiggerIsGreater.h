/**
 * @file BiggerIsGreater.h
 * @brief https://www.hackerrank.com/challenges/bigger-is-greater/problem
 */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <algorithm>

using namespace std;

#ifndef BIGGERISGRREATER_H
#define BIGGERISGRREATER_H

#define DEBUG

/**
* @brief Compute next lexilogically greater string.
*
* @details
* Few examples \n
* ab  -> ba    \n
* abc -> acb   \n
* abcd -> abdc \n
* abdc -> acbd \n
* dkhc -> hcdk \n
* 
* Imagine finding words in a Dictionary. The returned string should be next \n
* higher string formed by existing characters of the string.
*
* @param  input string
* @return "no answer" if no higher order string can be formed, else return the higher order string
*/

string biggerIsGreater(string w);

#endif /* BIGGERISGRREATER_H */
