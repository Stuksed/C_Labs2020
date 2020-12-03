#pragma once
#include "MCell.h"

enum Direction
{
    None = 0,
    Down = 1 << 0,
    Right = 1 << 1,
    RightDown = Down | Right
};

class Maze
{
    MCell* m_field;
    int n, m;
    bool setConnection(int, int, int, int, bool);

public:
    Maze(int, int);
    ~Maze();
    MCell& cell(int, int) const;
    bool hasConnection(int, int, int, int);
    bool makeConnection(int, int, int, int);
    bool removeConnection(int, int, int, int);
    void printMaze();
};