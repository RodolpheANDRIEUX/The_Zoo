#include <random>
#include "../headers/Chicken.h"
#include "../headers/Utils.h"

void Chicken::show() {
    cout << name << "(" << ((age/30 <= 6) ? "baby " : "") << ((female) ? "hen) - " : "rooster) - ");
    cout << ((age/30 <= 12) ? to_string(age/30) + " month old (" + to_string(age) + " days) ": to_string(age/360) + "years old (" + to_string(age) + " days) ");
    cout << ((sick)? "" : "not ") << "sick and " << ((hungry)? "" : "not ") << "hungry" << ((sick || hungry)? "     /!\\" : "") << endl;
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
        if (pregnancy == 42){
            pregnancy = 0;
            return true;
        }
        if (sick || hungry){ // its ok if its the last day... cmon!
            pregnancy = 0;
            cout << name << "'s eggs are not covered anymore..." << endl;
        }
    }
    return false;
}