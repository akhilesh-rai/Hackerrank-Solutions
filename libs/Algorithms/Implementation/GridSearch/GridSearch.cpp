#include "GridSearch.h"

/****************************** Local Function Declarations *******************************************/


/****************************** Function Definitions **************************************************/
string gridSearch(vector<string> G, vector<string> P) 
{
    string res = "NO";
    int lenG = static_cast<int>(G.size());
    int lenP = static_cast<int>(P.size());
    vector<size_t> indices;

    bool found = false;
    int patternIdx = 0;
    for (string s : G)
    {
        size_t index = s.find(P[patternIdx]);
        if (found == true && index == string::npos)
        {
            break;
        }
        if (index != string::npos)
        {
            found = true;
            indices.push_back(index);
            patternIdx++;
            if (patternIdx >= lenP)
            {
                break;
            }
        }
    }

    if (indices.size() == lenP)
    {
        if (std::adjacent_find(indices.begin(), indices.end(), std::not_equal_to<>()) == indices.end())
        {
            res = "YES";
        }
    }
    

    return res;
}

