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
        catalog[201] = {"6 month old Tiger", 3000};
        catalog[202] = {"4 years old Tiger", 120000};
        catalog[203] = {"14 years old Tiger", 60000};
        catalog[204] = {"6 month old rooster", 100};
        catalog[205] = {"6 month old  Chicken", 20};
        catalog[206] = {"6 month old Eagle", 1000};
        catalog[207] = {"4 years old Eagle", 4000};
        catalog[208] = {"14 years old Eagle", 2000};
    }

    void openBoutique(Zoo* client);

    void foodMenu(Zoo* client);

    void habitatMenu(Zoo* client);

    void animalMenu(Zoo* client);

    void sell(Zoo* client, int article);
};


#endif //UNTITLED1_AMAZONZOO_H
