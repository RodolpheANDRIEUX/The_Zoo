#include "../headers/Zoo.h"
#include "../headers/TigerEnclosure.h"
#include "../headers/Tiger.h"
#include "../headers/ChickenCoop.h"
#include "../headers/EagleAviary.h"

// it's time to pay!
bool Zoo::pay(double price) {
    if (money >= price){
        money -= price;
        return true;
    }
    return false;
}

double Zoo::getMoney() const {
    return money;
}

double Zoo::getGrains() const {
    return grains;
}

double Zoo::getSteaks() const {
    return steaks;
}

// create all new elements (Food, Habitats, Animals) when bought in the store
void Zoo::give(int article, double quantity) {
    if (article < 100){ // food
        switch (article) {
            case 1:
                steaks += quantity;
                break;
            case 2:
                grains += quantity;
                break;
            default:
                cout << "error giving due: article doesnt exist!" << endl;
        }
        return;
    }

    string animalName;
    for (int i = 0; i < (int)quantity; i++) {
        if (article >= 200) {
            cout << "give it a name: ";
            cin.ignore();
            getline(cin, animalName);
        }
        switch (article) {
            case 101:
                habitats.push_back(new TigerEnclosure);
                break;
            case 102:
                habitats.push_back(new ChickenCoop);
                break;
            case 103:
                habitats.push_back(new EagleAviary);
                break;
            case 201:
                placeAnimal(new Tiger(animalName, 180, false));
                break;
            case 202:
                placeAnimal(new Tiger(animalName, 180, true));
                break;
            case 203:
                placeAnimal(new Tiger(animalName, 360*4, false));
                break;
            case 204:
                placeAnimal(new Tiger(animalName, 360*4, true));
                break;
            case 205:
                placeAnimal(new Tiger(animalName, 360*14, false));
                break;
            case 206:
                placeAnimal(new Tiger(animalName, 360*14, true));
                break;
            case 207:
                placeAnimal(new Chicken(animalName, 6*30, false));
                break;
            case 208:
                placeAnimal(new Chicken(animalName, 6*30, true));
                break;
            case 209:
                placeAnimal(new Eagle(animalName, 6*30, false));
                break;
            case 210:
                placeAnimal(new Eagle(animalName, 6*30, true));
                break;
            case 211:
                placeAnimal(new Eagle(animalName, 360*4, false));
                break;
            case 212:
                placeAnimal(new Eagle(animalName, 360*4, true));
                break;
            case 213:
                placeAnimal(new Eagle(animalName, 360*14, false));
                break;
            case 214:
                placeAnimal(new Eagle(animalName, 360*14, true));
                break;
            default:
                cout << "error giving due: article doesnt exist!" << endl;
        }
    }
}

bool Zoo::checkPlaceForTiger() {
    for ( auto habitat : habitats){
        if (dynamic_cast<TigerEnclosure*>(habitat) && habitat->getPlace() > 0){
            return true;
        }
    }
    return false;
}

bool Zoo::checkPlaceForChiken() {
    for ( auto habitat : habitats){
        if (dynamic_cast<ChickenCoop*>(habitat) && habitat->getPlace() > 0){
            return true;
        }
    }
    return false;
}

bool Zoo::checkPlaceForEagle() {
    for ( auto habitat : habitats){
        if (dynamic_cast<EagleAviary*>(habitat) && habitat->getPlace() > 0){
            return true;
        }
    }
    return false;
}

void Zoo::placeAnimal(Animal *animal) {
    do {
        vector<int> availableIndex;
        cout << "**** Chose an habitat for " << animal->getName() << " ****" << endl;

        for (int i = 0; i < habitats.size(); i++){ // lists available habitat for the animal
            int available = habitats[i]->getPlace();
            if (available > 0){
                if (dynamic_cast<TigerEnclosure*>(habitats[i]) && dynamic_cast<Tiger*>(animal) || dynamic_cast<TigerEnclosure*>(habitats[i]) && dynamic_cast<Chicken*>(animal)) {
                    availableIndex.push_back(i);
                    cout << "(" <<  i+1 << ") ";
                    cout << "Tiger Enclosure with ";
                    cout << available << " available places" << endl;
                } else  if (dynamic_cast<ChickenCoop*>(habitats[i]) && dynamic_cast<Chicken*>(animal)) {
                    availableIndex.push_back(i);
                    cout << "(" <<  i+1 << ") ";
                    cout << "Chicken Coop with ";
                    cout << available << " available places" << endl;
                } else  if (dynamic_cast<EagleAviary*>(habitats[i]) && dynamic_cast<Eagle*>(animal)) {
                    availableIndex.push_back(i);
                    cout << "(" <<  i+1 << ") ";
                    cout << "Eagle Aviary with ";
                    cout << available << " available places" << endl;
                }
            }
        }

        int Input;
        do{
            string input;
            cin >> input;
            try {
                Input = stoi(input);
            } catch (...) {
                Input = 0;
            }
        } while (Input < 1);
        pair<int, int> err = habitats[Input]->receive(animal);
        switch (err.first){
            case 1:
                steaks += err.second;
                return;
            case 2:
                cout << "You are fined for endangering public safety: " << err.second << "euros" << endl;
                if (!pay(err.second)){
                    cout << "You don't have enough money to pay" << endl;
                    gameOver();
                }
                return;
            case 0:
                cout << "You have successfully welcomed a new animal in the Zoo!" << endl;
                return;
            default:
                cout << "*unknown error*" << endl;
                break;
        }
    } while (true);
}

void Zoo::gameOver() const {
    cout << "\n\nGAME OVER" << endl;
    cout << "Your survived " << Days << " days!" << endl;
    exit(EXIT_SUCCESS);
}
