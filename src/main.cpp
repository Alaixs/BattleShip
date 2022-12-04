//#v0.4.2
//TODO : remake askPlayerToPlace   // isboatsank bug remake plz//add decoration aroudn grid
#include <iostream>
#include <fstream>
#include "typeDef.h"
#include "functions.h"
#include "test.h"
using namespace std;


int main()
{
    system("color");
    //Creation de joueur 1 et 2
    struct Player p1;
    struct Player p2;

    //call function to initialize the grid
    initializeGrid(p1.grid);
    initializeGrid(p2.grid);

    titleGame();

    //Check if the name is not over SIZE characters and if it is not empty
    cout << "rentrer le nom du premier joueur" << endl;
    cin >> p1.name;
    checkNameLength(p1.name);

    cout << "Rentrer le nom du deuxieme joueur" << endl;
    cin >> p2.name;
    checkNameLength(p2.name);

    displayGrid(p1, p2);
    cout << endl;

clearScreen();

askPlayerToPlace(p1, p2);
askPlayerToPlace(p2, p1);

    while (p1.score > NBCELLS || p2.score > NBCELLS)
    {
        askPlayerToShot(p1, p2);
        askPlayerToShot(p2, p1);
    }
    if (p1.score > NBCELLS)
    {
        cout << "Le joueur " << p1.name << " a gagne" << endl;
    }
    else
    {
        cout << "Le joueur " << p2.name << " a gagne" << endl;
    }

return 0;


// titleGame();
// test_initializeGrid();
// test_placeShip();
// test_structureDonnees();
// test_hitOrMiss();
// test_isBoatSank();




}