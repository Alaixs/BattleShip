//#v0.4.6
#include <iostream>
#include <random>
#include <fstream>
#include <windows.h>
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
    cout << "    ";
    for (int j=1; j <= 2 ; j++)
    {
        for(int i= 0; i < SIZE_GRID-2 ; i++)
        {
            cout << albet[i] << " ";
        }
        cout << "     ";
    }
}

void checkNameLength(string playerName)
{
        //check if the name of the player is not over SIZE_GRID characters
         while (playerName.length() > SIZE_GRID || playerName == "")
    {
        cout << "Vous ne pouvez pas rentrer un pseudo vide ou de plus de "<< SIZE_GRID <<" charactere" << endl;
        cout << "Rentrez a nouveau le nom du premier joueur svp" << endl;
        cin >> playerName;
    }

}

void centerName(string p1name, string p2name)
//create a function to center the name of the player and put player 1 in blue
{
    int p1nameLength = p1name.length();
    int p2nameLength = p2name.length();
    int p1space = (SIZE_GRID*2 - p1nameLength)/2;
    int p2space = (SIZE_GRID*2 - p2nameLength)/2;
    //center the name of the player 1
    for (int i = 0; i < p1space+1; i++)
    {
        cout << " ";
    }
    //print the name of the player 1 in blue
    cout << p1name;
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
     cout << p2name;
}

