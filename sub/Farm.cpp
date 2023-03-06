//
// Created by ise on 1/5/22.
//
#include <vector>
using namespace std;
#include "Farm.h"
int Farm::PriceMilk=3;
int Farm::PriceWool=2;
int Farm::PriceEggs=1;
int Farm::FarmCounter=0;

Farm::Farm() {
    FarmCounter++;
    ID=FarmCounter;
    Money=10;
    amount_eggs=0;
    amount_milk=0;
    amount_wool=0;
}

Farm::~Farm() {

    for (auto & it : animal_array){
        delete it;
    }
    animal_array.clear();






}

void Farm::SetAmountWool(int amount) {
    if (amount+amount_wool<0){
        return;
    }
    amount_wool=amount_wool+amount;
}

void Farm::SetAmountEggs(int amount) {
    if (amount+amount_eggs<0){
        return;
    }
    amount_eggs=amount_eggs+amount;

}

void Farm::SetAmountMilk(int amount) {
    if (amount+amount_milk<0){
        return;
    }
    amount_milk=amount_milk+amount;

}

void Farm::SetMoney(int amount) {
    if (amount+Money<0){
        return;
    }
    Money=Money+amount;
}

int Farm::getAmountEggs()const {
    return amount_eggs;
}

int Farm::getAmountMilk()const {
    return amount_milk;
}

int Farm::getAmountWool()const {

    return amount_wool;
}

int Farm::GetMoney() const {
    return Money;
}

void Farm::SetAnimalArray() {

    for (auto & it : animal_array) {
        it->setAnimalAge(1);

    }

    for (auto it = animal_array.begin(); it != animal_array.end();){
        if ((*it)->getAnimalDeath()==(*it)->getAnimalAge()) {
            delete *it;
            it = animal_array.erase(it);

        } else {
            ++it;
        }
    }


}