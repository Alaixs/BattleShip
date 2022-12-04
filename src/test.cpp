#include <iostream>
#include "test.h"
#include "typeDef.h"
#include "functions.h"

using namespace std;

void test_structureDonnees()
{
    cout << "********* Start testing of enum Ship *********" << endl;
    int pass = 0;
    int failed = 0;
    Ship boat;
    boat = CARRIER;
    if (boat == 5)
    {
        cout << "PASS \t: CARRIER" << endl;
        pass++;
    }
    else
    {
        cout << "FAIL! \t: CARRIER" << "\n\tActual " << boat << "\n\texpected " << CARRIER << endl;
        failed++;
    }
    boat = CRUISER;
    if (boat == 4)
    {
        cout << "PASS \t: CRUISER" << endl;
        pass++;
    }
    else
    {
        cout << "FAIL! \t: CRUISER" << "\n\tActual " << boat << "\n\texpected " << CRUISER << endl;
        failed++;
    }
    boat = DESTROYER;
    if (boat == 3)
    {
        cout << "PASS \t: DESTROYER" << endl;
        pass++;
    }
    else
    {
        cout << "FAIL! \t: DESTROYER" << "\n\tActual " << boat << "\n\texpected " << DESTROYER << endl;
        failed++;
    }
    boat = SUBMARINE;
    if (boat == 3)
    {
        cout << "PASS \t: SUBMARINE" << endl;
        pass++;
    }
    else
    {
        cout << "FAIL! \t: SUBMARINE" << "\n\tActual " << boat << "\n\texpected " << SUBMARINE << endl;
        failed++;
    }
    boat = TORPEDO;
    if (boat == 2)
    {
        cout << "PASS \t: TORPEDO" << endl;
        pass++;
    }
    else
    {
        cout << "FAIL! \t: TORPEDO" << "\n\tActual " << boat << "\n\texpected " << TORPEDO << endl;
        failed++;
    }
    boat = NONE;
    if (boat == 0)
    {
        cout << "PASS \t: NONE" << endl;
        pass++;
    }
    else
    {
        cout << "FAIL! \t: NONE" << "\n\tActual " << boat << "\n\texpected " << NONE << endl;
        failed++;
    }
    cout << "Totals: " << pass << " passed, " << failed << " failed" << endl;
    cout << "********* Finished testing of enum Ship *********" << endl;

    cout << endl;
    pass = 0;
    failed = 0;
    cout << "********* Start testing of enum State *********" << endl;
    State st;
    st = HIT;
    if (st == 120)
    {
        cout << "PASS \t: HIT" << endl;
        pass++;
    }
    else
    {
        cout << "FAIL! \t: HIT" << "\n\tActual " << st << "\n\texpected " << HIT << endl;
        failed++;
    }
    st = SINK;
    if (st == 35)
    {
        cout << "PASS \t: SINK" << endl;
        pass++;
    }
    else
    {
        cout << "FAIL! \t: SINK" << "\n\tActual " << st << "\n\texpected " << SINK << endl;
        failed++;
    }
    st = MISS;
    if (st == 111)
    {
        cout << "PASS \t: MISS" << endl;
        pass++;
    }
    else
    {
        cout << "FAIL! \t: MISS" << "\n\tActual " << st << "\n\texpected " << MISS << endl;
        failed++;
    }
    st = UNSHOT;
    if (st == 126)
    {
        cout << "PASS \t: UNSHOT" << endl;
        pass++;
    }
    else
    {
        cout << "FAIL! \t: UNSHOT" << "\n\tActual " << st << "\n\texpected " << UNSHOT << endl;
        failed++;
    }
    cout << "Totals: " << pass << " passed, " << failed << " failed" << endl;
    cout << "********* Finished testing of enum State *********" << endl;

    cout << endl;
    pass = 0;
    failed = 0;
    cout << "********* Start testing of const SIZE *********" << endl;
    if (SIZE == 12)
    {
        cout << "PASS \t: SIZE" << endl;
        pass++;
    }
    else
    {
        cout << "FAIL! \t: SIZE" << "\n\tActual " << SIZE << "\n\texpected 12" << endl;
        failed++;
    }
    cout << "Totals: " << pass << " passed, " << failed << " failed" << endl;
    cout << "********* Finished testing of const SIZE *********" << endl;

    cout << endl;
    pass = 0;
    failed = 0;
    cout << "********* Start testing of const NBShip *********" << endl;
    if (NBSHIPS == 5)
    {
        cout << "PASS \t: NBShip" << endl;
        pass++;
    }
    else
    {
        cout << "FAIL! \t: NBShip" << "\n\tActual " << NBSHIPS << "\n\texpected 5" << endl;
        failed++;
    }
    cout << "Totals: " << pass << " passed, " << failed << " failed" << endl;
    cout << "********* Finished testing of const NBShip *********" << endl;

    cout << endl;
    pass = 0;
    failed = 0;
    cout << "********* Start testing of const NBCELLS *********" << endl;
    if (NBCELLS == 17)
    {
        cout << "PASS \t: NBCELLS" << endl;
        pass++;
    }
    else
    {
        cout << "FAIL! \t: NBCELLS" << "\n\tActual " << NBCELLS << "\n\texpected 17" << endl;
        failed++;
    }
    cout << "Totals: " << pass << " passed, " << failed << " failed" << endl;
    cout << "********* Finished testing of const NBCELLS *********" << endl;

    cout << endl;
    pass = 0;
    failed = 0;
    cout << "********* Start testing of const string Ship[NBShip] *********" << endl;
    if (ships[0] == "carrier")
    {
        cout << "PASS \t: carrier" << endl;
        pass++;
    }
    else
    {
        cout << "FAIL! \t: carrier" << "\n\tActual " << ships[0] << "\n\texpected carrier" << endl;
        failed++;
    }
    if (ships[1] == "cruiser")
    {
        cout << "PASS \t: cruiser" << endl;
        pass++;
    }
    else
    {
        cout << "FAIL! \t: cruiser" << "\n\tActual " << ships[1] << "\n\texpected cruiser" << endl;
        failed++;
    }
    if (ships[2] == "destroyer")
    {
        cout << "PASS \t: destroyer" << endl;
        pass++;
    }
    else
    {
        cout << "FAIL! \t: destroyer" << "\n\tActual " << ships[2] << "\n\texpected destroyer" << endl;
        failed++;
    }
    if (ships[3] == "submarine")
    {
        cout << "PASS \t: submarine" << endl;
        pass++;
    }
    else
    {
        cout << "FAIL! \t: submarine" << "\n\tActual " << ships[3] << "\n\texpected submarine" << endl;
        failed++;
    }
    if (ships[4] == "torpedo")
    {
        cout << "PASS \t: torpedo" << endl;
        pass++;
    }
    else
    {
        cout << "FAIL! \t: torpedo" << "\n\tActual " << ships[4] << "\n\texpected torpedo" << endl;
        failed++;
    }
    cout << "Totals: " << pass << " passed, " << failed << " failed" << endl;
    cout << "********* Finished testing of const string ships[NBShip] *********" << endl;
}

