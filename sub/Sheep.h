//
// Created by ise on 1/6/22.
//

#ifndef FINALPROJECT_SHEEP_H
#define FINALPROJECT_SHEEP_H
#include "Animal.h"
#include <string>
#include <iostream>
using namespace std;


class Sheep :public Animal{
public:
    Sheep(){animal_age=0;animal_price=5;animal_death_age=5;}
    ~Sheep() override =default;
    int getAnimalAge()const override;
    int getAnimalPrice()const override;
    int getAnimalDeath()const override;


};


#endif //FINALPROJECT_SHEEP_H
