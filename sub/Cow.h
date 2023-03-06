//
// Created by ise on 1/6/22.
//

#ifndef FINALPROJECT_COW_H
#define FINALPROJECT_COW_
#include "Animal.h"
#include <string>
#include <iostream>
using namespace std;


class Cow: public Animal{
public:
    Cow(){animal_age=0;animal_price=10;animal_death_age=10;}
    ~Cow() override =default;
    int getAnimalAge()const override;
    int getAnimalPrice()const override;
    int getAnimalDeath()const override;


};


#endif //FINALPROJECT_COW_H
