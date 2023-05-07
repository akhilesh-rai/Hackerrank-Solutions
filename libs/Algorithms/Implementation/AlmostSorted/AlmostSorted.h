/**
 * @file AlmostSorted.h
 * @brief https://www.hackerrank.com/challenges/almost-sorted/problem
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#ifndef ALMOSTSORTED_H
#define ALMOSTSORTED_H

/**
* @brief Prints output as described in problem definition .
*
* @details 
* First save copy of input arr and then sort it.  
* Afterwards, find start and end idx of the diferences to know swap/reverse.  
* Below image desribes it visually.   
* @image html AlmostSorted.png
*
* @param  arr  input array of almost sorted values
* @return string output as request in prob definition
*/
string almostSorted(vector<int> arr);

#endif /* ALMOSTSORTED_H */
