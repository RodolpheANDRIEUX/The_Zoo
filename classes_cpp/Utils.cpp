#include "../headers/Utils.h"
#include <random>
#include <iostream>

using namespace std;

int Utils::getRandomNumber() {
    srand((unsigned) time(NULL));

    return rand()%1000;
}