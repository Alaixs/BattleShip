#ifndef TYPEDEF_H
#define TYPEDEF_H
#include <iostream>
using namespace std;

//la dimension de la grille de jeu 10+2 pour détection du navire voisin
const int SIZE = 12;
// le nombre de navires de guerre
const int NBSHIPS = 5;
// le nombre de cases occupées par les navires d’un joueur (score)
const int NBCELLS = 17;
// les navires de guerre disponibles et leur taille sur la grille
enum Ship {CARRIER=5, CRUISER=4, DESTROYER=3, SUBMARINE=3, TORPEDO=2,
NONE=0}; //numéro = nb cases


// les différents états que peut prendre une case de la grille et leur
// affichage
enum State {HIT='x', SINK='#', MISS='o', UNSHOT='~'};
// une case de la grille
// le navire présent sur la case
// l’état de la case
struct Cell {
 Ship ship;
 State state;
};
// le joueur avec
// son nom
// son score pour déterminer qui a perdu
// sa grille de jeu
struct Player {
 string name;
 int score;
 Cell grid[SIZE][SIZE];
};
// les coordonnées de la case sur la grille avec
// la colonne de ‘A’ à ‘J’ (lettre en MAJ)
// la ligne de 1 à 10
// /!\ prévoir le cas où la grille change de taille !
struct Coordinate {
 char col;
 int row;
};

#endif // TYPEDEF_H
