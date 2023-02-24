#include "Zoo.h"
#include <map>

#ifndef UNTITLED1_AMAZONZOO_H
#define UNTITLED1_AMAZONZOO_H


class AmazonZoo {
    std::map<int, pair<string, double>> catalog;

public:
    AmazonZoo(){
        catalog[1] = {"Meat", 5.00};
        catalog[2] = {"Grains", 2.50};
        catalog[3] = {"", 0};
    }

    static void openBoutique(Zoo* client);

    void foodMenu(Zoo* client);

    void habitatMenu(Zoo* client);

    void animalMenu(Zoo* client);

    void sell(Zoo* client, int article);
};


#endif //UNTITLED1_AMAZONZOO_H
