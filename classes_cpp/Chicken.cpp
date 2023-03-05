#include <random>
#include "../headers/Chicken.h"

void Chicken::show() {
    cout << name << "(" << ((female) ? "hen) - " : "rooster) - ");
    cout << ((age/30 <= 12) ? to_string(age/30) + " month old (" + to_string(age) + " days) ": to_string(age/360) + "years old (" + to_string(age) + " days) ");
    cout << ((sick)? "" : "not ") << "sick and " << ((hungry)? "" : "not ") << "hungry" << endl;
}

void Chicken::getSick() {
    if(!sick) {
        random_device rd;
        mt19937 gen(rd());

        std::uniform_int_distribution<> dis(0, 360);

        int random = dis(gen);
        if(random < 18) {
            cout << name << "is sick" << endl;
            sick = true;
            fdSick = age;
        }
    } else if((age-fdSick) <= 5) {
        sick = false;
    }
}

bool Chicken::getOld() {
    age++;
    if(age >= 5400){
        this->kill(1);
        return true;
    }
    return false;
}

bool Chicken::isSexuallyPredisposed() {
    if (female) { // for female
        return age >= 180 && age <= 2880 && pregnancy == 0 && shyCoolDown == 0;
    } else { // for male
        return age >= 180 && age <= 2880 && shyCoolDown == 0;
    }
}
