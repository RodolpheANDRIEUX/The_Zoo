//
// Created by rodol on 23/02/2023.
//

#include <random>
#include "../headers/Tiger.h"
#include "../headers/Utils.h"

void Tiger::show() {
    cout << name << "(" << ((female) ? ((pregnancy > 0) ? "Female) - Pregnant, " : "Female) - ") : "Male) - ");
    cout << ((age/30 <= 6) ? "baby tiger " : "") << ((age/30 <= 12) ? to_string(age/30) + " month old (" + to_string(age) + " days) ": to_string(age/360) + "years old (" + to_string(age) + " days) ");
    cout << ((sick)? "" : "not ") << "sick and " << ((hungry)? "" : "not ") << "hungry" << ((sick || hungry)? "     /!\\" : "") << endl;
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
    if(age >= 8850){
        if(Utils::tirage(10)){ // esperance +ou- 5 mois en moyenne
            kill(1);
            return true;
        }
    }
    return false;
}

bool Tiger::isSexuallyPredisposed() {
    if (female) { // for female
        return age >= 1440 && age <= 5040 && pregnancy == 0 && shyCoolDown == 0;
    } else { // for male
        return age >= 2160 && age <= 5040 && shyCoolDown == 0;
    }
}

void Tiger::getPregnant(Animal *mate) {
    pregnancy = 1; // first day
    cout << "for some reason " << name << " ate twice as more today." << endl;
}

bool Tiger::birthDay(int date) {
    if (pregnancy > 0){
        pregnancy ++;
        if (pregnancy == 90){
            pregnancy = 0;
            return true;
        }
        if (sick || hungry){ // its ok if its the last day... cmon!
            pregnancy = 0;
            cout << name << " lost the baby" << endl;
        }
    }
    return false;
}



