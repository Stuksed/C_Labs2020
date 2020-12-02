#include "Maze.h"
#include "MCell.h"

int main()
{
    Maze myMaze(5, 5);

    myMaze.makeConnection(0, 0, 0, 1);
    myMaze.makeConnection(0, 1, 1, 1);
    myMaze.makeConnection(1, 1, 1, 2);
    myMaze.makeConnection(1, 2, 2, 2);
    myMaze.makeConnection(0, 2, 2, 2);
    myMaze.makeConnection(2, 2, 2, 3);
    myMaze.makeConnection(2, 3, 3, 3);
    myMaze.makeConnection(3, 3, 3, 4);
    myMaze.makeConnection(3, 4, 4, 4);

    myMaze.printMaze();
}
