#include "Habitat.h"
#include "Tiger.h"

#ifndef UNTITLED1_TIGERENCLOSURE_H
#define UNTITLED1_TIGERENCLOSURE_H


class TigerEnclosure : public Habitat{

public:
    Animal* show() override;

    int getPlace() override;

    pair<int, int> receive(Animal *newAnimal) override;

    void checkOverCrowding() override;

    void dailyRoutine(int date) override;

    int sell() override;

    string getType() override;
};


#endif //UNTITLED1_TIGERENCLOSURE_H
