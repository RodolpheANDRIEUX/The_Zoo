#include "../headers/Utils.h"
#include <random>

using namespace std;

bool Utils::tirage(int probaPerMonth) { // probability per month in % (ex: 1% per month -> 1) (ex: 10% per day -> 10 * 30 -> 300)
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 3000);
    int rnd = dis(gen);
    if (rnd <= probaPerMonth){
        return true;
    }
    return false;
}
