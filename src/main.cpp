//#v0.3.5
//TODO : fix input false // add decoration aroudn grid
#include <iostream>
#include "typeDef.h"
#include "functions.h"
#include "test.h"

using namespace std;

string aPlace;

int main()
{
    system("color");
    //Creation de joueur 1 et 2
    struct Player p1;
    struct Player p2;

    //call function to initialize the grid
    initializeGrid(p1.grid);
    initializeGrid(p2.grid);

    //test to see if the grid is initialized correctly with a ship
    //p1.grid[3][2].ship = CARRIER;


    cout  << R"(

                     BATTLESHIP                 |__            ©
                                                |\/
                                                ---
                                                / | [
                                        !  	| |||
                                        _/| 	_/|-++'
                                    +  +--|	|--|--|_ |-
                                { /|__|  |/\__|  |--- |||__/
                                +---------------___[}-_===_.'____             	/\
                            ____`-' ||___-{]_| _[}-  | 	|_[___\==--        	\/   _
             __..._____--==/___]_|__|_____________________________[___\==--____,------' .7
            |                                                                 	BB-61/
             \_________________________________________________________________________|
            )" << '\n'

          << endl << endl << endl;
    //Check if the name is not over SIZE characters and if it is not empty
    cout << "rentrer le nom du premier joueur" << endl;
    cin >> p1.name;
    checkNameLength(p1.name);
    
    cout << "Rentrer le nom du deuxieme joueur" << endl;
    cin >> p2.name;
    checkNameLength(p2.name);

    centerName(p1.name, p2.name);
    cout << endl;

    displayGrid(p1, p2);
    cout << endl;

void clearScreen();


askPlayerToPlace(p1, p2);

}



//test_initializeGrid();
//test_placeShip();
//test_alreadyShot();
//test_structureDonnees();
//test_hitOrMiss();
//test_isBoatSank();


