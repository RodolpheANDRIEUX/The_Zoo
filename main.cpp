#include <iostream>
#include "headers/Zoo.h"
#include "headers/AmazonZoo.h"

using namespace std;


/*
 * Procedure d'ajout d'un nouvel animal dans le Zoo
 *
 * Lui creer une classe
 * L'ajouter lui et son habitat au catalogue Amazon (+ food si necessaire)
 * L'ajouter dans les methodes menu (food, habitat, animals, age, sexe)
 * L'ajouter dans le zoo::give() !
 *
 *
 *
 *
 */

int main() {
    Zoo zoo("Our zoo");
    AmazonZoo amazonZoo;
    cout << "####  WELCOME TO YOUR ZOO \"LE ZOO\"!  ####" << endl;
    cout << "You have 1 month of food left!" << endl;

    string userInput;
    int Input;
    do {
        cout << "\n**** LE ZOO ****" << endl;
        cout << "(1) Buy" << endl;
        cout << "(2) See the Zoo" << endl;
        cout << "(3) Pass time" << endl;
        cout << "(0) Exit" << endl;
        cin >> userInput; Input = (int)userInput[0] - 48;
        switch (Input)
        {
            case 1: // Amazon Zoo
                amazonZoo.openBoutique(&zoo);
                break;
            case 2:
                zoo.show();
                break;
            case 3:
                cout << "\n**** PASS TIME ****" << endl;
                zoo.skipMenu();
                break;
            case 0:
                break;
            default:
                cout << "*unknown input*" << endl;
                break;
        }
    } while (Input != 0);
}