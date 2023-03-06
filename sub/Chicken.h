//
// Created by ise on 1/6/22.
//

#ifndef FINALPROJECT_CHICKEN_H
#define FINALPROJECT_CHICKEN_H
#include "Animal.h"
#include <string>
#include <iostream>
using namespace std;

class Chicken: public Animal{


public:

    Chicken(){animal_age=0;animal_price=3;animal_death_age=3;}
    ~Chicken() override =default;
    int getAnimalAge()const override;
    int getAnimalPrice()const override;
    int getAnimalDeath()const override;



};


#endif //FINALPROJECT_CHICKEN_H
