//
//This file generates the board
//

#include "Grid.h"

#include <iostream>
 
using namespace std;


Grid::Grid(int size) {
    
    srand(time(NULL));

    this->size = size;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {

            grid[i][j] = '.';
        }
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {

            HidedGrid[i][j] = '.';
        }
    }
}


void Grid::elementDeploy(int numberOfElements) {

    int randomPlacement;// 0 = vertical , 1 = horizontal , 2 = diagonal

    for (int i = 0; i < numberOfElements; i++){

        grid[rand() % this->size][rand()% this-> size] = 'F';//random deployment for Food element


        int tempPlaceX = rand() % this->size;
        int tempPlaceY = rand() % this->size;

        grid[tempPlaceX][tempPlaceY] = 'I';

        randomPlacement = rand() % 2;// 0 = vertical , 1 = horizontal , 2 = diagonal

        if (randomPlacement == 0){//horizontal deployment
            if (tempPlaceX == size-1){
                grid[tempPlaceX-1][tempPlaceY] = 'I';
            }
            else{
                grid[tempPlaceX+1][tempPlaceY] = 'I';
            }
        }

        else if (randomPlacement == 1){//vertical deployment
            if (tempPlaceY == size-1){
                grid[tempPlaceX][tempPlaceY-1] = 'I';
            }
            else
                grid[tempPlaceX][tempPlaceY+1] = 'I';


        }


        else//diagonal deployment
        {
            if (tempPlaceX == 0 && tempPlaceY == 0){
                grid[tempPlaceX +1][tempPlaceY+1];
            }
            else if (tempPlaceX == size && tempPlaceY == 0){
                grid[tempPlaceX-1][tempPlaceY+1];
            }
            else if (tempPlaceX == 0 && tempPlaceY == size){
                grid[tempPlaceX+1][tempPlaceY-1];
            }
            else if (tempPlaceX == size && tempPlaceY == size){
                grid[tempPlaceX-1][tempPlaceY-1];
            }

        }


        grid[rand() % this->size][rand()% this-> size] = 'S';//size 1

        if (i %2  == 0) {//amount of bear is half of wolf
            int randomPlacement1 = rand()%2; // horizontal 0 vertical 1 diagonal 2

            int coordinateX = rand() % this->size;
            int coordinateY = rand() % this->size;

            grid[coordinateX][coordinateY] = 'B';

            if (randomPlacement1 == 1){//vertical placement
                if (coordinateX == 0){//if bear is on top side of the board
                    grid[coordinateX+1][coordinateY] = 'B';
                    grid[coordinateX+2][coordinateY] = 'B';
                }
                else if (coordinateX == 4){//if bear is on bottom side of the board
                    grid[coordinateX-1][coordinateY] = 'B';
                    grid[coordinateX-2][coordinateY] = 'B';
                }
                else{
                    grid[coordinateX-1][coordinateY] = 'B';
                    grid[coordinateX+1][coordinateY] = 'B';
                }
            }

            if (randomPlacement1 == 0){//horizontal placement
                if (coordinateY == 0){//if bear is left side of the board
                    grid[coordinateX][coordinateY+1] = 'B';
                    grid[coordinateX][coordinateY+2] = 'B';
                }
                else if (coordinateY == 4){// if bear is right side of the board
                    grid[coordinateX][coordinateY-1] = 'B';  
                    grid[coordinateX][coordinateY-2] = 'B';

                }
                else{
                    grid[coordinateX][coordinateY-1] = 'B';
                    grid[coordinateX][coordinateY+1] = 'B';
                }

            }


        }
        grid[rand() % this->size][rand()% this-> size] = 'W';//deployment of Wold (size = 1)
        grid[rand() % this->size][rand()% this-> size] = 'G';//deployment of Gold (size = 1)

    }
}

void Grid::display() {
    for (int i = 0; i<size; i++){
        for (int j = 0; j <size; j++){
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

char Grid::choice(int x, int y) {

    if (grid[x][y] == 'F'){
        return 'F';
    }
    else if (grid[x][y] == 'S'){
        return 'S';
    }
    else if (grid[x][y] == 'B'){
        return 'B';
    }
    else if (grid[x][y] == 'W'){
        return 'W';
    }
    else if (grid[x][y] == 'G'){
        return 'G';
    }
    else if (grid[x][y] == 'I'){
        return 'I';
    }
    else{
        return '.';
    }



}

void Grid::hidedGrid (int x,int y,char foundChar) {//If a player finds an element this function updates the HidedGrid to show the element

    if (foundChar == 'F') {
        HidedGrid[x][y] = 'F';
    } else if (foundChar == 'S') {
        HidedGrid[x][y] = 'S';
    } else if (foundChar == 'I') {
        HidedGrid[x][y] = 'I';
    } else if (foundChar == 'W') {
        HidedGrid[x][y] = 'W';
    } else if (foundChar == 'B') {
        HidedGrid[x][y] = 'B';
    } else if (foundChar == 'G') {
        HidedGrid[x][y] = 'G';
    }
}

void Grid::displayCurrentGrid() {//This function show the instantaneous version of the HidedGrid

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << HidedGrid[i][j] << " ";
        }
        cout << endl;
    }

}