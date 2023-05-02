#include "Bomberman.h"

/****************************** Local Function Declarations *******************************************/
static vector<int> findLocs(string s, char c);

static vector<Point> findCellWithBombs(vector<string> grid);

static void fillUpGrid(vector<string>& grid);

/****************************** Function Definitions **************************************************/
vector<string> bomberMan(int n, vector<string> grid) {
    const int gridHeight = static_cast<int>(grid.size());
    if (gridHeight < 1)
    {
        return {};
    }
    const int gridWidth = static_cast<int>(grid[0].size());
    string inner(gridWidth,'.');
    vector<string> res(gridHeight, inner);

    if (n <= 1)
    {
        res = grid;
        return res;
    }
    else
    {
        int time = 2;
        vector<Point> cellWithBomb = findCellWithBombs(grid);

        while (time <= n)
        {                 
            if (time % 2 != 0)//odd time == blow up time
            {
                for (Point p : cellWithBomb)
                {
                    grid[p.i][p.j] = '.';
                    if (p.i - 1 >= 0)
                    {
                        grid[p.i - 1][p.j] = '.';
                    }
                    if (p.i + 1 < gridHeight)
                    {
                        grid[p.i + 1][p.j] = '.';
                    }
                    if (p.j - 1 >= 0)
                    {
                        grid[p.i][p.j - 1] = '.';
                    }
                    if (p.j + 1 < gridWidth)
                    {
                        grid[p.i][p.j + 1] = '.';
                    }
                }

                cellWithBomb = findCellWithBombs(grid);
     
                res = grid;
            }
            else //even time == fill up time
            {
                fillUpGrid(grid);
                res = grid;
            }

            time++;
        }
    }

    return res;

}

static vector<int> findLocs(string s,char c)
{
    vector<int> res = {};

    for (int i = 0; i < s.length(); i++)
    {
        if (c == s[i])
        {
            res.push_back(i);
        }
    }

    return res;
}

static vector<Point> findCellWithBombs(vector<string> grid)
{
    vector<Point> cellWithBomb;
    int stringNum = 0;
    for (string s : grid)
    {
        vector<int> locsInner = findLocs(s, 'O');

        for (int i : locsInner)
        {
            Point p = { stringNum , i };
            cellWithBomb.push_back(p);
        }
        stringNum++;
    }
    return cellWithBomb;
}

static void fillUpGrid(vector<string>& grid)
{
    for (auto& s : grid)
    {
        for (int i = 0; i < s.length(); i++)
        {
            s[i] = 'O';
        }
    }
}