void test_checkCoordinate()
{
    int pass = 0;
    int failed = 0;
    string input;
    Coordinate output;
    cout << "********* Start testing of checkCoordinate *********" << endl;
    // b7 true B7
    input = "b7";
    if (checkCoordinate(input, output) == true)
    {
        if (output.col == 'B' and output.row == 7)
        {
            cout << "PASS \t: " << input << endl;
            pass++;
        }
        else
        {
            cout << "FAIL! \t: " << input << "\n\tActual " << output.col << output.row << "\n\texpected B7" << endl;
            failed++;
        }
    }
    else
    {
        cout << "FAIL! \t: " << input << "\n\tActual " << output.col << output.row << "\n\texpected B7" << endl;
        failed++;
    }
    // a1 true A1
    input = "a1";
    if (checkCoordinate(input, output) == true)
    {
        if (output.col == 'A' and output.row == 1)
        {
            cout << "PASS \t: " << input << endl;
            pass++;
        }
        else
        {
            cout << "FAIL! \t: " << input << "\n\tActual " << output.col << output.row << "\n\texpected A1" << endl;
            failed++;
        }
    }
    else
    {
        cout << "FAIL! \t: " << input << "\n\tActual " << output.col << output.row << "\n\texpected A1" << endl;
        failed++;
    }
    // j10 true J10
    input = "j10";
    if (checkCoordinate(input, output) == true)
    {
        if (output.col == 'J' and output.row == 10)
        {
            cout << "PASS \t: " << input << endl;
            pass++;
        }
        else
        {
            cout << "FAIL! \t: " << input << "\n\tActual " << output.col << output.row << "\n\texpected J10" << endl;
            failed++;
        }
    }
    else
    {
        cout << "FAIL! \t: " << input << "\n\tActual " << output.col << output.row << "\n\texpected J10" << endl;
        failed++;
    }
    // B7 true B7
    input = "B7";
    if (checkCoordinate(input, output) == true)
    {
        if (output.col == 'B' and output.row == 7)
        {
            cout << "PASS \t: " << input << endl;
            pass++;
        }
        else
        {
            cout << "FAIL! \t: " << input << "\n\tActual " << output.col << output.row << "\n\texpected B7" << endl;
            failed++;
        }
    }
    else
    {
        cout << "FAIL! \t: " << input << "\n\tActual " << output.col << output.row << "\n\texpected B7" << endl;
        failed++;
    }
    // A1 true A1
    input = "A1";
    if (checkCoordinate(input, output) == true)
    {
        if (output.col == 'A' and output.row == 1)
        {
            cout << "PASS \t: " << input << endl;
            pass++;
        }
        else
        {
            cout << "FAIL! \t: " << input << "\n\tActual " << output.col << output.row << "\n\texpected A1" << endl;
            failed++;
        }
    }
    else
    {
        cout << "FAIL! \t: " << input << "\n\tActual " << output.col << output.row << "\n\texpected A1" << endl;
        failed++;
    }
    // J10 true J10
    input = "J10";
    if (checkCoordinate(input, output) == true)
    {
        if (output.col == 'J' and output.row == 10)
        {
            cout << "PASS \t: " << input << endl;
            pass++;
        }
        else
        {
            cout << "FAIL! \t: " << input << "\n\tActual " << output.col << output.row << "\n\texpected J10" << endl;
            failed++;
        }
    }
    else
    {
        cout << "FAIL! \t: " << input << "\n\tActual " << output.col << output.row << "\n\texpected J10" << endl;
        failed++;
    }
    // 10J false
    input = "10J";
    if (checkCoordinate(input, output) == false)
    {
        cout << "PASS \t: " << input << endl;
        pass++;
    }
    else
    {
        cout << "FAIL! \t: " << input << "\n\tActual true \n\texpected false" << endl;
            failed++;
    }
    // b 7 false
    input = "b 7";
    if (checkCoordinate(input, output) == false)
    {
        cout << "PASS \t: " << input << endl;
        pass++;
    }
    else
    {
        cout << "FAIL! \t: " << input << "\n\tActual true \n\texpected false" << endl;
            failed++;
    }
    // bonjour false
    input = "bonjour";
    if (checkCoordinate(input, output) == false)
    {
        cout << "PASS \t: " << input << endl;
        pass++;
    }
    else
    {
        cout << "FAIL! \t: " << input << "\n\tActual true \n\texpected false" << endl;
            failed++;
    }
    // 120 false
    input = "120";
    if (checkCoordinate(input, output) == false)
    {
        cout << "PASS \t: " << input << endl;
        pass++;
    }
    else
    {
        cout << "FAIL! \t: " << input << "\n\tActual true \n\texpected false" << endl;
            failed++;
    }
    cout << "Totals: " << pass << " passed, " << failed << " failed" << endl;
    cout << "********* Finished testing of checkCoordinate *********" << endl;
}

