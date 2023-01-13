//#v0.4.8
//TODO : // Try to log output // Try to change some color
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

    test_isBoatSank();

    titleGame();
    //ask if the player want to play versus the computer or versus another player
    int choice = 0;
    cout << "Do you want play versus a player or versus the computer ?" <<endl;
    cout << "1. Play versus the computer" << endl;
    cout << "2. Play versus another player" << endl;
    cin  >> choice;
    if(choice == 1)
    {
        cout << "Enter your name" <<endl;
        cin >> p1.name;
        checkNameLength(p1.name);
        p2.name = "Computer";

        displayGrid(p1, p2);
        cout << endl;
        clearScreen();
        askPlayerToPlace(p1, p2);
        randomPlacement(p2);
        cout << "1.Do you want play with slave of 3 shot ?" <<endl;
        cout << "2.Do you want play with normal rules?" <<endl;
        cin >> choice;
        if(choice == 1)
        {
             while (p1.score <= NBCELLS || p2.score <= NBCELLS)
            {
            askPlayerToShot(p1, p2);
            askPlayerToShot(p1, p2);
            askPlayerToShot(p1, p2);
            iaShot(p2, p1);
            iaShot(p2, p1);
            iaShot(p2, p1);
            }
            if (p1.score == NBCELLS)
    {
        cout << "The Player " << p1.name << " has won" << endl;
    }
    else
    {
        cout << "The Player " << p2.name << " has won" << endl;
    }

        }
        else if (choice == 2)
        {
         while (p1.score <= NBCELLS || p2.score <= NBCELLS)
            {
            askPlayerToShot(p1, p2);
            iaShot(p2, p1);
        }
            if (p1.score == NBCELLS)
    {
        cout << "The Player " << p1.name << " has won" << endl;
    }
    else
    {
        cout << "The Player " << p2.name << " has won" << endl;
    }
        
        
        }
        else
        {
            cout << "You have to choose between 1 and 2" << endl;
        }
    


    }
    else if(choice == 2)
    {
            //Check if the name is not over SIZE characters and if it is not empty
    cout << "Enter the name of the first player" << endl;
    cin >> p1.name;
    checkNameLength(p1.name);

    cout << "Enter the name of the second player" << endl;
    cin >> p2.name;
    checkNameLength(p2.name);

    askPlayerToPlace(p1, p2);
    askPlayerToPlace(p2, p1);

cout << "1.Do you want play with slave of 3 shot ?" <<endl;
cout << "2.Do you want play with normal rules?" <<endl;
cin >> choice;
if(choice == 1)
{

 while (p1.score <= NBCELLS || p2.score <= NBCELLS)
    {
        askPlayerToShot(p1, p2);
        askPlayerToShot(p1, p2);
        askPlayerToShot(p1, p2);
        askPlayerToShot(p2, p1);
        askPlayerToShot(p2, p1);
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

}
else if(choice == 2)
{
 while (p1.score <= NBCELLS || p2.score <= NBCELLS)
    {
        askPlayerToShot(p1, p2);
        
    }
    if (p1.score == NBCELLS)
    {
        cout << "The Player " << p1.name << " has won" << endl;
    }
    else
    {
        cout << "The Player " << p2.name << " has won" << endl;
    }
    }}
else
{

    cout << "Wrong number" << endl;
}
   
clearScreen();

return 0;
    
}
// titleGame();
// test_initializeGrid();
// test_placeShip();
// test_structureDonnees();
// test_hitOrMiss();
// test_isBoatSank();



