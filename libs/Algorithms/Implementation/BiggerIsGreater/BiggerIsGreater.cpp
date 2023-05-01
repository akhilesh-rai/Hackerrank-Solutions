#include "BiggerIsGreater.h"

/****************************** Local Function Declarations *******************************************/


/****************************** Function Definitions **************************************************/
template <typename T>
void util_swap(T& a, T& b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

string biggerIsGreater(string w) {
    string res     = "no answer";
    bool   success = false;

    set<char> charsSet;
    for (char c : w)
    {
        charsSet.insert(c);        
    }
#ifdef DEBUG
    for (char c : charsSet)
    {
        cout << c << " ";
    }
    cout << endl;
#endif // DEBUG

    int len = w.size();
    for (int i = len-1; i >= 1; i--)
    {
        for (int j = i-1; j >= 0; j--)
        {
            if (w[i] > w[j])
            {
                util_swap<char>(w[i], w[j]);
                success = true;
                break;
            }
        }
        if (success)
        {
            break;
        }
    }
    if (success)
    {
        res = w;
    }

    return res;
}
