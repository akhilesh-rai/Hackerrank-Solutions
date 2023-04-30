#include "QueensAttack2.h"

/* Local Function Declarations*/
static int numCellFree(Direction dir, vector<vector<int>>& chessboard, vector<int> queenPos);


/* Function Definitions*/
int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles) 
{
    int numCells = 0;

    vector<vector<int>> chessboard(n, vector<int>(n));
    /*init vector to 0*/
    const int queenRow = max(n - r_q, 0);
    const int queenCol = max(c_q - 1, 0);
    chessboard[queenRow][queenCol] = 5;


    for (auto inner : obstacles)
    {
        chessboard[n - inner[0]][inner[1] - 1] = 1;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << chessboard[i][j] << " ";
        }
        cout << endl;
    }

    cout << "NORTH: " << numCellFree(Direction::NORTH, chessboard, { queenRow ,queenCol }) <<endl;
    cout << "SOUTH: " << numCellFree(Direction::SOUTH, chessboard, { queenRow ,queenCol }) << endl;
    cout << "EAST: " << numCellFree(Direction::EAST, chessboard, { queenRow ,queenCol }) << endl;
    cout << "WEST: " << numCellFree(Direction::WEST, chessboard, { queenRow ,queenCol }) << endl;
    cout << "NORTHWEST: " << numCellFree(Direction::NORTHWEST, chessboard, { queenRow ,queenCol }) << endl;
    cout << "NORTHEAST: " << numCellFree(Direction::NORTHEAST, chessboard, { queenRow ,queenCol }) << endl;
    cout << "SOUTHWEST: " << numCellFree(Direction::SOUTHWEST, chessboard, { queenRow ,queenCol }) << endl;
    cout << "SOUTHEAST: " << numCellFree(Direction::SOUTHEAST, chessboard, { queenRow ,queenCol }) << endl;

    numCells += numCellFree(Direction::NORTH, chessboard, { queenRow ,queenCol });
    numCells += numCellFree(Direction::SOUTH, chessboard, { queenRow ,queenCol });
    numCells += numCellFree(Direction::EAST, chessboard, { queenRow ,queenCol });
    numCells += numCellFree(Direction::WEST, chessboard, { queenRow ,queenCol });
    numCells += numCellFree(Direction::NORTHWEST, chessboard, { queenRow ,queenCol });
    numCells += numCellFree(Direction::NORTHEAST, chessboard, { queenRow ,queenCol });
    numCells += numCellFree(Direction::SOUTHWEST, chessboard, { queenRow ,queenCol });
    numCells += numCellFree(Direction::SOUTHEAST, chessboard, { queenRow ,queenCol });

    return numCells;
}

static int numCellFree(Direction dir, vector<vector<int>> &chessboard, vector<int> queenPos)
{
    int res = 0;

    int BOARD_SIZE = chessboard.size();   

    switch (dir)
    {
        case Direction::NORTH:
        {
            int extremNorth = chessboard[0][queenPos[1]];

            int numOfBlocks = abs(0 - queenPos[0]);

            for (int i = 1; i <= numOfBlocks; i++)
            {
                if (chessboard[queenPos[0] - i][queenPos[1]] == 0)
                {
                    res++;
                }
                else
                {
                    break;
                }
            }
            break;

        }
        case Direction::SOUTH:
        {
            int extremNorth = chessboard[0][queenPos[1]];

            int numOfBlocks = abs(BOARD_SIZE - queenPos[0]);

            for (int i = 1; i <= numOfBlocks; i++)
            {
                if (chessboard[queenPos[0] + i][queenPos[1]] == 0)
                {
                    res++;
                }
                else
                {
                    break;
                }
            }
            break;

        }
        case Direction::EAST:
        {
            int extremNorth = chessboard[0][queenPos[1]];

            int numOfBlocks = abs(BOARD_SIZE - queenPos[1]-1);

            for (int i = 1; i <= numOfBlocks; i++)
            {
                if (chessboard[queenPos[0]][queenPos[1]+i] == 0)
                {
                    res++;
                }
                else
                {
                    break;
                }
            }
            break;

        }
        case Direction::WEST:
        {
            int extremNorth = chessboard[0][queenPos[1]];

            int numOfBlocks = abs(0 - queenPos[1]);

            for (int i = 1; i <= numOfBlocks; i++)
            {
                if (chessboard[queenPos[0]][queenPos[1] - i] == 0)
                {
                    res++;
                }
                else
                {
                    break;
                }
            }
            break;

        }
        case Direction::NORTHWEST:
        {
            int extremNorth = chessboard[0][queenPos[1]];

            int numOfBlocks = min(abs(0 - queenPos[0]), abs(0 - queenPos[1]));

            for (int i = 1; i <= numOfBlocks; i++)
            {
                if (chessboard[queenPos[0] - i][queenPos[1]-i] == 0)
                {
                    res++;
                }
                else
                {
                    break;
                }
            }
            break;

        }
        case Direction::NORTHEAST:
        {
            int extremNorth = chessboard[0][queenPos[1]];

            int numOfBlocks = min(abs(0 - queenPos[0]), abs(BOARD_SIZE - queenPos[1] - 1));

            for (int i = 1; i <= numOfBlocks; i++)
            {
                if (chessboard[queenPos[0] - i][queenPos[1] + i] == 0)
                {
                    res++;
                }
                else
                {
                    break;
                }
            }
            break;

        }
        case Direction::SOUTHWEST:
        {
            int extremNorth = chessboard[0][queenPos[1]];

            int numOfBlocks = min(abs(BOARD_SIZE - queenPos[0]), abs(0 - queenPos[1]));

            for (int i = 1; i <= numOfBlocks; i++)
            {
                if (chessboard[queenPos[0] + i][queenPos[1]-i] == 0)
                {
                    res++;
                }
                else
                {
                    break;
                }
            }
            break;

        }
        case Direction::SOUTHEAST:
        {
            int extremNorth = chessboard[0][queenPos[1]];

            int numOfBlocks = min(abs(BOARD_SIZE - queenPos[0]), abs(BOARD_SIZE - queenPos[1] - 1));

            for (int i = 1; i <= numOfBlocks; i++)
            {
                if (chessboard[queenPos[0] + i][queenPos[1] + i] == 0)
                {
                    res++;
                }
                else
                {
                    break;
                }
            }
            break;

        }
    }

    return res;
}
