#include "Maze.h"
#include "MCell.h"

int main()
{
    int n = 5;
    int i1 = 0, j1 = 0, i2 = 0, j2 = 1;
    Maze myMaze(n, n);

    for (int i = 0; i < (n-1)*2; i++)
    {
        myMaze.makeConnection(i1, j1, i2, j2);
        if (i % 2 == 0) { j1++; i2++; }
        else { i1++; j2++; }  
    }

    myMaze.printMaze();
}
