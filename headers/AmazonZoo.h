#include "Zoo.h"
#include <map>

#ifndef UNTITLED1_AMAZONZOO_H
#define UNTITLED1_AMAZONZOO_H


class AmazonZoo {
    map<int, pair<string, double>> catalog;

public:
    AmazonZoo(){
        // FOOD
        catalog[1] = {"Meat", 5.00};
        catalog[2] = {"Grains", 2.50};
        // HABITATS
        catalog[101] = {"Tiger Enclosure", 2000};
        catalog[102] = {"Chicken Coop", 300};
        catalog[103] = {"Eagle Aviary", 2000};
        // ANIMALS
        catalog[201] = {"6 month getOld Male Tiger", 3000};
        catalog[202] = {"6 month getOld Female Tiger", 3000};
        catalog[203] = {"4 years getOld Male Tiger", 120000};
        catalog[204] = {"4 years getOld Female Tiger", 120000};
        catalog[205] = {"14 years getOld Male Tiger", 60000};
        catalog[206] = {"14 years getOld Female Tiger", 60000};
        catalog[207] = {"6 month getOld rooster", 100};
        catalog[208] = {"6 month getOld  Chicken", 20};
        catalog[209] = {"6 month getOld Male Eagle", 1000};
        catalog[210] = {"6 month getOld Female Eagle", 1000};
        catalog[211] = {"4 years getOld Male Eagle", 4000};
        catalog[212] = {"4 years getOld Female Eagle", 4000};
        catalog[213] = {"14 years getOld Male Eagle", 2000};
        catalog[214] = {"14 years getOld Female Eagle", 2000};

    }

    void openBoutique(Zoo *client);

    void foodMenu(Zoo *client);

    void habitatMenu(Zoo *client);

    void animalMenu(Zoo *client);

    void ageMenu(Zoo *client, int animalID);

    void sell(Zoo *client, int article);

    void sexeMenu(Zoo *client, int articleID);

    void placeAnimal(Zoo *client, int article);
};


#endif //UNTITLED1_AMAZONZOO_H
