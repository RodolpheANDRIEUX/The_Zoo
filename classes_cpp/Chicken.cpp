#include <random>
#include "../headers/Chicken.h"
#include "../headers/Utils.h"

void Chicken::show() {
    cout << name << "(" << ((female) ? "hen) - " : "rooster) - ");
    cout << ((age/30 <= 12) ? to_string(age/30) + " month old (" + to_string(age) + " days) ": to_string(age/360) + "years old (" + to_string(age) + " days) ");
    cout << ((sick)? "" : "not ") << "sick and " << ((hungry)? "" : "not ") << "hungry" << endl;
}

void Chicken::getSick() {
    if(!sick) {
        int random = Utils::getRandomNumber();

        if(random < 50) {
            cout << "*" << name << " is sick*" << endl;
            sick = true;
            sickCoolDown = 5;
        }
    } else if(sickCoolDown <= 0) {
        cout << "*" << name << " is neat*" << endl;
        sick = false;
    } else {
        sickCoolDown--;
    }
}

bool Chicken::getOld() {
    age++;
    if(age >= 182){
        this->kill(1);
        return true;
    }
    return false;
}
