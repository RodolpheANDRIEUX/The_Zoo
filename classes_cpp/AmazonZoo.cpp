#include "../headers/AmazonZoo.h"
#include "../headers/Zoo.h"
#include <iostream>
using namespace std;

void AmazonZoo::openBoutique(Zoo* client){

    string userInput;
    int Input;
    do {
        cout << "\n**** AMAZON ZOO ****                                       Balance: " << client->getMoney() << "euro" << endl;
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
                habitatMenu(client);
                break;
            case 3:
                animalMenu(client);
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
        cout << "\n**** FOOD ****                                    Balance: " << client->getMoney() << "euro" << endl;
        cout << "(1) Meat                                          Your Meat: " << client->getSteaks() << "kg" << endl;
        cout << "(2) Grains                                        Your Grains: " << client->getGrains() << "kg" << endl;
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

void AmazonZoo::habitatMenu(Zoo* client){

    string userInput;
    int Input;

    do {
        cout << "\n**** HABITATS ****                                  Balance: " << client->getMoney() << "euro" << endl;
        cout << "(1) For Tiger (can contain up to 2 Tigers)" << endl;
        cout << "(2) For Chicken (can contain up to 10 chickens)" << endl;
        cout << "(3) For Chicken (can contain up to 4 eagles)" << endl;
        cout << "(0) back to menu" << endl;
        cin >> userInput; Input = (int)userInput[0] - 48;
        switch (Input)
        {
            case 1:
                sell(client, 101); // Tiger Enclosure
                break;
            case 2:
                sell(client, 102); // Chicken Coop
                break;
            case 3:
                sell(client, 103); // Eagle Aviary
                break;
            case 0:
                break;
            default:
                cout << "*unknown input*" << endl;
                break;
        }
    } while (Input != 0);
}

void AmazonZoo::animalMenu(Zoo* client){}

void AmazonZoo::sell(Zoo *client, int article) {
    double quantity;
    double price;
    string userInput;
    int Input;

    cout << "\n** Buying "<< catalog[article].first << " (" << catalog[article].second << "euro" << ((article <= 100) ? "/kg) **" : ") **") << endl;
    cout << "Quantity" << ((article <= 100) ? " (kg): " : ": ");
    cin >> quantity;
    price = quantity * catalog[article].second;
    cout << "It will be " << price << "euro. Continue?" << endl;

    do{
        cout << "(1) Yes\n(0) No" << endl;
        cin >> userInput; Input = (int)userInput[0] - 48;

        if (Input == 1){
            if (client->pay(price)) {
                cout << "*payment accepted*" << endl;
                cout << "Your Balance is now " << client->getMoney() << "euro" << endl;
                client->give(article, quantity);
                return;
            }
            cout << "payment declined" << endl;
            return;
        }

    }while (Input != 0);
}