void initGrid(Cell aGrid[][SIZE])
{
    for (int row = 0; row < SIZE; row++)
    {
        for (int column = 0; column < SIZE; column++)
        {
            aGrid[row][column].ship = NONE;
            aGrid[row][column].state = UNSHOT;
        }
    }
}

bool compareGrid(Cell aGrid1[][SIZE], Cell AGrid2[][SIZE])
{
    for (int i=0; i<SIZE; i++)
    {
        for (int j=0; j<SIZE; j++)
        {
            if (aGrid1[i][j].state != AGrid2[i][j].state or aGrid1[i][j].ship != AGrid2[i][j].ship)
            {
                return false;
            }
        }
    }
    return true;
}

void test_initializeGrid()
{
    int pass = 0;
    int failed = 0;
    Cell grid[SIZE][SIZE];
    Cell output[SIZE][SIZE];
    cout << "********* Start testing of initializeGrid *********" << endl;
    initializeGrid(grid);
    initGrid(output);
    if (compareGrid(grid, output))
    {
        cout << "PASS \t: Initialisation de la grille" << endl;
        pass++;
    }
    else
    {
        cout << "FAIL! \t: Initialisation de la grille" << endl;
        failed++;
    }
    cout << "Totals: " << pass << " passed, " << failed << " failed" << endl;
    cout << "********* Finished testing of initializeGrid *********" << endl;
}

