//
// Created by ise on 1/5/22.
//

#include "Animal.h"

int Animal::getAnimalAge() const {
    return animal_age;
}



bool Animal::setAnimalAge(int amount) {
    animal_age=animal_age+amount;
    return true;

}