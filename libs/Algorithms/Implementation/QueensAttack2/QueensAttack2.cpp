/**
 * @file QueensAttack2.cpp
 * @brief Solution to the hacker rank question : Queens Attack 2 is implemented here.
 */
#include "QueensAttack2.h"

/****************************** Local Function Declarations *******************************************/
/**
* @brief Computes num of free cells in given direction.
* @param dir        The type of Direction 
* @param chessboard Chess board matrix
* @param queenPos   Current queen position in the board (converted!)
*
* @return num of free cells available for the queen to move in the Direction dir
*/
static uint16_t numCellFree(Direction dir, vector<vector<uint16_t>>& chessboard, vector<uint16_t> queenPos);


/****************************** Function Definitions **************************************************/
uint16_t queensAttack(uint16_t n, uint16_t k, uint16_t r_q, uint16_t c_q, vector<vector<uint16_t>> obstacles)
{
    uint16_t numCells = 0;
    vector<vector<uint16_t>> chessboard(n, vector<uint16_t>(n));

    /*Error Checks*/
    if (r_q > n || c_q > n)
    {
        return 0;
    }
    if (n <= 1)
    {
        return 0;
    }
    if (r_q < 1 || c_q < 1)
    {
        return 0;
    }
  
    const uint16_t queenRow = max(n - r_q, 0);
    const uint16_t queenCol = max(c_q - 1, 0);

    for (auto inner : obstacles)
    {
        /*Error Checks*/
        if (inner[ROW] > n || inner[COL] > n)
        {
            return 0;
        }
        chessboard[n - inner[ROW]][inner[COL] - 1] = 1;
    }

    /* Print Board*/
#ifdef DEBUG
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == queenRow && j == queenCol)
            {
                cout << "*" << " "; /*Mark Queens current pos*/
            }
            else
            {
                cout << chessboard[i][j] << " ";
            }
        }
        cout << endl;
    }
    cout << endl;
#endif // DEBUG

    /* Print empty cells per direction */
#ifdef DEBUG
    cout << "NORTH: " << numCellFree(Direction::NORTH, chessboard, {queenRow ,queenCol}) << endl;
    cout << "SOUTH: " << numCellFree(Direction::SOUTH, chessboard, { queenRow ,queenCol }) << endl;
    cout << "EAST: " << numCellFree(Direction::EAST, chessboard, { queenRow ,queenCol }) << endl;
    cout << "WEST: " << numCellFree(Direction::WEST, chessboard, { queenRow ,queenCol }) << endl;
    cout << "NORTHWEST: " << numCellFree(Direction::NORTHWEST, chessboard, { queenRow ,queenCol }) << endl;
    cout << "NORTHEAST: " << numCellFree(Direction::NORTHEAST, chessboard, { queenRow ,queenCol }) << endl;
    cout << "SOUTHWEST: " << numCellFree(Direction::SOUTHWEST, chessboard, { queenRow ,queenCol }) << endl;
    cout << "SOUTHEAST: " << numCellFree(Direction::SOUTHEAST, chessboard, { queenRow ,queenCol }) << endl;
#endif // DEBUG

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

static uint16_t numCellFree(Direction dir, vector<vector<uint16_t>> &chessboard, vector<uint16_t> queenPos)
{
    uint16_t       res        = 0u;
    const uint16_t BOARD_SIZE = static_cast<uint16_t>(chessboard.size());

    /*Error checks*/
    if (queenPos.size() != 2u)
    {
        return 0u;
    }

    switch (dir)
    {
        case Direction::NORTH:
        {
            uint16_t numOfBlocks = abs(ROW - queenPos[ROW]);

            for (uint16_t i = 1u; i <= numOfBlocks; i++)
            {
                if (chessboard[queenPos[ROW] - i][queenPos[COL]] == 1u)
                {
                    break;
                }
                res++;
            }
            break;
        }
        case Direction::SOUTH:
        {
            uint16_t numOfBlocks = abs(BOARD_SIZE - queenPos[ROW]-1);

            for (uint16_t i = 1u; i <= numOfBlocks; i++)
            {
                /*Error checks*/
                if ((queenPos[ROW] + i) >= BOARD_SIZE)
                {
                    return 0;
                }
                if (chessboard[queenPos[ROW] + i][queenPos[COL]] == 1u)
                {
                    break;
                }
                res++;
            }
            break;
        }
        case Direction::EAST:
        {
            uint16_t numOfBlocks = abs(BOARD_SIZE - queenPos[COL]-1);

            for (uint16_t i = 1u; i <= numOfBlocks; i++)
            {
                /*Error checks*/
                if ((queenPos[COL] + i) >= BOARD_SIZE)
                {
                    return 0;
                }
                if (chessboard[queenPos[ROW]][queenPos[COL]+i] == 1u)
                {
                    break;
                }
                res++;
            }
            break;
        }
        case Direction::WEST:
        {
            uint16_t numOfBlocks = abs(0 - queenPos[COL]);

            for (uint16_t i = 1u; i <= numOfBlocks; i++)
            {
                if (chessboard[queenPos[ROW]][queenPos[COL] - i] == 1u)
                {
                    break;
                }
                res++;
            }
            break;
        }
        case Direction::NORTHWEST:
        {
            uint16_t numOfBlocks = min(abs(0 - queenPos[0]), abs(0 - queenPos[COL]));

            for (uint16_t i = 1u; i <= numOfBlocks; i++)
            {
                if (chessboard[queenPos[ROW] - i][queenPos[COL]-i] == 1u)
                {
                    break;
                }
                res++;
            }
            break;
        }
        case Direction::NORTHEAST:
        {
            uint16_t numOfBlocks = min(abs(0 - queenPos[0]), abs(BOARD_SIZE - queenPos[COL] - 1 ));

            for (uint16_t i = 1u; i <= numOfBlocks; i++)
            {
                /*Error checks*/
                if ((queenPos[COL] + i) >= BOARD_SIZE)
                {
                    return 0;
                }
                if (chessboard[queenPos[ROW] - i][queenPos[COL] + i] == 1u)
                {
                    break;
                }
                res++;
            }
            break;
        }
        case Direction::SOUTHWEST:
        {
            uint16_t numOfBlocks = min(abs(BOARD_SIZE - queenPos[ROW]), abs(0 - queenPos[COL]));

            for (uint16_t i = 1u; i <= numOfBlocks; i++)
            {
                /*Error checks*/
                if ((queenPos[ROW] + i) >= BOARD_SIZE )
                {
                    return 0;
                }
                if (chessboard[queenPos[ROW] + i][queenPos[COL]-i] == 1u)
                {
                    break;
                }
                res++;
            }
            break;
        }
        case Direction::SOUTHEAST:
        {
            uint16_t numOfBlocks = min(abs(BOARD_SIZE - queenPos[ROW]), abs(BOARD_SIZE - queenPos[COL] - 1));

            for (uint16_t i = 1u; i <= numOfBlocks; i++)
            {
                /*Error checks*/
                if((queenPos[ROW] + i) >= BOARD_SIZE || (queenPos[COL] + i) >= BOARD_SIZE)
                {
                    return 0;
                }
                if (chessboard[queenPos[ROW] + i][queenPos[COL] + i] == 1u)
                {
                    break;
                }
                res++;
            }
            break;
        }
    }

    return res;
}
