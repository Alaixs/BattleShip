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

void checkNameLength(string playerName)
{
         while (playerName.length() > SIZE || playerName == "")
    {
        cout << "Vous ne pouvez pas rentrer un pseudo vide ou de plus de "<< SIZE <<" charactere" << endl;
        cout << "Rentrez a nouveau le nom du premier joueur svp" << endl;
        cin >> playerName;
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

void displayGrid(Player & aPlayer, Player & anOpponent)
{
    albetGrid();
    cout << endl;
    //boucle pour faire les grilles de jeu
    for (int i = 1; i < SIZE - 1; i++) {
        // Player1 grids
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


bool checkCoordinate(string aPlace, Coordinate & someCoordi)
{
    //convert the letter in uppercase
    aPlace[0] = toupper(aPlace[0]);

if (aPlace.length() > 3 || aPlace.length() < 2 || aPlace[0] < 'A' || aPlace[0] > 'Z' || aPlace[1] <= '0')
{
    return false;
}
else
{
    int nbRow = stoi(aPlace.substr(1, aPlace.length()));
    someCoordi.col = aPlace[0];
    someCoordi.row = nbRow;
    return true;

}
}

bool placeShip(Cell grid[][SIZE], Placement place, Ship ship)
{

    //check if the ship is placed horizontally or vertically
    if (place.dir == 'H')
    {
        //check if the ship is placed in the grid
        if (place.coordi.col + ship > 'Z')
        {
            return false;
        }
        //check if there is no ship in the way
        for (int i = 0; i < ship; i++)
        {
            if (grid[place.coordi.row][place.coordi.col].ship != NONE)
            {
                return false;
            }
        }
        //place the ship 
        for (int i = 0; i < ship; i++)
        {
            grid[place.coordi.row][place.coordi.col - 'A' + i].ship = ship;
        }
    }
    else if (place.dir == 'V')
    {
        //check if the ship is placed in the grid
        if (place.coordi.row + ship > SIZE)
        {
            return false;
        }
        //check if there is no ship in the way
        for (int i = 0; i < ship; i++)
        {
            if (grid[place.coordi.row + i][place.coordi.col - 'A'].ship != NONE)
            {
                return false;
            }
        }
        //place the ship 
        for (int i = 0; i < ship; i++)
        {
            grid[place.coordi.row + i][place.coordi.col - 'A'].ship = ship;
        }
    }
    else
    {
        return false;
    }
}