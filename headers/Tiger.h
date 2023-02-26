#include <utility>
#include "Animal.h"

#ifndef UNTITLED1_TIGER_H
#define UNTITLED1_TIGER_H


class Tiger : public Animal {

public:
    Tiger(string name, int age, bool female) : Animal(std::move(name), age, female){}

    void show() override;

    void getOld();
};


#endif //UNTITLED1_TIGER_H
