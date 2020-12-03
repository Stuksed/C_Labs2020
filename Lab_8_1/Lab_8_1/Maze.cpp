#include <iostream>
#include <tuple>
#include "Maze.h"
#include "Direction.h"
using namespace std;

bool Maze::setConnection(int i1, int j1, int i2, int j2, bool typeConnect)
{
    if (abs(i1 - i2) == 1)
    {
        m_field[min(i1, i2) * n + min(j1, j2)].m_down = typeConnect;
        return true;
    }

    if (abs(j1 - j2) == 1)
    {
        m_field[min(j1, j2) * n + min(j1, j2)].m_right = typeConnect;
        return true;
    }

    return false;
}

Maze::Maze(int n, int m) : n(n), m(m) { m_field = new MCell[n * m]; }
Maze::~Maze() { delete m_field; }
MCell& Maze::cell(int i, int j) const { return m_field[i * n + j]; }

bool Maze::hasConnection(int i1, int j1, int i2, int j2)
{
    if (abs(i1 - i2) == 1)
        if (m_field[min(i1, i2) * n + min(j1, j2)].down())
            return true;

    if (abs(j1 - j2) == 1)
        if (m_field[min(i1, i2) * n + min(j1, j2)].right())
            return true;

    return false;
}

bool Maze::makeConnection(int i1, int j1, int i2, int j2) { return setConnection(i1, j1, i2, j2, true); }
bool Maze::removeConnection(int i1, int j1, int i2, int j2) { return setConnection(i1, j1, i2, j2, false); }

void Maze::printMaze()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            tuple<Direction, Direction> dirCode = make_tuple(None, None);

            if ((i - 1 >= 0) & hasConnection(i, j, i - 1, j))
                get<0>(dirCode) = Direction(get<0>(dirCode) | Down);

            if ((j - 1 >= 0) & hasConnection(i, j, i, j - 1))
                get<0>(dirCode) = Direction(get<0>(dirCode) | Right);

            if ((i + 1 <= n) & hasConnection(i, j, i + 1, j))
                get<1>(dirCode) = Direction(get<1>(dirCode) | Down);

            if ((j + 1 <= m) & hasConnection(i, j, i, j + 1))
                get<1>(dirCode) = Direction(get<1>(dirCode) | Right);

            if (get<0>(dirCode) == Right && get<1>(dirCode) == Right)
                cout << char(196);

            else if (get<0>(dirCode) == Right && get<1>(dirCode) == Down)
                cout << char(191);

            else if (get<0>(dirCode) == Down && get<1>(dirCode) == Right)
                cout << char(192);

            else if (get<0>(dirCode) == Down && get<1>(dirCode) == Down)
                cout << char(179);

            else if (get<0>(dirCode) == RightDown && get<1>(dirCode) == Down)
                cout << char(180);

            else if (get<0>(dirCode) == RightDown && get<1>(dirCode) == Right)
                cout << char(193);

            else if (get<0>(dirCode) == Right && get<1>(dirCode) == RightDown)
                cout << char(194);

            else if (get<0>(dirCode) == Down && get<1>(dirCode) == RightDown)
                cout << char(195);

            else if (get<0>(dirCode) == RightDown && get<1>(dirCode) == None)
                cout << char(217);

            else if (get<0>(dirCode) == None && get<1>(dirCode) == RightDown)
                cout << char(218);

            else if (get<0>(dirCode) == RightDown && get<1>(dirCode) == RightDown)
                cout << char(197);

            else cout << 0;
        }

        cout << endl;
    }
}
