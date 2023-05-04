/**
 * @file main.cpp
 * @brief Entry Point. Calls to multiple hackkerrank problems.
 */
#include <iostream>

#include"../libs/Algorithms/Implementation/QueensAttack2/QueensAttack2.h"
#include"../libs/Algorithms/Implementation/OrganizeContainer/OrganizeContainer.h"
#include"../libs/Algorithms/Implementation/BiggerIsGreater/BiggerIsGreater.h"
#include"../libs/Algorithms/Implementation/GridSearch/GridSearch.h"
#include"../libs/Algorithms/Implementation/Bomberman/Bomberman.h"
#include"../libs/Algorithms/Implementation/AlmostSorted/AlmostSorted.h"

using namespace std;

/// @brief This is the entry point
/// @return 0
int main()
{
    /*Queen Attack 2*/
    cout << "Queen Attack 2: " << queensAttack(8, 0, 1, 1, { }) << endl <<endl;

    /* Organize Container of Balls*/
    vector<vector<int>> container = { {999336263,998799923},{998799923,999763019} };
    cout << "Organizing container of balls: " << organizingContainers(container) << endl << endl;

    /*Bigger is Greater*/
    //cout << biggerIsGreater("dkhc")<<endl;

    /*Grid Search*/
    vector<string> G1 = { {1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15} };
    vector<string> P1 = { {1,3},{1,8},{1,13} };
    cout << "Grid Search: " << gridSearch(G1, P1)<<endl;

    /*Bomber Man*/
    vector<string> res = bomberMan(3, { ".......","...O...","....O..",".......","OO.....","OO....." });
    for (string in : res)
    {
        cout << in << endl;
    }
    cout << endl;

    /*Almost Sorted*/
    cout << "Almost Sorted " << endl;
    vector<int> arr = { 1,5,4,3,2,6 };
    cout<< almostSorted(arr);
    cout << endl;

}