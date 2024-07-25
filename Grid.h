//
// This file generates the board
//

#ifndef ASSIGNMENT3_GRID_H
#define ASSIGNMENT3_GRID_H

#include <ctime>
#include <iostream>
   

class Grid {

private:
    int size;
    char grid[100][100];//This is the grid which has the elements
    char HidedGrid[100][100];//This is the grid which is hided

public:

    Grid(int size);

    void hidedGrid (int x,int y,char foundChar);
    void displayCurrentGrid();
    void elementDeploy (int numberOfElements);
    void display();
    char choice (int x, int y);


};


#endif //ASSIGNMENT3_GRID_H