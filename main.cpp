#include <iostream>
#include "typeDef.H"

//TODO : Effacer nom quand touche préssé/Faire input user pour placer bateau
using namespace std;

//Affiche toutes les lettres en fonction de SIZE
void albetgrid()
{
    for(int i= 0; i < SIZE-2 ; i++)
    {
        cout << albet[i] << " ";
    }
}

//Fonction pour crée des espaces équivalent entre le nom p1 et p2
void spaceName()
{
    for(int i=0; i < k ;i++)
    {

        cout << " ";
    }
}



int main()
{
    system("color");
    //Creation de joueur 1 et 2
    struct Player p1;
    struct Player p2;

    //atribution caractere de base à la grille
    for (int i = 1; i < SIZE-1; i++)
    {
        for (int j = 1; j < SIZE-1; j++)
        {
            //On assigne par défaut UNSHOT (~) à toute la grille
            p1.grid[i][j].state=UNSHOT;
            p1.grid[i][j].ship=NONE;
            p2.grid[i][j].state=UNSHOT;
            p2.grid[i][j].ship=NONE;

        }
    }
    p1.grid[2][5].ship = CARRIER;

//add boat


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
    //Calcul de l'espace necessaire pour faire centrer le nom avec la grille
    for (string::size_type space = 0; space < ((SIZE*2)-p1.name.length())/2; space++) {
        cout << " ";
        k++;
    }

    {

        //Sortie du nom avec couleur allié
        cout << "\033[1;34m" + p1.name +"\033[0m";

        spaceName();


        for (string::size_type space = 0; space < ((SIZE*2)-p2.name.length())/2; space++) {
            cout << " ";
        }
        //Fonction qui rajoute un espace en fonction d'un chiffre ou non
        if(p1.name.length() & 1)
        {
            cout << " ";
        }
        //Ajustement pour perfectionner le centrage des noms
        //Sortie du nom avec couleur ennemis
        cout << " " << "\033[1;31m" + p2.name +"\033[0m"<< endl;
        //début grille
        cout << "   ";
        albetgrid();
        cout << "     ";
        albetgrid();
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
//draw a penis


            //Condition en fonction de quel OS on se trouve
            //Demande d'appuyer sur n'importe quel boutton pour clear le terminal et passer au joueur suivant
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
}