void test_placeShip()
{
    int pass = 0;
    int failed = 0;
    Cell grid[SIZE][SIZE];
    Cell output[SIZE][SIZE];
    Placement position;
    Ship boat;
    cout << "********* Start testing of placeShip *********" << endl;
    // Saisie du bateau correcte H
    initGrid(grid);
    initGrid(output);
    position.coordi.col = 'B';
    position.coordi.row = 3;
    position.dir = 'H';
    boat = TORPEDO;
    output[3][2].ship = boat;
    output[3][3].ship = boat;
    placeShip(grid, position, boat);
    if (compareGrid(grid, output))
    {
        cout << "PASS \t: B3 TORPEDO H" << endl;
        pass++;
    }
    else
    {
        cout << "FAIL! \t: B3 TORPEDO H" << "\n\tActual " << grid[3][2].ship << grid[3][3].ship << grid[3][4].ship << "\n\texpected " << boat << boat << NONE << endl;
        failed++;
    }
    // Saisie du bateau correcte V
    initGrid(grid);
    initGrid(output);
    position.coordi.col = 'D';
    position.coordi.row = 5;
    position.dir = 'V';
    boat = SUBMARINE;
    output[5][4].ship = boat;
    output[6][4].ship = boat;
    output[7][4].ship = boat;
    placeShip(grid, position, boat);
    if (compareGrid(grid, output))
    {
        cout << "PASS \t: D5 SUBMARINE V" << endl;
        pass++;
    }
    else
    {
        cout << "FAIL! \t: D5 SUBMARINE V" << "\n\tActual " << grid[5][4].ship << grid[6][4].ship << grid[7][4].ship << grid[8][4].ship << "\n\texpected " << boat << boat << boat << NONE << endl;
        failed++;
    }
    // Saisie du bateau correcte
    initGrid(grid);
    initGrid(output);
    position.coordi.col = 'B';
    position.coordi.row = 3;
    position.dir = 'H';
    boat = TORPEDO;
    output[3][2].ship = boat;
    output[3][3].ship = boat;
    if (placeShip(grid, position, boat) == true)
    {
        if (compareGrid(grid, output))
        {
            cout << "PASS \t: B3 TORPEDO H" << endl;
            pass++;
        }
        else
        {
            cout << "FAIL! \t: B3 TORPEDO H" << "\n\tActual " << grid[3][2].ship << grid[3][3].ship << grid[3][4].ship << "\n\texpected " << boat << boat << NONE << endl;
            failed++;
        }
    }
    else
    {
        cout << "FAIL! \t: B3 TORPEDO H" << "\n\tActual false \n\texpected true " << endl;
        failed++;
    }
    // Saisie du bateau correcte bord H
    initGrid(grid);
    initGrid(output);
    position.coordi.col = 'A';
    position.coordi.row = 1;
    position.dir = 'H';
    boat = TORPEDO;
    output[1][1].ship = boat;
    output[1][2].ship = boat;
    if (placeShip(grid, position, boat) == true)
    {
        if (compareGrid(grid, output))
        {
            cout << "PASS \t: A1 TORPEDO H" << endl;
            pass++;
        }
        else
        {
            cout << "FAIL! \t: A1 TORPEDO H" << "\n\tActual " << grid[1][1].ship << grid[1][2].ship << grid[1][3].ship << "\n\texpected " << boat << boat << NONE << endl;
            failed++;
        }
    }
    else
    {
        cout << "FAIL! \t: A1 TORPEDO H" << "\n\tActual false \n\texpected true " << endl;
        failed++;
    }
    // Saisie du bateau correcte bord V
    initGrid(grid);
    initGrid(output);
    position.coordi.col = 'J';
    position.coordi.row = 9;
    position.dir = 'V';
    boat = TORPEDO;
    output[9][10].ship = boat;
    output[10][10].ship = boat;
    if (placeShip(grid, position, boat) == true)
    {
        if (compareGrid(grid, output))
        {
            cout << "PASS \t: J9 TORPEDO V" << endl;
            pass++;
        }
        else
        {
            cout << "FAIL! \t: J9 TORPEDO V" << "\n\tActual " << grid[9][10].ship << grid[10][10].ship << grid[11][10].ship << "\n\texpected " << boat << boat << NONE << endl;
            failed++;
        }
    }
    else
    {
        cout << "FAIL! \t: J9 TORPEDO V" << "\n\tActual false \n\texpected true " << endl;
        failed++;
    }
    // orientation fausse
    initGrid(grid);
    initGrid(output);
    position.coordi.col = 'J';
    position.coordi.row = 9;
    position.dir = 'R';
    boat = TORPEDO;
    if (placeShip(grid, position, boat) == false)
    {
        if (compareGrid(grid, output))
        {
            cout << "PASS \t: J9 TORPEDO R (orientation fausse)" << endl;
            pass++;
        }
        else
        {
            cout << "FAIL! \t: J9 TORPEDO R (orientation fausse)" << "\n\tActual " << grid[9][10].ship << grid[10][10].ship << grid[11][10].ship << "\n\texpected " << output[9][10].ship << output[10][10].ship << output[11][10].ship << endl;
            failed++;
        }
    }
    else
    {
        cout << "FAIL! \t: J9 TORPEDO R (orientation fausse)" << "\n\tActual true \n\texpected false " << endl;
        failed++;
    }
    // Débordement horizontal
    initGrid(grid);
    position.coordi.col = 'I';
    position.coordi.row = 8;
    position.dir = 'H';
    boat = SUBMARINE;
    if (placeShip(grid, position, boat) == false)
    {
        cout << "PASS \t: I8 SUBMARINE H (débordement H)" << endl;
        pass++;
    }
    else
    {
        cout << "FAIL! \t: I8 SUBMARINE H (débordement H)" << "\n\tActual true \n\texpected false " << endl;
        failed++;
    }
    // Débordement vertical
    initGrid(grid);
    position.coordi.col = 'E';
    position.coordi.row = 9;
    position.dir = 'V';
    boat = DESTROYER;
    if (placeShip(grid, position, boat) == false)
    {
        cout << "PASS \t: E9 DESTROYER V (débordement V)" << endl;
        pass++;
    }
    else
    {
        cout << "FAIL! \t: E9 DESTROYER V (débordement V)" << "\n\tActual true \n\texpected false " << endl;
        failed++;
    }
    // Chevauchement horizontal
    initGrid(grid);
    position.coordi.col = 'D';
    position.coordi.row = 5;
    position.dir = 'H';
    grid[6][5].ship = TORPEDO;
    boat = CRUISER;
    if (placeShip(grid, position, boat) == false)
    {
        cout << "PASS \t: D5 CRUISER H (chevauchement H)" << endl;
        pass++;
    }
    else
    {
        cout << "FAIL! \t: D5 CRUISER H (chevauchement H)" << "\n\tActual true \n\texpected false " << endl;
        failed++;
    }
    // Chevauchement vertical
    initGrid(grid);
    position.coordi.col = 'F';
    position.coordi.row = 4;
    position.dir = 'V';
    grid[4][6].ship = TORPEDO;
    boat = CARRIER;
    if (placeShip(grid, position, boat) == false)
    {
        cout << "PASS \t: F4 CARRIER V (chevauchement V)" << endl;
        pass++;
    }
    else
    {
        cout << "FAIL! \t: F4 CARRIER V (chevauchement V)" << "\n\tActual true \n\texpected false " << endl;
        failed++;
    }
    // Collé horizontal
    initGrid(grid);
    position.coordi.col = 'D';
    position.coordi.row = 5;
    position.dir = 'H';
    grid[6][6].ship = TORPEDO;
    boat = CRUISER;
    if (placeShip(grid, position, boat) == false)
    {
        cout << "PASS \t: D5 CRUISER H (collé H)" << endl;
        pass++;
    }
    else
    {
        cout << "FAIL! \t: D5 CRUISER H (collé H)" << "\n\tActual true \n\texpected false " << endl;
        failed++;
    }
    // Collé vertical
    initGrid(grid);
    position.coordi.col = 'F';
    position.coordi.row = 4;
    position.dir = 'V';
    grid[7][6].ship = TORPEDO;
    boat = CARRIER;
    if (placeShip(grid, position, boat) == false)
    {
        cout << "PASS \t: F4 CARRIER V (collé V)" << endl;
        pass++;
    }
    else
    {
        cout << "FAIL! \t: F4 CARRIER V (collé V)" << "\n\tActual true \n\texpected false " << endl;
        failed++;
    }
    // Collé diagonale
    initGrid(grid);
    position.coordi.col = 'H';
    position.coordi.row = 6;
    position.dir = 'V';
    grid[5][7].ship = TORPEDO;
    boat = SUBMARINE;
    if (placeShip(grid, position, boat) == false)
    {
        cout << "PASS \t: F4 CARRIER V (collé diagonale)" << endl;
        pass++;
    }
    else
    {
        cout << "FAIL! \t: F4 CARRIER V (collé diagonale)" << "\n\tActual true \n\texpected false " << endl;
        failed++;
    }
    cout << "Totals: " << pass << " passed, " << failed << " failed" << endl;
    cout << "********* Finished testing of placeShipV2 *********" << endl;
}

