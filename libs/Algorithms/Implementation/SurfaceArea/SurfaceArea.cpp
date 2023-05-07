#include "SurfaceArea.h"

/****************************** Local Function Declarations *******************************************/


/****************************** Function Definitions **************************************************/

class loc {
public:
    loc() : i(0), j(0), k(0) {}
    loc(int a, int b, int c) : i(a), j(b), k(c) {}

    bool operator==(const loc& other) const {
        return i == other.i && j == other.j && k == other.k;
    }

    struct Hasher {
        std::size_t operator()(const loc& key) const {
            std::size_t seed = 0;
            seed ^= std::hash<int>{}(key.i) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
            seed ^= std::hash<int>{}(key.j) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
            seed ^= std::hash<int>{}(key.k) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
            return seed;
        }
    };

    int i, j, k;
};

// define hash and equality functions for MyKey
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

    cell(loc l)
    {
        this->l = l;
    }
    int getArea()
    {
        int area = 6;
        if (up != nullptr)
        {
            area--;
        }
        if (down != nullptr)
        {
            area--;
        }
        if (north != nullptr)
        {
            area--;
        }
        if (south != nullptr)
        {
            area--;
        }
        if (east != nullptr)
        {
            area--;
        }
        if (west != nullptr)
        {
            area--;
        }
        return area;
    }
};

class Toy
{
    int H;
    int W;
    int surfaceArea;
    vector<cell*> cells;
    unordered_map<loc, int> cellsIdx;
    unordered_map<loc, int> isOccupied;
    void computeSurfaceArea()
    {

    }
public:
    Toy(int H, int W)
    {
        this->H = H;
        this->W = W;
        surfaceArea = 0;
    }
    void addCell(cell* newCell)
    {
        cellsIdx[newCell->l] = static_cast<int>(cells.size());
        isOccupied[newCell->l] = true;
        cells.push_back(newCell);

        newCell->up    = getCellInDir(newCell->l, dir::UP);
        newCell->down  = getCellInDir(newCell->l, dir::DOWN);
        newCell->north = getCellInDir(newCell->l, dir::NORTH);
        newCell->south = getCellInDir(newCell->l, dir::SOUTH);
        newCell->east  = getCellInDir(newCell->l, dir::EAST);
        newCell->west  = getCellInDir(newCell->l, dir::WEST);
        
        computeSurfaceArea();
    }

    cell* getCell(loc l)
    {
        const int idx = cellsIdx[l];
        auto it = cellsIdx.find(l);

        if (it != cellsIdx.end())
        {
            return cells[idx];
        }
        else
        {
            return nullptr;
        }
        
    }

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
    T.printToy();

    for (auto c : holder)
    {
        delete c;
    }

    return area;
}
