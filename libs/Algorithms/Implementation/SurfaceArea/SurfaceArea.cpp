/**
 * @file SurfaceArea.cpp
 * @brief Solution to the hacker rank question : Queens Attack 2 is implemented here.
 */
#include "SurfaceArea.h"

/****************************** Local Function Declarations *******************************************/


/****************************** Function Definitions **************************************************/
/**
 * @brief class to represent the cell index. 
 *
 * (i => rows,j =>cols,k =>height)
 */
class loc {
public:
    /**
    * @brief Default constructor .
    */
    loc() : i(0), j(0), k(0) {}
    /**
    * @brief Construct a new loc object with the given indices .
    *
    * @param i row index.
    * @param j col index.
    * @param k height index
    */
    loc(int a, int b, int c) : i(a), j(b), k(c) {}

    /**
    * @brief Overload equal to operator .
    *
    * @param other loc object being compared to
    */
    bool operator==(const loc& other) const {
        return i == other.i && j == other.j && k == other.k;
    }

    int i, j, k;
};

// define hash and equality functions for loc (needed for usage as keys in unordered_map)
namespace std {
    template <>
    struct hash<loc> {
        size_t operator()(const loc& k) const {
            // implement hash function here
            return std::hash<int>()(k.i) ^ std::hash<int>()(k.j) ^ std::hash<int>()(k.k);
        }
    };

    template <>
    struct equal_to<loc> {
        bool operator()(const loc& lhs, const loc& rhs) const {
            // implement equality function here
            return lhs == rhs;
        }
    };
}

/**
 * @brief class to represent a cell.
 *
 * each cell has a location index -> loc
 * and pointers to its surrounding neighbor cells
 */
class cell 
{
public:
    loc l;
    cell* up;
    cell* down;
    cell* north;
    cell* south;
    cell* east;
    cell* west;

    /**
    * @brief Construct a new cell object with the given loc .
    *
    * @param l loc index of cell.
    */
    cell(loc l)
    {
        this->l = l;
        this->up = nullptr;
        this->down = nullptr;
        this->north = nullptr;
        this->south = nullptr;
        this->east = nullptr;
        this->west = nullptr;
    }
};

/**
 * @brief class to represent a Toy.
 *
 * Each toy is made up of multiple cells by stacking on top/next to each other.
 * H X W defines the base plate of the toy.
 * 
 */
class Toy
{
    int H;                   ///< base plate number of rows
    int W;                   ///< base plate number of cols
    int surfaceArea;         ///< surface area of toy
    vector<cell*> cells;     ///< vector of cell pointers that make up the toy
    unordered_map<loc, int> cellsIdx;   ///< map of loc (i,j,k) / cell to index in above "cells" vector container
    unordered_map<loc, int> isOccupied; ///< map of loc (i,j,k) / cell to occupancy of cell
    
public:
    /**
    * @brief Construct a new Toy object with the given base plate dims .
    *
    * @param H base plate num of rows
    * @param W base plate num of cols
    */
    Toy(int H, int W)
    {
        this->H = H;
        this->W = W;
        surfaceArea = 0;
    }
    /**
    * @brief Add a new cell/module to the toy.
    * 
    * @details
    * On adding a new cell to the toy, update the mapping of loc and vector idx of cell, and occupacy.
    * Then update the neighborhood info of the new cell.
    *
    * @param newCell pointer to new cell
    */
    void addCell(cell* newCell)
    {
        cellsIdx[newCell->l]   = static_cast<int>(cells.size());
        isOccupied[newCell->l] = true;
        cells.push_back(newCell);

        newCell->up    = getCellInDir(newCell->l, dir::UP);
        newCell->down  = getCellInDir(newCell->l, dir::DOWN);
        newCell->north = getCellInDir(newCell->l, dir::NORTH);
        newCell->south = getCellInDir(newCell->l, dir::SOUTH);
        newCell->east  = getCellInDir(newCell->l, dir::EAST);
        newCell->west  = getCellInDir(newCell->l, dir::WEST);
    }
    /**
    * @brief Get pointer to cell given its location.
    * @param l loc of cell
    * @return pointer to cell
    */
    cell* getCell(loc l)
    {
        auto it = cellsIdx.find(l);

        if (it != cellsIdx.end())
        {
            const int idx = cellsIdx[l];
            return cells[idx];
        }
        else
        {
            return nullptr;
        }        
    }

    /**
    * @brief Get pointer to neighbor cell in given direction dir.
    * @param l loc of cell
    * @param d dir 
    * @return pointer to cell
    */
    cell* getCellInDir(loc l, dir d)
    {
        loc tmp = l;
        switch (d)
        {
            case dir::UP:
            {                
                tmp.k += 1;                
                break;
            }
            case dir::DOWN:
            {
                tmp.k -= 1;
                break;
            }
            case dir::NORTH:
            {
                tmp.i += 1;
                break;
            }
            case dir::SOUTH:
            {
                tmp.i -= 1;
                break;
            }
            case dir::EAST:
            {
                tmp.j += 1;
                break;
            }
            case dir::WEST:
            {
                tmp.j -= 1;
                break;
            }
            default:
                break;            
        }

        auto it = isOccupied.find(tmp);
        if (it != isOccupied.end())
        {
            return getCell(tmp);
        }
        else
        {
            return nullptr;
        }
    }

    /**
    * @brief Count immediate neighbors for given cell.
    * @param c cell
    * @return number of immediate neighbors
    */
    int countNeighbors(cell* c)
    {
        int res = 0;

        if (c->up != nullptr)
        {
            res++;
        }
        if (c->down != nullptr)
        {
            res++;
        }
        if (c->north != nullptr)
        {
            res++;
        }
        if (c->south != nullptr)
        {
            res++;
        }
        if (c->east != nullptr)
        {
            res++;
        }
        if (c->west != nullptr)
        {
            res++;
        }

        return res;
    }

    /**
    * @brief Compute surface area of Toy.
    * @return surface area
    */
    int computeSurfaceArea()
    {
        for (auto c : cells)
        {
            int numNeigh = countNeighbors(c);

            if (numNeigh == 0)
            {
                surfaceArea += 6;
            }
            else if (numNeigh == 1)
            {
                surfaceArea += 4;
            }
            else if (numNeigh == 2)
            {
                surfaceArea += 2;
            }
            else
            {
                surfaceArea += 0;
            }
        }
        return surfaceArea;
    }

    /**
    * @brief Print toy cells.
    */
    void printToy()
    {
        for (auto i : cells)
        {
            cout << i->l.i << " " << i->l.j << " " << i->l.k << endl;
            cout << "no of neighbors: " << countNeighbors(i) << endl <<endl;
        }
    }

};

int surfaceArea(vector<vector<int>> A) {
    int area = 0;
    vector<cell*> holder;
    int H = static_cast<int>(A.size()); //rows
    int W = static_cast<int>(A[0].size());//cols
    Toy T(H, W);
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < A[i].size(); j++)
        {
            for (int k = 0; k < A[i][j]; k++)
            {
                loc l = { i,j,k };
                //shared_ptr<cell> c = make_shared<cell>(l);
                cell* c = new cell(l);
                T.addCell(c);
                holder.push_back(c);
            }            
        }
    }
#ifdef DEBUG
    T.printToy();
#endif // DEBUG
    
    area = T.computeSurfaceArea();

    for (auto c : holder)
    {
        delete c;
    }

    return area;
}
