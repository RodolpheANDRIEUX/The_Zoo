#include <random>
#include "../headers/Eagle.h"

void Eagle::show() {
    cout << name << "(" << ((female) ? "Female) - " : "Male) - ");
    cout << ((age/30 <= 12) ? to_string(age/30) + " month old (" + to_string(age) + " days) ": to_string(age/360) + "years old (" + to_string(age) + " days) ");
    cout << ((sick)? "" : "not ") << "sick and " << ((hungry)? "" : "not ") << "hungry" << endl;
}

void Eagle::getSick() {
    if(!sick) {
        random_device rd;
        mt19937 gen(rd());

        std::uniform_int_distribution<> dis(0, 360);

        int random = dis(gen);
        if(random < 36) {
            cout << name << "is sick" << endl;
            sick = true;
            fdSick = age;
        }
    } else if((age-fdSick) <= 30) {
        sick = false;
    }
}

bool Eagle::getOld() {
    age++;
    if(age >= 9000){
        this->kill(1);
        return true;
    }
    return false;
}

bool Eagle::isSexuallyPredisposed() {
    if (female) { // for female
        return age >= 1440 && age <= 5040 && pregnancy == 0 && shyCoolDown == 0;
    } else { // for male
        return age >= 1440 && age <= 5040 && shyCoolDown == 0;
    }
}
