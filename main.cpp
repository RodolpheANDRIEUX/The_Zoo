#include <iostream>
#include "headers/Zoo.h"
#include "headers/AmazonZoo.h"
using namespace std;

int main() {
    Zoo zoo("Our zoo");
    AmazonZoo amazonZoo;

    string userInput;
    int Input;
    do {
        cout << "\n**** LE ZOO ****" << endl;
        cout << "(1) Buy" << endl;
        cout << "(2) My Zoo" << endl;
        cout << "(3) Pass time" << endl;
        cout << "(0) Exit" << endl;
        cin >> userInput; Input = (int)userInput[0] - 48;
        switch (Input)
        {
            case 1:
                amazonZoo.openBoutique(&zoo);
                break;
            case 2:
                cout << "\n**** MY ZOO ****" << endl;
                //zoo.show();
                break;
            case 3:
                cout << "\n**** PASS TIME ****" << endl;
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