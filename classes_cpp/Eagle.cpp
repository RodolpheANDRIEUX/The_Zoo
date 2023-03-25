#include <random>
#include "../headers/Eagle.h"
#include "../headers/Utils.h"

void Eagle::show() {
    cout << name << "(" << ((female) ? ((pregnancy > 0) ? "Female) - Pregnant, " : "Female) - ") : "Male) - ");
    cout << ((age/30 <= 6) ? "baby eagle " : "") << ((age/30 <= 12) ? to_string(age/30) + " month old (" + to_string(age) + " days) ": to_string(age/360) + "years old (" + to_string(age) + " days) ");
    cout << ((sickCoolDown > 0)? "" : "not ") << "sick and " << ((hungry)? "" : "not ") << "hungry" << ((sickCoolDown > 0 || hungry)? "     /!\\" : "") << endl;
}

void Eagle::handleSickness() {
    if(sickCoolDown > 0 && Utils::tirage(2400)){
        sickCoolDown--;
    }
    if(Utils::tirage(833) && Utils::tirage(3)) {
        sickCoolDown = 24;
    }
}

bool Eagle::getOlder() {
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

bool Eagle::isSexuallyPredisposed() {
    if (female) { // for female
        return age >= 1440 && age <= 5040 && pregnancy == 0 && shyCoolDown == 0 && mate == nullptr && sickCoolDown == 0 && !hungry;
    } else { // for male
        return age >= 1440 && age <= 5040 && shyCoolDown == 0 && mate == nullptr && sickCoolDown == 0 && !hungry;
    }
}

void Eagle::marry(Eagle *newMate) {
    mate = newMate;
}

void Eagle::getPregnant(Animal *withMate) {
    pregnancy = 1; // first day
    cout << name << " seems to like " << withMate->getName() << endl;
    marry(dynamic_cast<Eagle *>(withMate)); // je vous déclare aigle...
    (dynamic_cast<Eagle *>(withMate))->marry(this); // ...et aiguillette?
}

bool Eagle::birthDay(int date) {
    if (pregnancy > 1){ // already have eggs
        pregnancy ++;
        if (pregnancy == 45){
            pregnancy = 0;
            return true;
        }
        if (sickCoolDown > 0 || hungry){ // its ok the first and the last day
            pregnancy = 0;
            cout << name << "'s eggs are wasted" << endl;
        }
    }
    if (pregnancy == 1 && date%360 >= 60 && date%360 <= 90){ // spawn eggs
        pregnancy ++;
    }
    return false;
}

double Eagle::eatMeat(double meat) {
    if (meat == 0){
        hungerCoolDown++;
        if (hungerCoolDown > 10){
            hungry = true;
        }
        if (hungerCoolDown > 25){
            kill(5);
            return -1;
        }
        return 0;
    }

    double consumption;
    if(!female) {
        consumption = 0.25;
    } else if(pregnancy > 0) {
        consumption =  0.6;
    } else {
        consumption =  0.3;
    }
    if(consumption > meat){
        cout << "There is no meat left /!\\" << endl;
        return meat;
    }
    hungry = false;
    hungerCoolDown = 0;
    return consumption;
}

double Eagle::eatGrains(double grains) {
    return 0;
}

int Eagle::sell() {
    if(age <= 180) {
        return 500;
    }
    if(age <= 1440) {
        return 2000;
    }
    return 400;
}