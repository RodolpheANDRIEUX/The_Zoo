#include "../headers/AmazonZoo.h"
#include "../headers/Zoo.h"
#include <iostream>
#include <cstdlib>
#include <map>
using namespace std;

void AmazonZoo::openBoutique(Zoo* client){

    string userInput;
    int Input;
    do {
        system("clear");
        system("cls");
        cout << "\n**** AMAZON ZOO ****                                       Balance: " << client->getMoney() << endl;
        cout << "(1) Food" << endl;
        cout << "(2) habitats" << endl;
        cout << "(3) Animals" << endl;
        cout << "(0) Main Menu" << endl;
        cin >> userInput; Input = (int)userInput[0] - 48;
        switch (Input)
        {
            case 1:
                foodMenu(client);
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

void AmazonZoo::foodMenu(Zoo* client){

    string userInput;
    int Input;

    do {
        system("clear");
        system("cls");
        cout << "\n**** FOOD ****                               Balance: " << client->getMoney() << endl;
        cout << "(1) Meat                                     Your Meat: " << client->getSteaks() << "kg" << endl;
        cout << "(2) Grains                                     Your Grains: " << client->getGrains() << "kg" << endl;
        cout << "(0) back to menu" << endl;
        cin >> userInput; Input = (int)userInput[0] - 48;
        switch (Input)
        {
            case 1:
                sell(client, 1); // Meat
                break;
            case 2:
                sell(client, 2); // Grains
                break;
            case 0:
                break;
            default:
                cout << "*unknown input*" << endl;
                break;
        }
    } while (Input != 0);
}

void AmazonZoo::habitatMenu(Zoo* client){}

void AmazonZoo::animalMenu(Zoo* client){}

void AmazonZoo::sell(Zoo *client, int article) {
    double quantity;
    double price;

    cout << "Buying "<< catalog[article].first << " (" << catalog[article].second << "€/kg)" << endl;
    cout << "\nQuantity(kg): ";
    cin >> quantity;
    price = quantity * 2.5;

    if (client->pay(price)) {
        cout << "payment accepted" << endl;
        client->giveGrains(quantity);
        return;
    }
    cout << "payment declined" << endl;
}

