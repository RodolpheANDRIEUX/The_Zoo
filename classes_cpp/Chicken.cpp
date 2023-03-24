#include <random>
#include "../headers/Chicken.h"

void Chicken::show() {
    cout << name << "(" << ((age/30 <= 6) ? "baby " : "") << ((female) ? "hen) - " : "rooster) - ");
    cout << ((age/30 <= 12) ? to_string(age/30) + " month old (" + to_string(age) + " days) ": to_string(age/360) + "years old (" + to_string(age) + " days) ");
    cout << ((sickCoolDown > 0)? "" : "not ") << "sick and " << ((hungry)? "" : "not ") << "hungry" << ((sickCoolDown > 0 || hungry)? "     /!\\" : "") << endl;
}

void Chicken::handleSickness() {
    if(sickCoolDown > 0 && Utils::tirage(2400)){
        sickCoolDown--;
    }
    if(Utils::tirage(10) && Utils::tirage(125)) {
        sickCoolDown = 4;
    }
}

bool Chicken::getOlder() {
    age++;
    if (shyCoolDown > 0 ){
        shyCoolDown--;
    }
    if(age >= 5340){
        if(Utils::tirage(25)){ // esperance +ou- 2 mois en moyenne
            kill(1);
            return true;
        }
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

void Chicken::getPregnant(Animal *mate) {
    pregnancy = 1;
    cout << name << " seems to be sitting on eggs" << endl;
}

bool Chicken::birthDay(int date) {
    if (pregnancy > 0){
        pregnancy ++;
        if (pregnancy >= 42){
            pregnancy = 0;
            return true;
        }
        if (sickCoolDown > 0 || hungry){ // its ok if its the last day... cmon!
            pregnancy = 0;
            cout << name << "'s eggs are not covered anymore..." << endl;
        }
    }
    return false;
}

double Chicken::eatGrains(double grains) {
    if (grains == 0){
        hungerCoolDown++;
        if (hungerCoolDown > ((female) ? 1 : 2)){
            hungry = true;
        }
        if (hungerCoolDown > 5){
            kill(5);
            return -1;
        }
        return 0;
    }

    double consumption;
    if(!female) {
        consumption = 0.18;
    } else if(pregnancy > 0) {
        consumption =  0.3;
    } else {
        consumption =  0.15;
    }
    if(consumption > grains){
        cout << "There is no grains left /!\\" << endl;
        return grains;
    }
    hungry = false;
    hungerCoolDown = 0;
    return consumption;
}

double Chicken::eatMeat(double meat) {
    return 0;
}