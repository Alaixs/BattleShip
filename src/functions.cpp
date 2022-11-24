#include <iostream>
#include "typeDef.h"
#include "functions.h"
using namespace std;

// les noms des navires de guerre
string ships[NBSHIPS] = {"carrier", "cruiser", "destroyer", "submarine", "torpedo" };
string name, albet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

void albetGrid()
{
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

void centerName(string name)
{
    
    for (int i = 0; i < (SIZE*2 - name.length())/2; i++)
    {
        cout << " ";
    }
    cout << name;
    
    for (int i = 0; i < (SIZE*2 - name.length())/2; i++)
    {
        cout << " ";
    }
    // si la longueur du nom est impaire, on rajoute un espace
    if (name.length() % 2 == 0)
    {
        cout << " ";
    }
    else 
    {
        cout << "  ";
    }
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