#ifndef UNTITLED1_HABITAT_H
#define UNTITLED1_HABITAT_H


class Habitat {

protected:
    int nbAnimal = 0;
public:
    virtual void show() = 0;

    virtual int getPlace() = 0;
};


#endif //UNTITLED1_HABITAT_H
