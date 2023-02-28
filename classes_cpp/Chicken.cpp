#include "../headers/Chicken.h"

void Chicken::show() {
    cout << name << "(" << ((female) ? "hen) - " : "rooster) - ");
    cout << ((age/30 <= 12) ? to_string(age/30) + " month old (" + to_string(age) + " days) ": to_string(age/360) + "years old (" + to_string(age) + " days) ");
    cout << ((sick)? "" : "not ") << "sick and " << ((hungry)? "" : "not ") << "hungry" << endl;
}

void Chicken::getOld() {
    age++;
    if(age >= 182){
        this->kill(1);
    }
}
