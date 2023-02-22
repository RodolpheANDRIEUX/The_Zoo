#include <iostream>

using namespace std;

int main() {
    Zoo zoo("Notre zoo", 80000);

    bool exit = false;
    string userInput;
    int Input;

    while(!exit) {
        cout << "\n**** MENU PRINCIPAL ****" << endl;
        cout << "(1) Boutique" << endl;
        cout << "(2) Zoo" << endl;
        cout << "(3) Jour suivant" << endl;
        cout << "(0) Quitter" << endl;
        cin >> userInput; Input = (int)userInput[0] - 48;
        switch (Input)
        {
            case 1:
                zoo.boutique();
                break;
            case 2:
                zoo.show();
                break;
            case 3:
                zoo.skip();
                break;
            case 0:
                exit = true;
                break;
            default:
                cout << "*unknown input*" << endl;
                break;
        }
    }
}