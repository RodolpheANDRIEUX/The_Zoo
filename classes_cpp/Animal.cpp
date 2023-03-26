#include "../headers/Animal.h"
#include "../headers/Eagle.h"

string Animal::getName() {
    return name;
}

bool Animal::getFemale() const {
    return female;
}

void Animal::kill(int deathCode) {
    switch (deathCode){
        case 1:
            cout << "*" << name << " died from natural causes*" << endl;
            break;
        case 2:
            cout << "*" << name << " has been eaten by a Tiger*" << endl;
            break;
        case 3:
            cout << "*" << name << " escaped the Zoo*" << endl;
            break;
        case 4:
            cout << "*" << name << " died from overcrowding in his habitat*" << endl;
            break;
        case 5:
            cout << "*" << name << " starved to death*" << endl;
            break;
        case 6:
            cout << "The thieves have stolen " << name << endl;
            break;
        case 7:
            cout << "*" << name << " died from sickness*" << endl;
            break;
        default:
            cout << "*" << name << " died*" << endl;
            break;
    }
    delete this;
}

bool Animal::everythingok() const {
    if (hungry || (sickCoolDown > 0)){
        return false;
    }
    return true;
}

void Animal::getsShy(int i) {
    shyCoolDown = i;
}

int Animal::menu() {
    int Input;
    do {
        cout << "\n** " << name << " **" << endl;
        cout << "(1) Rename" << endl;
        cout << "(2) Move" << endl;
        cout << "(3) Interact" << endl;
        cout << "(0) Go back" << endl;

        string strInput;
        cin >> strInput;
        try {
            Input = stoi(strInput);
        } catch (...) {
            cout << "*unknown input*" << endl;
            Input = -1;
            continue;
        }

        switch (Input) {
            case 1:
                rename();
                break;
            case 2:
                return 1;
            case 3:
                interact();
                break;
            case 0:
                break;
            default:
                cout << "*unknown input*" << endl;
                break;
        }

    } while (Input != 0);
    return 0;
}

void Animal::rename() {
    string newName;
    cout << "Enter new name: ";
    cin >> newName;
    name = newName;
    cout << "Name changed to " << name << "." << endl;
}

