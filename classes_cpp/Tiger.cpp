//
// Created by rodol on 23/02/2023.
//

#include <random>
#include "../headers/Tiger.h"
#include "../headers/Utils.h"

void Tiger::show() {
    cout << name << "(" << ((female) ? "Female) - " : "Male) - ");
    cout << ((age/30 <= 12) ? to_string(age/30) + " month old (" + to_string(age) + " days) ": to_string(age/360) + "years old (" + to_string(age) + " days) ");
    cout << ((sick)? "" : "not ") << "sick and " << ((hungry)? "" : "not ") << "hungry" << endl;
}

void Tiger::getSick() {
    if(!sick) {
        int random = Utils::getRandomNumber();

        if(random < 300) {
            cout << "*" << name << " is sick*" << endl;
            sick = true;
            sickCoolDown = 15;
        }
    } else if(sickCoolDown <= 0) {
        cout << "*" << name << " is neat*" << endl;
        sick = false;
    } else {
        sickCoolDown--;
    }
}

bool Tiger::getOld() {
    age++;
    if(age >= 9000){
        this->kill(1);
        return true;
    }
    return false;
}