void test_aleadyShot()
{
    int pass = 0;
    int failed = 0;
    Cell grid[SIZE][SIZE];
    Coordinate coordinate;
    cout << "********* Start testing of aleadyShot *********" << endl;
    // G8 true HIT
    initGrid(grid);
    coordinate.col = 'G';
    coordinate.row = 8;
    grid[8][7].state = HIT;
    if (alreadyShot(grid, coordinate) == true)
    {
        cout << "PASS \t: Tir déjà effectué en G8 (HIT)" << endl;
        pass++;
    }
    else
    {
        cout << "FAIL! \t: Tir déjà effectué en G8 (HIT)" << "\n\tActual false \n\texpected true" << endl;
        failed++;
    }
    // G7 true MISS
    initGrid(grid);
    coordinate.col = 'G';
    coordinate.row = 7;
    grid[7][7].state = MISS;
    if (alreadyShot(grid, coordinate) == true)
    {
        cout << "PASS \t: Tir déjà effectué en G7 (MISS)" << endl;
        pass++;
    }
    else
    {
        cout << "FAIL! \t: Tir déjà effectué en G7 (MISS)" << "\n\tActual false \n\texpected true" << endl;
        failed++;
    }
    // G6 true SINK
    initGrid(grid);
    coordinate.col = 'G';
    coordinate.row = 6;
    grid[6][7].state = SINK;
    if (alreadyShot(grid, coordinate) == true)
    {
        cout << "PASS \t: Tir déjà effectué en G6 (SINK)" << endl;
        pass++;
    }
    else
    {
        cout << "FAIL! \t: Tir déjà effectué en G6 (SINK)" << "\n\tActual false \n\texpected true" << endl;
        failed++;
    }
    // B10 false
    initGrid(grid);
    coordinate.col = 'B';
    coordinate.row = 10;
    if (alreadyShot(grid, coordinate) == false)
    {
        cout << "PASS \t: Premier tir en B10" << endl;
        pass++;
    }
    else
    {
        cout << "FAIL! \t: Premier tir en B10" << "\n\tActual true \n\texpected false" << endl;
        failed++;
    }
    cout << "Totals: " << pass << " passed, " << failed << " failed" << endl;
    cout << "********* Finished testing of aleadyShot *********" << endl;
}

