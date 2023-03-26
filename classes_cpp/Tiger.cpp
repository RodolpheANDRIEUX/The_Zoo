#include <random>
#include "../headers/Tiger.h"
#include "../headers/Utils.h"

void Tiger::show() {
    cout << name << "(" << ((female) ? ((pregnancy > 0) ? "Female) - Pregnant, " : "Female) - ") : "Male) - ");
    cout << ((age/30 <= 6) ? "baby tiger " : "") << ((age/30 <= 12) ? to_string(age/30) + " month old (" + to_string(age) + " days) ": to_string(age/360) + "years old (" + to_string(age) + " days) ");
    cout << ((sickCoolDown > 0)? "" : "not ") << "sick and " << ((hungry)? "" : "not ") << "hungry" << ((sickCoolDown > 0 || hungry)? "     /!\\" : "") << endl;
}

bool Tiger::handleSickness() {
    if(sickCoolDown > 0 && Utils::tirage(2400)){ // -20% / +infinity esperance: 15j
        sickCoolDown--;
        if (Utils::tirage(20)) { // en moyenne 10% de mortalité sur la durée esperée de la maladie
            kill(7);
            return true;
        }
        return false;
    }
    if(Utils::tirage(25) && Utils::tirage(300)) {
        sickCoolDown = 12; // durée esperée -20%
    }
    return false;
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

double Tiger::getDailyIncomes(int days) {
    double inc = 0;
    if (days == 1){
        inc += 43800;
    }
    if(pregnancy == 0){
        if (days%360 > 120 && days%360 < 240){ // haute saison
            inc += 48;
            inc += Utils::randomInt(24); // 60 par jour en moyenne (+/-20%)
        } else{ // saison basse
            inc += 8;
            inc += Utils::randomInt(4); // 10 par jour en moyenne (+/-20%)
        }
    }
    return inc;
}

void Tiger::interact() {
    int Input;
    do {
        cout << "\n** Are you sure you want to pet " << name << "? **" << endl;
        cout << "(1) Pet the tiger" << endl;
        cout << "(0) Go back" << endl;

        string strInput;
        cin >> strInput;
        try {
            Input = stoi(strInput);
        } catch (...) {
            cout << "*unknown input*" << endl;
            Input = -1;
            continue;
        }

        switch (Input) {
            case 1:
                cout << "You got eaten. GAME OVER" << endl;
                exit(0);
            case 0:
                break;
            default:
                cout << "*unknown input*" << endl;
                break;
        }

    } while (Input != 0);
}
