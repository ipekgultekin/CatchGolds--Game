//Catch Golds

#include <iostream>
#include "Grid.h"
#include "Element.h"
#include "Player.h"
#include <ctime> //to generate random numbers

using namespace std;

   int main() {

    srand(time(NULL)); //to generate random numbers

    int sizeOftheBoard,numberOfRound,x,y;


    cout <<"                Welcome to Catch Golds!!" << endl;


    cout << "Enter size of the board: ";
    cin >> sizeOftheBoard;



    if (sizeOftheBoard < 5){
        cout << "Size of the board should be >= 5" << endl;
    }
else {
        int maxRound = sizeOftheBoard * sizeOftheBoard - 20; //to calculate max number of round
        numberOfRound = 20 + rand() % maxRound; //to randomly determine the number of games

        cout << endl << "Rounds: " << numberOfRound / 2 << endl;

        Grid grid(sizeOftheBoard); //we created a Grid object for the table

        cout << endl << endl << "Player 1 Health: " << 2 * sizeOftheBoard << endl;
        cout << endl << endl << "Player 2 Health: " << 2 * sizeOftheBoard << endl;
        //automatically, in the begining each players' health will be according to size of the board

        Player player1(sizeOftheBoard);
        Player player2(sizeOftheBoard);


        grid.elementDeploy(2 * sizeOftheBoard * sizeOftheBoard / 25);
        //placing the elements in the table

        //grid.display(); //If you want to see the unhided grid at the beginning of the game you can use this


        for (int round = 0; round < (numberOfRound + 1) / 2; round++) {
            grid.displayCurrentGrid(); //current table


            cout << "Player 1 choose a coordinate: " << endl; //first player's choice
            cin >> x;
            cin >> y;


            if (grid.choice(x, y) == 'F') { //if the player's choice equal to "Food"
                Food food(sizeOftheBoard);
                food.Effect(player1);

                grid.hidedGrid(x, y, 'F');

                cout << "You found Food! (this means your health will increase.)" << endl;
                cout << "Currently your health: " << player1.getHealth() << endl;
                cout << "Currently your score: " << player1.getScore();

            } else if (grid.choice(x, y) == 'I') {// if the player's choice equal to "Wood"
                Wood wood(sizeOftheBoard);
                wood.Effect(player1);

                grid.hidedGrid(x, y, 'I');

                cout << "You found Wood! (this means your health will increase.)" << endl;
                cout << "Currently your health: " << player1.getHealth() << endl;
                cout << "Currently your score: " << player1.getScore() << endl;

            } else if (grid.choice(x, y) == 'S') {// if the player's choice equal to "Medical Supplies"
                MedicalSupplies medic(sizeOftheBoard);
                medic.Effect(player1);

                grid.hidedGrid(x, y, 'S');

                cout << "You found medical supplies! (this means your health will increase.)" << endl;
                cout << "Currently your health: " << player1.getHealth() << endl;
                cout << "Currently your score: " << player1.getScore() << endl;

            } else if (grid.choice(x, y) == 'W') {// if the player's choice equal to "Wolf"
                Wolf wolf(sizeOftheBoard);
                wolf.Effect(player1);

                grid.hidedGrid(x, y, 'W');

                cout << "Ooops! You found wolf!! (this means your health will decrease!)" << endl;
                cout << "Currently your health: " << player1.getHealth() << endl;
                cout << "Currently your score: " << player1.getScore() << endl;

            } else if (grid.choice(x, y) == 'B') {// if the player's choice equal to "Bear"
                Bear bear(sizeOftheBoard);
                bear.Effect(player1);

                grid.hidedGrid(x, y, 'B');

                cout << "Ooops! You found bear!! (this means your health will decrease!)" << endl;
                cout << "Currently your health: " << player1.getHealth() << endl;
                cout << "Currently your score: " << player1.getScore() << endl;

            } else if (grid.choice(x, y) == 'G') {// if the player's choice equal to "Gold"
                Gold gold;
                gold.Effect(player1);

                grid.hidedGrid(x, y, 'G');

                cout << "You found GOLD!!! (this means your score will increase.)" << endl;
                cout << "Currently your health: " << player1.getHealth() << endl;
                cout << "Currently your score: " << player1.getScore() << endl;

            } else {
                cout << "You found Nothing! Unlucky :(" << endl;
            }

            cout << "Player 2 choose a coordinate: " << endl; //The same process for the Player 2
            cin >> x;
            cin >> y;


            if (grid.choice(x, y) == 'F') {
                Food food(sizeOftheBoard);
                food.Effect(player2);

                grid.hidedGrid(x, y, 'F');

                cout << "You found Food! (this means your health will increase.)" << endl;
                cout << "Currently your health: " << player2.getHealth() << endl;
                cout << "Currently your score: " << player2.getScore();

            } else if (grid.choice(x, y) == 'I') {
                Wood wood(sizeOftheBoard);
                wood.Effect(player2);

                grid.hidedGrid(x, y, 'I');

                cout << "You found Wood! (this means your health will increase.)" << endl;
                cout << "Currently your health: " << player2.getHealth() << endl;
                cout << "Currently your score: " << player2.getScore() << endl;

            } else if (grid.choice(x, y) == 'S') {
                MedicalSupplies medic(sizeOftheBoard);
                medic.Effect(player2);

                grid.hidedGrid(x, y, 'S');

                cout << "You found medical supplies! (this means your health will increase.)" << endl;
                cout << "Currently your health: " << player2.getHealth() << endl;
                cout << "Currently your score: " << player2.getScore() << endl;

            } else if (grid.choice(x, y) == 'W') {
                Wolf wolf(sizeOftheBoard);
                wolf.Effect(player2);

                grid.hidedGrid(x, y, 'W');

                cout << "Ooops! You found wolf!! (this means your health will decrease!)" << endl;
                cout << "Currently your health: " << player2.getHealth() << endl;
                cout << "Currently your score: " << player2.getScore() << endl;

            } else if (grid.choice(x, y) == 'B') {
                Bear bear(sizeOftheBoard);
                bear.Effect(player2);

                grid.hidedGrid(x, y, 'B');

                cout << "Ooops! You found bear!! (this means your health will decrease!)" << endl;
                cout << "Currently your health: " << player2.getHealth() << endl;
                cout << "Currently your score: " << player2.getScore() << endl;

            } else if (grid.choice(x, y) == 'G') {
                Gold gold;
                gold.Effect(player2);

                grid.hidedGrid(x, y, 'G');

                cout << "You fond GOLD!!! (this means your score will increase.)" << endl;
                cout << "Currently your health: " << player2.getHealth() << endl;
                cout << "Currently your score: " << player2.getScore() << endl;

            } else {
                cout << "You found Nothing! Unlucky :(" << endl;
            }
            //end of the round the program shows the current statistic for each player
            cout << "This is end of the round " << round << endl << "     Currently statistics: " << endl <<
                 "Player 1 health : " << player1.getHealth() << "     Player 2 health : " << player2.getHealth() << endl
                 <<
                 "Player 1 Score : " << player1.getScore() << "     Player 2 Score : " << player2.getScore() << endl;


            if (player1.getHealth() <= 0) {//If one of the player is dead, this means game is over
                cout << "            Player 1 is dead. GAME OVER" << endl;

                round = numberOfRound;
            } else if (player2.getHealth() <= 0) {

                cout << "            Player 2 is dead. GAME OVER" << endl;

                round = numberOfRound;
            }

        }

        if (player1.getScore() > player2.getScore()) {
            cout << "            PLAYER 1 IS WON CONGRATS!!" << endl << endl;
        } else if (player1.getScore() < player2.getScore()) {
            cout << "            PLAYER 2 IS WON CONGRATS!!" << endl << endl;
        } else {
            cout << "            DRAW :/ MAYBE YOU SHOULD PLAY AGAIN" << endl << endl;
        }


        grid.display();//This function shows the unhided grid end of the game
    }

    return 0;
}