#include <random>
#include "../headers/Chicken.h"

void Chicken::show() {
    cout << name << "(" << ((age/30 <= 6) ? "baby " : "") << ((female) ? "hen) - " : "rooster) - ");
    cout << ((age/30 <= 12) ? to_string(age/30) + " month old (" + to_string(age) + " days) ": to_string(age/360) + "years old (" + to_string(age) + " days) ");
    cout << ((sickCoolDown > 0)? "" : "not ") << "sick and " << ((hungry)? "" : "not ") << "hungry" << ((sickCoolDown > 0 || hungry)? "     /!\\" : "") << endl;
}

bool Chicken::handleSickness() {
    if(sickCoolDown > 0 && Utils::tirage(2400)){ // -20% / +infinity esperance: 5j
        sickCoolDown--;
        if (Utils::tirage(60)) { // en moyenne 10% de mortalité sur la durée esperée de la maladie
            kill(7);
            return true;
        }
        return false;
    }
    if(Utils::tirage(10) && Utils::tirage(125)) {
        sickCoolDown = 4; // durée esperée -20%
    }
    return false;
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
        return age >= 180 && age <= 2880 && pregnancy == 0 && shyCoolDown == 0 && sickCoolDown == 0 && !hungry;
    } else { // for male
        return age >= 180 && age <= 2880 && shyCoolDown == 0 && sickCoolDown == 0 && !hungry;
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

int Chicken::sell() {
    if(female) {
        return 10;
    }
    return 20;
}

double Chicken::getDailyIncomes(int days) {
    double inc = 0;
    if (pregnancy < 1){
        if (days%360 > 120 && days%360 < 240){ // haute saison
            inc += 3.2;
            inc += Utils::randomInt(2); // 4 par jour en moyenne (+/-30%)
        } else{
            inc += 0.5;
            inc += Utils::randomInt(1); // 1 par jour en moyenne (+/-50%)
        }
    }
    return inc;
}

void Chicken::interact() {
    vector<string> responses = {"cot cot...", "cot?!", "cot cot cot cot cot cot cot cot.", "yes i know that", "nah C++ is easy mate", "hey do you have any bugs for me? they are so sweat!"};

    int Input;
    do {
        cout << "\n** Interact with " << name << " **" << endl;
        cout << "(1) 'cot'" << endl;
        cout << "(2) 'cot cot'" << endl;
        cout << "(3) 'cot cot cot'" << endl;
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

        if (Input >= 1 && Input <= 3) {
            int randomIndex = Utils::randomInt(int(responses.size()) - 1);
            cout << name << ": " << responses[randomIndex] << endl;
        } else if (Input != 0) {
            cout << "*unknown input*" << endl;
        }

    } while (Input != 0);
}
