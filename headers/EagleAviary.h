
#include "Habitat.h"
#include "Eagle.h"
#include <vector>
using namespace std;

#ifndef UNTITLED1_EAGLEAVIARY_H
#define UNTITLED1_EAGLEAVIARY_H



class EagleAviary : public Habitat{

public:
    void show() override;

    int getPlace() override;

    pair<int, int> receive(Animal *newAnimal) override;
};


#endif //UNTITLED1_EAGLEAVIARY_H
