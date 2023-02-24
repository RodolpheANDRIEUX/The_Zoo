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

void AmazonZoo::sexeMenu(Zoo *client, int articleID) {
    string userInput;
    int Input;
    do {
        cout << "\n**** Male or Female ****                                  Balance: " << client->getMoney() << "euro" << endl;
        cout << "(1) " << ((articleID == 207) ? "6 month old Rooster" : "Male") << endl;
        cout << "(2) " << ((articleID == 207) ? "6 month old Hen" : "Female") << endl;
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
        cout << "(1) 6 month old" << endl;
        cout << "(2) 4 years old" << endl;
        cout << "(3) 14 years old" << endl;
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

void AmazonZoo::placeAnimal(Zoo *client, int article) {
    if (article >= 201 && article <= 206){ // If its a Tiger
        if (!client->checkPlaceForTiger()){
            cout << "" << endl;
            return;
        }
        sell(client, article);
    } else if (article >= 207 && article <= 208){ // If its a chicken
        if (!client->checkPlaceForChiken()){
            cout << "" << endl;
            return;
        }
        sell(client, article);
    }else if (article >= 209 && article <= 214){ // If its an Eagle
        if (!client->checkPlaceForEagle()){
            cout << "" << endl;
            return;
        }
        sell(client, article);
    }
}




