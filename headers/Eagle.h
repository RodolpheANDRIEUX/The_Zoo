#include "Animal.h"

#ifndef UNTITLED1_EAGLE_H
#define UNTITLED1_EAGLE_H


class Eagle : public Animal {

public:
    Eagle(string name, int age, bool female) : Animal(std::move(name), age, female){}

    void sayHi() override;
};


#endif //UNTITLED1_EAGLE_H
