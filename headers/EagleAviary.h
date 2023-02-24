
#include "Habitat.h"
#include "Eagle.h"
#include <vector>
using namespace std;

#ifndef UNTITLED1_EAGLEAVIARY_H
#define UNTITLED1_EAGLEAVIARY_H



class EagleAviary : public Habitat{
    vector<Eagle*> eagles;

public:
    void show() override;

    int getPlace() override;
};


#endif //UNTITLED1_EAGLEAVIARY_H
