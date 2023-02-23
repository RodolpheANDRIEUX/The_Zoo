//
// Created by rodol on 23/02/2023.
//

#include "../headers/AmazonZoo.h"
#include <iostream>
using namespace std;

void AmazonZoo::openBoutique(){

    string userInput;
    int Input;
    do {
        cout << "(1) Food" << endl;
        cout << "(2) habitats" << endl;
        cout << "(3) Animals" << endl;
        cout << "(0) Main Menu" << endl;
        cin >> userInput; Input = (int)userInput[0] - 48;
        switch (Input)
        {
            case 1:
                cout << "\n**** FOOD ****" << endl;
                foodMenu();
                break;
            case 2:
                cout << "\n**** HABITATS ****" << endl;
                //zoo.show();
                break;
            case 3:
                cout << "\n**** ANIMALS ****" << endl;
                //zoo.timeMenu();
                break;
            case 0:
                break;
            default:
                cout << "*unknown input*" << endl;
                break;
        }
    } while (Input != 0);

}

void AmazonZoo::foodMenu(){}

void AmazonZoo::habitatMenu(){}

void AmazonZoo::animalMenu(){}

