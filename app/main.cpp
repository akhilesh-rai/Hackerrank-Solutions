/**
 * @file main.cpp
 * @brief Entry Point. Calls to multiple hackkerrank problems.
 */
#include <iostream>

#include"..\libs\Algorithms\Implementation\QueensAttack2\QueensAttack2.h"
#include"..\libs\Algorithms\Implementation\OrganizeContainer\OrganizeContainer.h"
#include"..\libs\Algorithms\Implementation\BiggerIsGreater\BiggerIsGreater.h"


using namespace std;

/// @brief This is the entry point
/// @return 0
int main()
{
    /*Queen Attack 2*/
    //cout << "Queen Attack 2: " << queensAttack(5, 3, 4, 3, { {5,5},{4,2},{2,3} });
    //cout << "Queen Attack 2: " << queensAttack(4, 0, 4, 4, { });
    cout << "Queen Attack 2: " << queensAttack(8, 0, 1, 1, { }) << endl <<endl;

    /* Organize Container of Balls*/
    vector<vector<int>> container = { {999336263,998799923},{998799923,999763019} };
    //vector<vector<int>> container = { {997612619, 934920795, 998879231, 999926463},{960369681, 997828120, 999792735, 979622676},{ 999013654, 998634077, 997988323, 958769423 },{ 997409523, 999301350, 940952923, 993020546} };

    cout << "Organizing container of balls: " << organizingContainers(container) << endl << endl;

    /*Bigger is Greater*/
    //cout << biggerIsGreater("dkhc")<<endl;

}