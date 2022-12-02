//#v0.4
#include <iostream>
#include <random>
#include "typeDef.h"
#include "functions.h"
using namespace std;

void titleGame()
{
    cout << R"(
 
                     BATTLESHIP                 |__            ©
                                                |\/
                                                ---
                                                / | [
                                        !  	| |||
                                        _/| 	_/|-++'
                                    +  +--|	|--|--|_ |-
                                { /|__|  |/\__|  |--- |||__/
                                +---------------___[}-_===_.'____            	/\
                            ____`-' ||___-{]_| _[}-  | 	|_[___\==--       	\/   _
             __..._____--==/___]_|__|_____________________________[___\==--____,------' .7
            |                                                                	BB-61/
             \_________________________________________________________________________|
            )" << '\n'
 
          << endl << endl;
}

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
        //check if the name of the player is not over SIZE characters
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
    cout << "\e[1;34m" << p1name << "\e[0m";
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
     cout << "\033[1;31m" << p2name << "\033[0m";
}

void initializeGrid(Cell aGrid[][SIZE])
{
    for(int i=0; i < SIZE; i++)
    {
        for(int j=0; j < SIZE; j++)
        {
            //initialize the grid to NONE and UNSHOT
            aGrid[i][j].ship = NONE;
            aGrid[i][j].state = UNSHOT;
        }
    }
}

void clearScreen()
{
    //If linux or macOS is used, use the command "clear" and "read" to clear the screen
#if defined(__linux__) || defined(__APPLE__)
    system("read -n 1 -s -p \"Press any key to continue...\"");
    system("clear");
    //else if windows is used clear the terminal and wait for a key press
#elif defined(_WIN32) || defined(_WIN64)
    system("pause");
    system("cls");
#endif
}

void displayGrid(Player & aPlayer, Player & anOpponent)
{
    albetGrid();
    cout << endl;
    //loop to display the grid
    for (int i = 1; i < SIZE - 1; i++) {
        // PLayer grid
        cout << i << ' ';
        if (i < 10) {
            cout << ' ';
        }

        for (int j = 1; j < SIZE - 1; j++) {
            //verify if there is a ship and print it
            if (aPlayer.grid[i][j].ship != NONE) {
                cout << (int) aPlayer.grid[i][j].ship << ' ';
            }
            else{
                //else display the state of the cell
                cout << (char) aPlayer.grid[i][j].state << ' ';
            }}

        // anOpponent grids
        cout << "  " << i << ' ';
        if (i < 10) {
            cout << ' ';
        } 
        //show only the state of the cell and not the ship
        for (int j = 1; j < SIZE - 1; j++) {
                cout << (char) anOpponent.grid[i][j].state << ' ';
        }
        cout << endl;
    }
}

int letterToNumber(char letter)
{
    //convert the letter to a number
    return (int) letter - 64;
}

bool checkCoordinate(string aPlace, Coordinate& someCoordi)
{
    //convert the letter in uppercase
    aPlace[0] = toupper(aPlace[0]);
//check if aPlace input is a letter for [0] and number for [1] and [2]
if (aPlace.length() > 3 || aPlace.length() < 2 || aPlace[0] < 'A' || aPlace[0] > 'Z' || aPlace[1] <= '0'  || aPlace[1] > '9')
{
    return false;
}
else
{
    //if the test is ok, convert the letter to a number and put it in the coordinate
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
    string place, userChoice, shipName[5] = {"CARRIER","CRUISER","DESTROYER","SUBMARINE","TORPEDO"};
    Ship boat[5] = {CARRIER, CRUISER, DESTROYER, SUBMARINE, TORPEDO};
    Coordinate coordi;
    Placement placement;
    //boucle pour placer les navires
    for (int i = 0; i < NBSHIPS; i++)
    {
            //ask the player to place a ship
            displayGrid(aPlayer, anOpponent);
            cout << "Player " << aPlayer.name << ", do you want to place your ship or made it random? (P/R)" << endl;
            cin >> userChoice;
            while (userChoice == "R" || userChoice == "r")
                    {
                        randomPlacement(aPlayer);
                        displayGrid(aPlayer, anOpponent);
                        cout << "Player " << aPlayer.name << ", your ship is placed randomly, if you want continue press Y or if you want replace randomly press R" << endl;
                        cin >> userChoice;
                    }
               if (userChoice == "p" || userChoice == "P")
            cout << "Player " << aPlayer.name << ", place your " << shipName[i] << " cells ship" << endl;
            cout << "Enter the coordinate and the direction (ex: A1): " <<endl;
            cin >> place;
            cout << "Enter the direction (H or V): ";
            cin >> placement.dir;
            placement.dir = toupper(placement.dir);
            int nbRow = stoi(place.substr(1, place.length()));
            placement.coordi.col = place[0];
            placement.coordi.row = nbRow;
            //check if the ship is valid and place it
            if (!checkCoordinate(place, coordi) || !placeShip(aPlayer.grid, placement, boat[i]))
            {
                while (!checkCoordinate(place, coordi) || !placeShip(aPlayer.grid, placement, boat[i]))
                {
                    cout << "Invalid placement, please enter a valid placement: ";
                    cin >> place;
                    cout << "Enter the direction (H or V): ";
                    cin >> placement.dir;
                    placement.dir = toupper(placement.dir);
                    int nbRow = stoi(place.substr(1, place.length()));
                    placement.coordi.col = place[0];
                    placement.coordi.row = nbRow;
                }

            }
                
            

                placeShip(aPlayer.grid, placement, boat[i]);
        //display the grid
        clearScreen();
        }
        for (int i = 0; i < NBSHIPS; i++)
    {
        {//dont show the aplayer grid to the aplayer


            //ask the player to place a ship
            //when an opponent is choosing the placement of the ships hide the grid of aPlayer
            displayGrid(anOpponent, aPlayer);
            cout << "Player " << anOpponent.name << ", place your " << shipName[i] << " cells ship" << endl;
            cout << "Enter the coordinate and the direction (ex: A1): " <<endl;
            cin >> place;
            cout << "Enter the direction (H or V): ";
            cin >> placement.dir;
            placement.dir = toupper(placement.dir);
            int nbRow = stoi(place.substr(1, place.length()));
            placement.coordi.col = place[0];
            placement.coordi.row = nbRow;
            //check if the ship is valid and place it

                while (!placeShip(anOpponent.grid, placement, boat[i]) || !checkCoordinate(place, coordi))
                {
                    cout << "Invalid placement, please enter a valid placement: ";
                    cin >> place;
                    cout << "Enter the direction (H or V): ";
                    cin >> placement.dir;
                    placement.dir = toupper(placement.dir);
                    int nbRow = stoi(place.substr(1, place.length()));
                    placement.coordi.col = place[0];
                    placement.coordi.row = nbRow;
                }


                placeShip(anOpponent.grid, placement, boat[i]);
        //display the grid
        clearScreen();
    }
}
}

bool alreadyShot(Cell aGrid[][SIZE], Coordinate someCoordi)
{
    //check if the cell has already been shot
    if (aGrid[someCoordi.row][letterToNumber(someCoordi.col)].state == HIT || aGrid[someCoordi.row][letterToNumber(someCoordi.col)].state == MISS || aGrid[someCoordi.row][letterToNumber(someCoordi.col)].state == SINK)
    {
        return true;
    }
        return false;
}

bool hitOrMiss(Cell aGrid[][SIZE], Coordinate someCoordi)
{
    //check if the cell has a ship
    if (aGrid[someCoordi.row][letterToNumber(someCoordi.col)].ship != NONE)
    {
        //check if the ship is sunk
        aGrid[someCoordi.row][letterToNumber(someCoordi.col)].state = HIT;
        return true;
    }
    else
    {   //else the cell is a miss
        aGrid[someCoordi.row][letterToNumber(someCoordi.col)].state = MISS;
        return false;
    }
}

void askPlayerToShot(Player& aPlayer, Player& anOpponent)
{
    string place;
    Coordinate coordi;

        displayGrid(aPlayer, anOpponent);
        //ask the player to shoot
        cout << "Player " << aPlayer.name << ", enter the coordinate of the cell you want to shoot (ex: A1): " <<endl;
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
            }
        }
        else
        {
            cout << "Error: the coordinate is not valid" << endl;
        }
        clearScreen();

}

