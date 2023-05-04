#include "AlmostSorted.h"

/****************************** Local Function Declarations *******************************************/

/****************************** Function Definitions **************************************************/
string almostSorted(vector<int> arr) {

    string res;
    int count = 0;
    int start = 0;
    int end = 0;
    int first = 0;
    bool evalDone = false;

    vector<int> tmp = arr;

    sort(arr.begin(), arr.end());

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] != tmp[i])
        {
            if (first != 0 && count > 1)
            {
#ifdef DEBUG
                cout << "no" << endl;
#endif 
                res = "no";

                evalDone = true;
                break;
            }
            else if (start != 0 && count != 0)
            {
                end = i+1;
            }
            else
            {
                start = i+1;
            }            
            count++;
        }
        else
        {
            if (start != 0 && first != 0 && count > 1)
            {
#ifdef DEBUG
                cout<< "no";
#endif
                res = "no";
                evalDone = true;
                break;
            }
            else if (count != 0)
            {
                first++;
            }
            else
            {
                /*do nothing*/
            }
        }
    }

    if (end > start && evalDone == false)
    {
        if (count == 2)
        {
#ifdef DEBUG
            cout << "yes" << endl;
            cout << "swap " << start << " " << end << endl;
#endif
            res = "yes\nswap " + to_string(start) + " " + to_string(end);
        }
        else
        {
            bool fail = false;
            for (int i = max((start-1),0); i < (end-1); i++)
            {
                //cout << tmp[i] << " " << tmp[i + 1] << endl;
                if (tmp[i] < tmp[(i + 1)])
                {
                    fail = true;
                    break;
                }
            }

            if (!fail)
            {
#ifdef DEBUG
                cout << "yes" << endl;
                cout << "reverse " << start << " " << end << endl;
#endif
                res = "yes\nreverse " + to_string(start) + " " + to_string(end);
            }
            else
            {
#ifdef DEBUG
                cout << "no" << endl;
#endif
                res = "no";
            }
        }
    }
    return res;
}
