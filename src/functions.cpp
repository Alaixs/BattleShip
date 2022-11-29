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

int letterToNumber(char letter)
{
    return (int) letter - 64;
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
        int colCoordi = letterToNumber(place.coordi.col);
        cout << "colCoordi = " << colCoordi << endl;
        //check if the ship is placed in the grid
        if (colCoordi + ship > SIZE - 1)
        {
            cout << "Check if the ship is placed in the grid: " <<colCoordi + ship + 1 << "false!" << endl;
            return false;
        }
        //check if there is no ship in the way and around the ship
        for (int iRow = place.coordi.row - 1; iRow < place.coordi.row + 1 + ship; iRow++)
        {
            for (int iCol = colCoordi - 1; iCol < colCoordi + 1 + ship; iCol++)
            {
                if (grid[iRow][iCol].ship != NONE)
                {
                    cout << "Check if there is no ship in the way and around the ship: " << "false!" << endl;
                    return false;
                }
            }
        }
        //place the ship
        for (int iCol = colCoordi; iCol < colCoordi + ship; iCol++)
        {
            cout << "H Placing ship..." <<endl;
            grid[place.coordi.row][iCol].ship = ship;
        }

        }
    else if (place.dir == 'V')
    {
        int colCoordi = letterToNumber(place.coordi.col);
        //check if the ship is placed in the grid
        if (place.coordi.row + ship - 1 > SIZE - 2)
        {
            cout << "V Check if the ship is placed in the grid:" << endl;
            return false;
        }
        //check if there is no ship in the way and around the ship
        for (int iRow = place.coordi.row - 1; iRow < place.coordi.row + ship + 1; iRow++)
        {
            for (int iCol = colCoordi-1; iCol < colCoordi + ship ; iCol++)
            {
                if (grid[iRow][iCol].ship != NONE)
                {
                    cout << grid[iRow][iCol].ship << endl;
                    return false;
                }
            }
        }
        //place the ship
        for (int iRow = place.coordi.row; iRow < place.coordi.row + ship; iRow++)
        {
            cout << "V Placing ship..." <<endl;
            grid[iRow][colCoordi].ship = ship;
        }
    }
    else
    {
        return false;
        cout << "Error: direction not valid" << endl;
    }
    return true;
}

void askPlayerToPlace(Player & aPlayer, Player & anOpponent)
{
    string place;
    Ship boat;
    Coordinate coordi;
    Placement placement;
    bool valid = false;
    //boucle pour placer les navires
    for (int i = 0; i < NBSHIPS; i++)
    {
        do
        {
            //ask the player to place a ship
            cout << "Player " << aPlayer.name << ", place your " << ships[i] << " cells ship" << endl;
            cout << "Enter the coordinate and the direction (ex: A1H): ";
            cin >> place;
            boat = (Ship) i;
            //check if the coordinate is valid
            if (checkCoordinate(place, coordi))
            {
                placement.coordi = coordi;
                placement.dir = place[2];
                //check if the ship can be placed
                if (placeShip(aPlayer.grid, placement, boat))
                {
                    valid = true;
                }
                else
                {
                    cout << "Error: the ship can't be placed" << endl;
                }
            }
            else
            {
                cout << "Error: the coordinate is not valid" << endl;
            }
        } while (!valid);
        //display the grid
        displayGrid(aPlayer, anOpponent);
        valid = false;
    }
}

bool alreadyShot(Cell aGrid[][SIZE], Coordinate someCoordi)
{
    if (aGrid[someCoordi.row][letterToNumber(someCoordi.col)].state == HIT || aGrid[someCoordi.row][letterToNumber(someCoordi.col)].state == MISS || aGrid[someCoordi.row][letterToNumber(someCoordi.col)].state == SINK)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool hitOrMiss(Cell aGrid[][SIZE], Coordinate someCoordi)
{
    if (aGrid[someCoordi.row][letterToNumber(someCoordi.col)].ship != NONE)
    {
        aGrid[someCoordi.row][letterToNumber(someCoordi.col)].state = HIT;
        return true;
    }
    else
    {
        aGrid[someCoordi.row][letterToNumber(someCoordi.col)].state = MISS;
        return false;
    }
}

void askPlayerToShoot(Player & aPlayer, Player & anOpponent)
{
    string place;
    Coordinate coordi;
    bool valid = false;
    do
    {
        //ask the player to shoot
        cout << "Player " << aPlayer.name << ", enter the coordinate of the cell you want to shoot (ex: A1): ";
        cin >> place;
        //check if the coordinate is valid
        if (checkCoordinate(place, coordi))
        {
            //check if the cell has already been shot
            if (alreadyShot(anOpponent.grid, coordi))
            {
                cout << "Error: the cell has already been shot" << endl;
            }
            else
            {
                //check if the shot is a hit or a miss
                if (hitOrMiss(anOpponent.grid, coordi))
                {
                    cout << "Hit!" << endl;
                }
                else
                {
                    cout << "Miss!" << endl;
                }
                valid = true;
            }
        }
        else
        {
            cout << "Error: the coordinate is not valid" << endl;
        }
    } while (!valid);
}

void randomPlacement(Player& aPlayer)
{
    Placement placement;
    Ship boat;
    bool valid = false;
    //boucle pour placer les navires
    for (int i = 0; i < NBSHIPS; i++)
    {
        do
        {
            boat = (Ship) i;
            //random coordinate
            placement.coordi.row = rand() % SIZE;
            placement.coordi.col = rand() % SIZE;
            //random direction
            if (rand() % 2 == 0)
            {
                placement.dir = 'H';
            }
            else
            {
                placement.dir = 'V';
            }
            //check if the ship can be placed
            if (placeShip(aPlayer.grid, placement, boat))
            {
                valid = true;
            }
        } while (!valid);
        valid = false;
    }
}

/*
 * \brief détermine si un bateau est coulé (toutes ses cases sont HIT)
 * \param aGrid : la grille
 * \param aRow : la ligne
 * \param aCol : la colonne
 */
bool isBoatSank(Cell aGrid[][SIZE], int aRow, int aCol)
{
    bool sank = true;
    Ship boat = aGrid[aRow][aCol].ship;
    //check if the ship is sank
    for (int iRow = 0; iRow < SIZE; iRow++)
    {
        for (int iCol = 0; iCol < SIZE; iCol++)
        {
            if (aGrid[iRow][iCol].ship == boat && aGrid[iRow][iCol].state != HIT)
            {
                sank = false;
            }
        }
    }
    return sank;
}

/*
 * \brief détermine si un joueur a gagné (tous ses bateaux sont coulés)
 * \param aPlayer : le joueur
 * \return true si le joueur a gagné
 */
bool isWinner(Player& aPlayer)
{
    bool winner = true;
    //check if the player has won
    for (int iRow = 0; iRow < SIZE; iRow++)
    {
        for (int iCol = 0; iCol < SIZE; iCol++)
        {
            if (aGrid[iRow][iCol].ship != NONE && aGrid[iRow][iCol].state != SINK)
            {
                winner = false;
            }
        }
    }
    return winner;
}