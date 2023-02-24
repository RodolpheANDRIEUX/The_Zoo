
#include "Habitat.h"
#include "Tiger.h"

#ifndef UNTITLED1_TIGERENCLOSURE_H
#define UNTITLED1_TIGERENCLOSURE_H


class TigerEnclosure : public Habitat{
    Tiger* tiger1 = nullptr;
    Tiger* tiger2 = nullptr;

public:
    void show() override;

    int getPlace() override;
};


#endif //UNTITLED1_TIGERENCLOSURE_H
