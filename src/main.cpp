//#v0.4.5
//TODO : isboatsank bug remake plz // Try to log output // Try to change some color
#include <iostream>
#include <fstream>
#include "typeDef.h"
#include "functions.h"
#include "test.h"
using namespace std;


int main()
{
    

    system("color 9F");
    //Creation de joueur 1 et 2
    struct Player p1;
    struct Player p2;

    //call function to initialize the grid
    initializeGrid(p1.grid);
    initializeGrid(p2.grid);
    p1.score = 0;
    p2.score = 0;

    titleGame();
   

    //Check if the name is not over SIZE characters and if it is not empty
    cout << "Enter the name of the first player" << endl;
    cin >> p1.name;
    checkNameLength(p1.name);

    cout << "Enter the name of the second player" << endl;
    cin >> p2.name;
    checkNameLength(p2.name);

    displayGrid(p1, p2);
    cout << endl;

clearScreen();

ofstream logs;
logs.open("Coups joués.txt");
logs << "Here are the moves you played during your last game.\n";
logs <<"Player 1: " << p1.name << "Player 2: "<< p2.name << endl;


askPlayerToPlace(p1, p2);
askPlayerToPlace(p2, p1);

    while (p1.score <= NBCELLS || p2.score <= NBCELLS)
    {
        askPlayerToShot(p1, p2);
        askPlayerToShot(p2, p1);
    }
    if (p1.score == NBCELLS)
    {
        cout << "The Player " << p1.name << " has won" << endl;
    }
    else
    {
        cout << "The Player " << p2.name << " has won" << endl;
    }

return 0;


// titleGame();
// test_initializeGrid();
// test_placeShip();
// test_structureDonnees();
// test_hitOrMiss();


}
