//
// Created by ise on 1/5/22.
//

#ifndef FINALPROJECT_ANIMAL_H
#define FINALPROJECT_ANIMAL_H
#include <string>
using namespace std;
class Animal {
protected:
    int animal_age;
    int animal_price;
    int animal_death_age;
public:
    Animal(){animal_age=0,animal_price=0,animal_death_age=0;}
    virtual ~Animal()=default;
    virtual int getAnimalAge()const;
    virtual int getAnimalPrice()const=0;
    virtual int getAnimalDeath()const=0;
    virtual bool setAnimalAge(int amount);







};


#endif //FINALPROJECT_ANIMAL_H