void test_hitOrMiss()
{
    int pass = 0;
    int failed = 0;
    Cell grid[SIZE][SIZE];
    Coordinate coordinate;
    cout << "********* Start testing of hitOrMiss *********" << endl;
    // C7 Hit
    initGrid(grid);
    coordinate.col = 'C';
    coordinate.row = 7;
    grid[7][3].ship = TORPEDO;
    if (hitOrMiss(grid, coordinate) == true)
    {
        cout << "PASS \t: Tir en C7 touché" << endl;
        pass++;
    }
    else
    {
        cout << "FAIL! \t: Tir en C7 touché" << "\n\tActual false \n\texpected true" << endl;
        failed++;
    }
    // C7 HIT grid
    initGrid(grid);
    coordinate.col = 'C';
    coordinate.row = 7;
    grid[7][3].ship = TORPEDO;
    hitOrMiss(grid, coordinate);
    if (grid[7][3].state == HIT)
    {
        cout << "PASS \t: Tir en C7 HIT enregistré dans la grille" << endl;
        pass++;
    }
    else
    {
        cout << "FAIL! \t: Tir en C7 HIT enregistré dans la grille" << "\n\tActual " << grid[7][3].state << "\n\texpected HIT (" << HIT << ")" << endl;
        failed++;
    }
    // F1 Miss
    initGrid(grid);
    coordinate.col = 'F';
    coordinate.row = 1;
    if (hitOrMiss(grid, coordinate) == false)
    {
        cout << "PASS \t: Tir en F1 à l'eau" << endl;
        pass++;
    }
    else
    {
        cout << "FAIL! \t: Tir en F1 à l'eau" << "\n\tActual true \n\texpected false" << endl;
        failed++;
    }
    // F1 MISS grid
    initGrid(grid);
    coordinate.col = 'F';
    coordinate.row = 1;
    hitOrMiss(grid, coordinate);
    if (grid[1][6].state == MISS)
    {
        cout << "PASS \t: Tir en F1 MISS enregistré dans la grille" << endl;
        pass++;
    }
    else
    {
        cout << "FAIL! \t: Tir en F1 MISS enregistré dans la grille" << "\n\tActual " << grid[1][6].state << "\n\texpected MISS (" << MISS << ")" << endl;
        failed++;
    }
    cout << "Totals: " << pass << " passed, " << failed << " failed" << endl;
    cout << "********* Finished testing of hitOrMiss *********" << endl;
}

