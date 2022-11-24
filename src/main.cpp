//#v0.2
//TODO : Put name in color
#include <iostream>
#include "typeDef.h"
#include "functions.h"

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

    p1.grid[2][5].ship = CARRIER;



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
    //Verification si le nom fait moins de 12 caractere sinon bug du terminal pour les deux joueurs
    cout << "rentrer le nom du premier joueur" << endl;
    cin >> p1.name;
    if (p1.name.length() > SIZE) {
        while (p1.name.length() > SIZE) {
            cout << "Vous ne pouvez pas rentrer un pseudo de plus de "<< SIZE <<" charactere" << endl;
            cout << "Rentrez a nouveau le nom du premier joueur svp" << endl;
            cin >> p1.name;
        }
    }
    cout << "Rentrer le nom du deuxieme joueur" << endl;
    cin >> p2.name;
    if (p2.name.length() > SIZE) {
        while (p2.name.length() > SIZE) {
            cout << "Vous ne pouvez pas rentrer un pseudo de plus de "<< SIZE <<" charactere" << endl;
            cout << "Rentrez a nouveau le nom du premier joueur svp" << endl;
            cin >> p2.name;
        }
    }

    centerName(p1.name);
    centerName(p2.name);
    cout << endl;

    albetGrid();
    cout << endl;

    //boucle pour faire les grilles de jeu
    for (int i = 1; i < SIZE - 1; i++) {
        // Player1 grid
        cout << i << ' ';
        if (i < 10) {
            cout << ' ';
        }

        for (int j = 1; j < SIZE - 1; j++) {
            //verify if there is a ship
            if (p1.grid[i][j].ship != NONE) {
                cout << (int) p1.grid[i][j].ship << ' ';
            }
            else{
                cout << (char) p1.grid[i][j].state << ' ';
            }}



        // Player2 grid
        cout << "  " << i << ' ';
        if (i < 10) {
            cout << ' ';
        } //espace pour alligner

        for (int j = 1; j < SIZE - 1; j++) {
            cout << (char) p2.grid[i][j].state << ' ';
        }

        cout << endl;


    }
    //if linux or mac os is used clear the terminal and wait for a key press
#if defined(__linux__) || defined(__APPLE__)
    system("read -n 1 -s -p \"Press any key to continue...\"");
    system("clear");
    //if windows is used clear the terminal and wait for a key press
#elif defined(_WIN32) || defined(_WIN64)
    system("pause");
    system("cls");
#endif

}