void initializeGrid(Cell aGrid[][SIZE_GRID])
{
    for(int i=0; i < SIZE_GRID; i++)
    {
        for(int j=0; j < SIZE_GRID; j++)
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

void styleGrid()
{
cout << "  ╭";
for (int i = 3; i < SIZE_GRID*2; i++)

    {
        cout << "─";
    }
    cout << "╮";
    cout << "  ";
    cout << "╭";
    for (int i = 3; i < SIZE_GRID*2; i++)
    {
        cout << "─";
    }
    cout << "╮";
}

void styleGridBottom()
{
    cout << "  ╰";
    for (int i = 3; i < SIZE_GRID*2; i++)
    {
        cout << "─";
    }
    cout << "╯";
    cout << "  ";
    cout << "╰";
    for (int i = 3; i < SIZE_GRID*2; i++)
    {
        cout << "─";
    }
    cout << "╯";

}

void displayGrid(Player & aPlayer, Player & anOpponent)
{
    SetConsoleOutputCP(CP_UTF8);
    centerName(aPlayer.name, anOpponent.name);
    cout << endl;
    albetGrid();
    cout << endl;
    styleGrid();
    cout << endl;
    //loop to display the grid
    for (int i = 1; i < SIZE_GRID - 1; i++) {
        // PLayer grid
        if (i < 10) {
    cout << ' ' ;
        }
        cout << i  << "│ ";

        for (int j = 1; j < SIZE_GRID - 1; j++) {
            //verify if there is a ship and print it
            if (aPlayer.grid[i][j].ship != NONE) {
                cout << (int) aPlayer.grid[i][j].ship << ' ';
            }
            else{
                //else display the state of the cell
                cout << (char) aPlayer.grid[i][j].state << ' ';
            }}
            cout << "│";


        // anOpponent grids
        if (i < 10) {
    cout << ' ' ;
        }
        cout << i  << "│ ";
        //show only the state of the cell and not the ship
        for (int j = 1; j < SIZE_GRID - 1; j++) {
                cout << (char) anOpponent.grid[i][j].state << ' ';
        }
        cout << "│";
        cout << endl;

    }
    styleGridBottom();
    cout << endl;
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

bool placeShip(Cell grid[][SIZE_GRID], Placement place, Ship ship)

{

    //check if the ship is placed horizontally or vertically
    if (place.dir == 'H')
    {
        int colCoordi = letterToNumber(place.coordi.col);
        //check if the ship is placed in the grid
        if (colCoordi + ship > SIZE_GRID - 1)
        {
            return false;
        }
        //check if there is no ship in the way and around the ship
        for (int iRow = place.coordi.row - 1; iRow < place.coordi.row + 1 + ship; iRow++)
        {
            for (int iCol = colCoordi - 1; iCol < colCoordi + 1 + ship; iCol++)
            {
                if (grid[iRow][iCol].ship != NONE)
                {
                    return false;
                }
            }
        }
        //place the ship
        for (int iCol = colCoordi; iCol < colCoordi + ship; iCol++)
        {
            grid[place.coordi.row][iCol].ship = ship;
        }

        }
    else if (place.dir == 'V')
    {
        int colCoordi = letterToNumber(place.coordi.col);
        //check if the ship is placed in the grid
        if (place.coordi.row + ship - 1 > SIZE_GRID - 2)
        {
            return false;
        }
        //check if there is no ship in the way and around the ship
        for (int iRow = place.coordi.row - 1; iRow < place.coordi.row + ship + 1; iRow++)
        {
            for (int iCol = colCoordi-1; iCol < colCoordi + ship ; iCol++)
            {
                if (grid[iRow][iCol].ship != NONE)
                {
                    return false;
                }
            }
        }
        //place the ship
        for (int iRow = place.coordi.row; iRow < place.coordi.row + ship; iRow++)
        {
            grid[iRow][colCoordi].ship = ship;
        }
    }
    else
    {
        return false;
    }
    return true;
}

void askPlayerToPlace(Player & aPlayer, Player & anOpponent)
{
    string place, userChoice, shipName[5] = {"CARRIER","CRUISER","DESTROYER","SUBMARINE","TORPEDO"};
    Ship boat[5] = {CARRIER, CRUISER, DESTROYER, SUBMARINE, TORPEDO};
    Coordinate coordi;
    Placement placement;
    bool state = false;
    //adk if the player want to place the ship manually
    cout << aPlayer.name << ", it's your turn to place your ships !" << endl;
    cout << "Do you want to place your ships manually? (Y/N)" << endl;
    cin >> userChoice;
    //if the player want to place the ship randomly call function randomPlacement
    if (userChoice == "N" || userChoice == "n")
    {
        cout << "Here are your randomly placed boats" << endl;
        randomPlacement(aPlayer);
        displayGrid(aPlayer, anOpponent);
        cout << "If this placement does not suit you, write R otherwise write anything else" << endl;
        cin >> userChoice;
        while (userChoice == "R" || userChoice == "r")
        {
            clearScreen();
            initializeGrid(aPlayer.grid);
            randomPlacement(aPlayer);
            displayGrid(aPlayer, anOpponent);
            cout << "If this placement does not suit you, write R otherwise write anything else" << endl;
            cin >> userChoice;
        }
        clearScreen();
    }
    else{

    //boucle pour placer les navires
    for (int i = 0; i < NBSHIPS; i++)
    {
            displayGrid(aPlayer, anOpponent);
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
            displayGrid(aPlayer, anOpponent);
            clearScreen();
            }
        }
}

bool alreadyShot(Cell aGrid[][SIZE_GRID], Coordinate someCoordi)
{
    //check if the cell has already been shot
    if (aGrid[someCoordi.row][letterToNumber(someCoordi.col)].state == HIT || aGrid[someCoordi.row][letterToNumber(someCoordi.col)].state == MISS || aGrid[someCoordi.row][letterToNumber(someCoordi.col)].state == SINK)
    {
        return true;
    }
        return false;
}

bool hitOrMiss(Cell aGrid[][SIZE_GRID], Coordinate someCoordi)
{
    bool isShooted = alreadyShot(aGrid ,someCoordi);
    if (!isShooted)
    {
        if (aGrid[someCoordi.row][someCoordi.col-64].ship)
        {
            aGrid[someCoordi.row][someCoordi.col-64].state = HIT;
            isBoatSank(aGrid, someCoordi.row, someCoordi.col-64);
            return true;
        }
        else {
            aGrid[someCoordi.row][someCoordi.col-64].state = MISS;
            return false;
        }
    }
    return false;
}


void askPlayerToShot(Player& aPlayer, Player& anOpponent)
{
    string place;
    Coordinate coordi;
    ofstream myfile;
    myfile.open ("Attemps.txt");

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
                    myfile << aPlayer.name << " shot at " << place << " and hit !" << endl;
                    cout << "Hit!" << endl;
                    aPlayer.score++;
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
         myfile.close();
        clearScreen();

}

void generateNumber(int& someNumber)
{
    const int MIN=1, MAX=SIZE_GRID-2;
     random_device rd;
     default_random_engine eng(rd());
     uniform_int_distribution<int> distr(MIN, MAX);
     someNumber= distr(eng);
}

void randomPlacement(Player& aPlayer)
{
    Placement placement;
    bool valid = false;
    int colcoordi;
    Ship boat[5] = {CARRIER, CRUISER, DESTROYER, SUBMARINE, TORPEDO};

//random placement of the ships with char

    for (int i = 0; i < NBSHIPS ; i++)
    {

        do {
            valid = false;
            generateNumber(placement.coordi.row);
            generateNumber(colcoordi);
            colcoordi += 64;
            placement.coordi.col = colcoordi;
            if (placement.coordi.row % 2 == 0)
            {
                placement.dir = 'H';
            }
            else
            {
                placement.dir = 'V';
            }
            //check if the ship is valid and place it
            if (placeShip(aPlayer.grid, placement, boat[i]))
            {
                valid = true;
            }
        } while (!valid);
}

}
bool isBoatSank(Cell aGrid[][SIZE_GRID], int aRow, int aCol)
{
    for (int i=aRow-1; i<aRow+2; i++)
        for (int j=aCol-1; j<aCol+2; j++)
            if (aGrid[i][j].ship != NONE)
            {
                if (i != aRow && j == aCol)
                {
                    while (aGrid[aRow-1][aCol].ship)
                        aRow--;
                    for (int i=0; i<aGrid[aRow][aCol].ship; i++)
                        if (aGrid[aRow+i][aCol].state != HIT)
                            return false;
                    for (int i=0; i<aGrid[aRow][aCol].ship; i++)
                        aGrid[aRow+i][aCol].state = SINK;
                    return true;
                }
                else if (i == aRow && j != aCol)
                {
                    while (aGrid[aRow][aCol-1].ship)
                        aCol--;
                    for (int i=0; i<aGrid[aRow][aCol].ship; i++)
                        if (aGrid[aRow][aCol+i].state != HIT)
                            return false;
                    for (int i=0; i<aGrid[aRow][aCol].ship; i++)
                        aGrid[aRow][aCol+i].state = SINK;
                    return true;
                }
            }
}

void iaShot(Player& aPlayer, Player& anOpponent)
{
bool wellShot = false;
Coordinate coordi;
string place;
int nb;
char letter;

do
{
    generateNumber(nb);
    letter = nb+64;
    place[0] = letter;
    generateNumber(nb);
    place[1] = nb;

        if (checkCoordinate(place, coordi))
        {
            //check if the cell has already been shot
            if (alreadyShot(anOpponent.grid, coordi))
            {
                wellShot = false;
            }
            else
            {
                //check if the shot is a hit or a miss
                if (hitOrMiss(anOpponent.grid, coordi))
                {
                    cout << "The computer Hit!" << endl;
                    aPlayer.score++;
                    wellShot = true;
                }
                else
                {
                    cout << "The computer Miss!" << endl;
                    wellShot = true;
                }
            }
            wellShot = false;
        }
        
    } while (wellShot);
}