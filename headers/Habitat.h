#ifndef UNTITLED1_HABITAT_H
#define UNTITLED1_HABITAT_H


#include "Animal.h"
#include <vector>

class Habitat {

protected:
    int nbAnimal = 0;
    vector<Animal*> Animals;
public:
    // La méthode getAnimals peut être modulable avec des code passé en paramètre.
    void getAnimals(int code);

    virtual void show() = 0;

    virtual int getPlace() = 0;

    virtual pair<int, int> receive(Animal *newAnimal) = 0;

    int getNbAnimals() const;

    bool checkHabitat();
};


#endif //UNTITLED1_HABITAT_H
