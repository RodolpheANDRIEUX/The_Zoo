//
// Created by rodol on 23/02/2023.
//

#include "../headers/Tiger.h"

void Tiger::show() {
    cout << name << "(" << ((female) ? "Female) - " : "Male) - ");
    cout << ((age/30 <= 12) ? to_string(age/30) + " month old (" + to_string(age) + " days) ": to_string(age/360) + "years old (" + to_string(age) + " days) ");
    cout << ((sick)? "" : "not ") << "sick and " << ((hungry)? "" : "not ") << "hungry" << endl;
}

void Tiger::getOld() {
    age++;
    if(age >= 182){
        this->kill(1);
    }
}