void generateNumber(int& someNumber)
{
    const int MAX = SIZE - 'A', MIN = 0;
    random_device rd;
    default_random_engine eng(rd());
    uniform_int_distribution<char> distr(MIN, MAX);
    someNumber = distr(eng);

}

void randomPlacement(Player& aPlayer)
{
    Placement placement;
    string place;
    Coordinate coordi;
    Ship boat;
    bool valid = false;
    int direction, colcoordi;
    

//random placement of the ships with char

    for (int i = 1; i < NBSHIPS; i++)
    {
        do {
        boat = static_cast<Ship>(i);
            //generate a random coordinate
            //placement col is a char
            generateNumber(coordi.row);
            generateNumber(colcoordi);
            colcoordi += 64; 
            placement.coordi.col = colcoordi;
            //generate a random direction
            generateNumber(direction);
            if (coordi.row % 2 == 0)
            {
                placement.dir = 'H';
            }
            else
            {
                placement.dir = 'V';
            }
            //check if the ship is valid and place it
            if (checkCoordinate(place, coordi) && placeShip(aPlayer.grid, placement, boat))
            {
                valid = true;
            }
        } while (!valid);
            displayGrid(aPlayer, aPlayer);
             
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
    for (int iRow = 0; iRow < SIZE ; iRow++)
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
