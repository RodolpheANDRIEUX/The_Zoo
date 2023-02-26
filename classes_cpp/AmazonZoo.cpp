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
        cout << "(3) For Eagles (can contain up to 4 eagles)" << endl;
        cout << "(4) Starter Pack (2 for Tigers, 2 for Chickens and 2 for Eagles)" << endl;
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
            case 4:
                if (client->pay(8600)) {
                    cout << "*payment accepted*" << endl;
                    cout << "Your Balance is now " << client->getMoney() << "euro" << endl;
                    client->give(101, 2);
                    client->give(102, 2);
                    client->give(103, 2);
                    return;
                }
                cout << "payment declined" << endl;
                return;
            case 0:
                break;
            default:
                cout << "*unknown input*" << endl;
                break;
        }
    } while (Input != 0);
}

void AmazonZoo::sexeMenu(Zoo *client, int articleID) {
    string userInput;
    int Input;
    do {
        cout << "\n**** Male or Female ****                                  Balance: " << client->getMoney() << "euro" << endl;
        cout << "(1) " << ((articleID == 207) ? "6 month getOld Rooster" : "Male") << endl;
        cout << "(2) " << ((articleID == 207) ? "6 month getOld Hen" : "Female") << endl;
        cout << "(0) back to menu" << endl;
        cin >> userInput; Input = (int)userInput[0] - 48;
        switch (Input)
        {
            case 1:
                placeAnimal(client, articleID);
                return;
            case 2:
                placeAnimal(client, articleID + 1 );
                return;
            case 0:
                break;
            default:
                cout << "*unknown input*" << endl;
                break;
        }
    } while (Input != 0);
}

void AmazonZoo::ageMenu(Zoo *client, int animalID) {
    string userInput;
    int Input;

    do {
        cout << "\n**** " << ((animalID == 201) ? "TIGERS" : "EAGLES") << " ****                                  Balance: " << client->getMoney() << "euro" << endl;
        cout << "(1) 6 month getOld" << endl;
        cout << "(2) 4 years getOld" << endl;
        cout << "(3) 14 years getOld" << endl;
        cout << "(0) back to menu" << endl;
        cin >> userInput; Input = (int)userInput[0] - 48;
        switch (Input)
        {
            case 1:
                sexeMenu(client, animalID);
                return;
            case 2:
                sexeMenu(client, animalID + 2);
                return;
            case 3:
                sexeMenu(client, animalID + 4);
                return;
            case 0:
                break;
            default:
                cout << "*unknown input*" << endl;
                break;
        }
    } while (Input != 0);
}

void AmazonZoo::animalMenu(Zoo* client){
    string userInput;
    int Input;
    do {
        cout << "\n**** ANIMALS ****                                  Balance: " << client->getMoney() << "euro" << endl;
        cout << "(1) Tigers" << endl;
        cout << "(2) Chicken" << endl;
        cout << "(3) Eagles" << endl;
        cout << "(0) back to menu" << endl;
        cin >> userInput; Input = (int)userInput[0] - 48;
        switch (Input)
        {
            case 1:
                ageMenu(client, 201);
                break;
            case 2:
                sexeMenu(client, 207);
                break;
            case 3:
                ageMenu(client, 209);
                break;
            case 0:
                break;
            default:
                cout << "*unknown input*" << endl;
                break;
        }
    } while (Input != 0);
}

void AmazonZoo::sell(Zoo *client, int article) {
    int quantity = 0;
    double price;
    string userInput;
    int Input;

    cout << "\n** Buying "<< catalog[article].first << " (" << catalog[article].second << "euro" << ((article <= 100) ? "/kg) **" : ") **") << endl;
    do {
        cout << "Quantity" << ((article <= 100) ? " (kg): " : ": ");
        string quantityInput;
        cin >> quantityInput;
        try {
            quantity = stoi(quantityInput);
        } catch (...) {
            quantity = 0;
        }
    } while (quantity < 1);
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

void AmazonZoo::placeAnimal(Zoo *client, int article) {
    if (article >= 201 && article <= 206){ // If its a Tiger
        if (!client->checkPlaceForTiger()){
            cout << "There is no place yet for a Tiger in Your Zoo" << endl;
            return;
        }
        sell(client, article);
    } else if (article >= 207 && article <= 208){ // If its a chicken
        if (!client->checkPlaceForChicken()){
            cout << "There is no place yet for a Chicken in Your Zoo" << endl;
            return;
        }
        sell(client, article);
    }else if (article >= 209 && article <= 214){ // If its an Eagle
        if (!client->checkPlaceForEagle()){
            cout << "There is no place yet for an Eagle in Your Zoo" << endl;
            return;
        }
        sell(client, article);
    }
}




