#include <iostream>
#include "typeDef.h"
#include "functions.h"
using namespace std;

void albetGrid()
{
    string albet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    cout << "   ";
    for (int j=1; j <= 2 ; j++)
    {
        for(int i= 0; i < SIZE-2 ; i++)
        {
            cout << albet[i] << " ";
        }
        cout << "     ";
    }
}

void centerName(string p1name, string p2name)
//create a function to center the name of the player and put player 1 in blue
{
    int p1nameLength = p1name.length();
    int p2nameLength = p2name.length();
    int p1space = (SIZE*2 - p1nameLength)/2;
    int p2space = (SIZE*2 - p2nameLength)/2;
    //center the name of the player 1
    for (int i = 0; i < p1space; i++)
    {
        cout << " ";
    }
    //print the name of the player 1 in blue
    cout << "\033[1;34m" << p1name << "\033[0m";
    //center the name of the player 2 (+1 for the space between the two grids)
    for (int i = 0; i < p1space+1; i++)
    {
        cout << " ";
    }
    for (int i = 0; i < p2space; i++)
    {
        cout << " ";
    }
    //if the name of the player 1 is odd, add a space
    if (p1nameLength % 2 != 0)
    {
        cout << " ";
    }
    //print the name of the player 2 in red
     cout << "\033[1;31m" << p2name<< "\033[0m";
}

void initializeGrid(Cell aGrid[][SIZE])
{
    for(int i=0; i < SIZE; i++)
    {
        for(int j=0; j < SIZE; j++)
        {
            aGrid[i][j].ship = NONE;
            aGrid[i][j].state = UNSHOT;
        }
    }
}

//create a function to display the grid with aPlayer and anOpponent

void clearScreen()
{
#if defined(__linux__) || defined(__APPLE__)
    system("read -n 1 -s -p \"Press any key to continue...\"");
    system("clear");
    //if windows is used clear the terminal and wait for a key press
#elif defined(_WIN32) || defined(_WIN64)
    system("pause");
    system("cls");
#endif
}

/*
 * \brief Affiche les grilles des deux joueurs
 * \param aPlayer : le joueur
 * \param anOpponent l'adversaire
 * \return void
 */
void displayGrid(Player & aPlayer, Player & anOpponent)
{
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
            if (aPlayer.grid[i][j].ship != NONE) {
                cout << (int) aPlayer.grid[i][j].ship << ' ';
            }
            else{
                cout << (char) aPlayer.grid[i][j].state << ' ';
            }}

        // Player2 grid
        cout << "  " << i << ' ';
        if (i < 10) {
            cout << ' ';
        } //espace pour alligner

        for (int j = 1; j < SIZE - 1; j++) {
            //verify if there is a ship
            if (anOpponent.grid[i][j].ship != NONE) {
                cout << (int) anOpponent.grid[i][j].ship << ' ';
            }
            else{
                cout << (char) anOpponent.grid[i][j].state << ' ';
            }
        }
        cout << endl;
    }
}