void test_isBoatSank()
{
    int pass = 0;
    int failed = 0;
    Cell grid[SIZE][SIZE];
    int row;
    int column;
    cout << "********* Start testing of isBoatSank *********" << endl;
    // CRUISER SANK F3
    initGrid(grid);
    row = 3;
    column = 5;
    grid[1][5].ship = CRUISER;
    grid[1][5].state = HIT;
    grid[2][5].ship = CRUISER;
    grid[2][5].state = HIT;
    grid[3][5].ship = CRUISER;
    grid[3][5].state = HIT;
    grid[4][5].ship = CRUISER;
    grid[4][5].state = HIT;
    if (isBoatSank(grid, row, column))
    {
        cout << "PASS \t: Tir en F3 CRUISER coulé" << endl;
        pass++;
    }
    else
    {
        cout << "FAIL! \t: Tir en F3 CRUISER coulé" << "\n\tActual false\n\texpected true" << endl;
        failed++;
    }
    // CRUISER SANK F1
    initGrid(grid);
    row = 1;
    column = 5;
    grid[1][5].ship = CRUISER;
    grid[1][5].state = HIT;
    grid[2][5].ship = CRUISER;
    grid[2][5].state = HIT;
    grid[3][5].ship = CRUISER;
    grid[3][5].state = HIT;
    grid[4][5].ship = CRUISER;
    grid[4][5].state = HIT;
    if (isBoatSank(grid, row, column))
    {
        cout << "PASS \t: Tir en F1 CRUISER coulé" << endl;
        pass++;
    }
    else
    {
        cout << "FAIL! \t: Tir en F1 CRUISER coulé" << "\n\tActual false\n\texpected true" << endl;
        failed++;
    }
    // TORPEDO HIT
    initGrid(grid);
    row = 7;
    column = 3;
    grid[7][3].ship = TORPEDO;
    grid[7][3].state = HIT;
    if (!isBoatSank(grid, row, column))
    {
        cout << "PASS \t: Tir en C7 TORPEDO touché" << endl;
        pass++;
    }
    else
    {
        cout << "FAIL! \t: Tir en C7 TORPEDO touché" << "\n\tActual true\n\texpected false" << endl;
        failed++;
    }
    // Confusion SUBMARINE DESTROYER
    initGrid(grid);
    row = 7;
    column = 4;
    grid[7][3].ship = SUBMARINE;
    grid[7][3].state = HIT;
    grid[7][4].ship = SUBMARINE;
    grid[7][4].state = HIT;
    grid[7][5].ship = SUBMARINE;
    grid[7][5].state = UNSHOT;
    grid[7][7].ship = DESTROYER;
    grid[7][7].state = HIT;
    grid[7][8].ship = DESTROYER;
    grid[7][8].state = UNSHOT;
    grid[7][9].ship = DESTROYER;
    grid[7][9].state = UNSHOT;
    if (!isBoatSank(grid, row, column))
    {
        cout << "PASS \t: Tir en C7 confusion SUBMARINE DESTROYER" << endl;
        pass++;
    }
    else
    {
        cout << "FAIL! \t: Tir en C7 confusion SUBMARINE DESTROYER" << "\n\tActual true\n\texpected false" << endl;
        failed++;
    }
    cout << "Totals: " << pass << " passed, " << failed << " failed" << endl;
    cout << "********* Finished testing of isBoatSank *********" << endl;
}
