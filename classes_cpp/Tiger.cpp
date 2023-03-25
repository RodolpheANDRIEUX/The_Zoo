#include <random>
#include "../headers/Tiger.h"
#include "../headers/Utils.h"

void Tiger::show() {
    cout << name << "(" << ((female) ? ((pregnancy > 0) ? "Female) - Pregnant, " : "Female) - ") : "Male) - ");
    cout << ((age/30 <= 6) ? "baby tiger " : "") << ((age/30 <= 12) ? to_string(age/30) + " month old (" + to_string(age) + " days) ": to_string(age/360) + "years old (" + to_string(age) + " days) ");
    cout << ((sickCoolDown > 0)? "" : "not ") << "sick and " << ((hungry)? "" : "not ") << "hungry" << ((sickCoolDown > 0 || hungry)? "     /!\\" : "") << endl;
}

void Tiger::handleSickness() {
    if(sickCoolDown > 0 && Utils::tirage(2400)){
        sickCoolDown--;
        return;
    }
    if(Utils::tirage(25) && Utils::tirage(300)) {
        sickCoolDown = 12;
    }
}

bool Tiger::getOlder() {
    age++;
    if (shyCoolDown > 0 ){
        shyCoolDown--;
    }
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
        return age >= 1440 && age <= 5040 && pregnancy == 0 && shyCoolDown == 0 && sickCoolDown == 0 && !hungry;
    } else { // for male
        return age >= 2160 && age <= 5040 && shyCoolDown == 0 && sickCoolDown == 0 && !hungry;
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
        if (sickCoolDown > 0 || hungry){ // its ok if its the last day... cmon!
            pregnancy = 0;
            cout << name << " lost the baby" << endl;
        }
    }
    return false;
}

double Tiger::eatMeat(double meat) {
    if (meat == 0){
        hungerCoolDown++;
        if (hungerCoolDown > 2){
            hungry = true;
        }
        if (hungerCoolDown > 20){
            kill(5);
            return -1;
        }
        return 0;
    }

    double consumption;
    if(!female) {
        consumption = 12;
    } else if(pregnancy > 0) {
        consumption =  20;
    } else {
        consumption =  10;
    }
    if(consumption > meat){
        cout << "There is no meat left /!\\" << endl;
        return meat;
    }
    hungry = false;
    hungerCoolDown = 0;
    return consumption;
}

double Tiger::eatGrains(double grains) {
    return 0;
}

int Tiger::sell() {
    if(age <= 180) {
        return 1500;
    }
    if(age <= 1440) {
        return 60000;
    }
    return 10000;
}