#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "typeDef.h"
#include <iostream>

using namespace std;

/*
 * \brief Fonction qui initialise la grille de jeu.
 * \param grid La grille de jeu.
 */
void titleGame();

/*
* \brief Check if the name of the player is not over SIZE_GRID_GRID characters
* \param playerName : the name of the player
* \return true if the name is not over SIZE_GRID_GRID characters
*/
void checkNameLength(string playerName);

/*
 * \espaces équivalent entre le nom p1 et p2
 * \param p1name nom du joueur 1
 * \param p2name nom du joueur 2
 * \return void
 */
void centerName(string p1name, string p2name);

/*
 * \brief Affiche toutes les lettres en fonction de SIZE_GRID_GRID 
 * \affiche des lettre en fonction de SIZE_GRID_GRID 
 * \return void
 */
void albetGrid();

/*
 * \brief Initialise le tableau à vid
 * \param une grille
 * \return void
 */
void initializeGrid(Cell aGrid[][SIZE_GRID]);

/*
 * \brief Affiche les grilles des deux joueurs
 * \param aPlayer : le joueur
 * \param anOpponent l'adversaire
 * \return void
 */
void displayGrid(Player & aPlayer, Player & anOpponent);

/*
 * \brief Efface l'écran après appui sur une touche et affiche
 * << BattleShip >> stylisé avec votre nom
 * appel système de la commande console << cls >> voir
 * https://cplusplus.com/reference/cstdlib/system/
 * /!\ ne fonctionne que sous Windows
 * \return void
 */
void clearScreen();

/*
 * \brief Vérifie les valeurs saisies pour initialiser les coordonnées
 * de placement des navires de guerre
 * \param aPlace : la saisie du joeur par exemple << b10 >>
 * \param someCoordi : les coordonnées valides stockées
 * \return true si les coordonnées sont valides, false sinon
 */
bool checkCoordinate(string aPlace, Coordinate & sommeCoordi);

/*
 * \brief place un navire dans la grille en vérifiant les règles
 * \param aGrid : la grille du joueur
 * \param aPlace : les coordonnées et l'orientation du placement
 * \param aShip : le type de navire (donc sa taille)
 * \return true si le placement est valide et effectué, false sinon
 */
bool placeShip(Cell grid[][SIZE_GRID], Placement place, Ship ship);

/*
 * \brief demande au joueur de placer chaque navire, vérifie les coordonnées
 * (checkCoordinnate) et affiche les grilles (displayGrid) des joueurs à chaque
 * placement (placeShip)
 * \param aPlayer : le joueur
 * \param anOpponent : l'adversaire
 * \return void
 */
void askPlayerToPlace(Player & aPlayer, Player & anOpponent);

/* \brief indique si le coup a déjà été tiré
 * \param aGrid : la grille
 * \param someCoordi : les coordonnées du tir
 * \return true si le coup a déjà été tiré
 */
bool alreadyShot(Cell aGrid[][SIZE_GRID], Coordinate someCoordi);

/* \brief modifie l'état d'une case de la grille de l'adversaire
 * selon le coup joué
 * \param aGrid : la grille
 * \param someCoordi : les coordonnées du tir
 * \return true si HIT
 */
bool hitOrMiss(Cell aGrid[][SIZE_GRID], Coordinate someCoordi);

/*
 * \brief affiche les grilles (displayGrid) des joueurs puis demande au joueur
 * les coordonnées du tir en vérifiant les coordonnées (checkCoordinate) et si
 * elles n'ont pas déjà été jouées (alreadyShot) puis affiche HIT or MISS
 * (hitOrMiss)
 * \param aPlayer : le joueur
 * \param anOpponent : l'adversaire
 * \return void
 */

void askPlayerToShot(Player& aPlayer, Player& anOpponent);

/*
 * \brief place tous les navires aléatoirement en respectant les règles
 * du jeu (placeShip)
 * \param aPlayer : le joueur avec sa grille
 * \return void
 */
void randomPlacement(Player& aPlayer);

/*
 * \brief détermine si un bateau est coulé (toutes ses cases sont HIT)
 * \param aGrid : la grille
 * \param aRow : la ligne
 * \param aCol : la colonne
 */
bool isBoatSank(Cell aGrid[][SIZE_GRID], int aRow, int aCol);



#endif // FUNCTIONS_H
