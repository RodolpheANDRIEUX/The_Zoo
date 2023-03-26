
#include "Habitat.h"
#include "Eagle.h"
#include <vector>
using namespace std;

#ifndef UNTITLED1_EAGLEAVIARY_H
#define UNTITLED1_EAGLEAVIARY_H



class EagleAviary : public Habitat{

public:
    Animal* show() override;

    int getPlace() override;

    pair<int, int> receive(Animal *newAnimal) override;

    void checkOverCrowding() override;

    void dailyRoutine(int date) override;

    int sell() override;

    string getType() override;
};


#endif //UNTITLED1_EAGLEAVIARY_H
