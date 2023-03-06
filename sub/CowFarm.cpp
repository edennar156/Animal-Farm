//
// Created by ise on 1/7/22.
//

#include "CowFarm.h"
#include "Cow.h"
#include <iostream>
using namespace std;
CowFarm::CowFarm() {
    animal_array.push_back(new Cow);
    animal_array.push_back(new Cow);
    animal_array.push_back(new Cow);
}


int CowFarm::FarmOutput() {
    int sum=0;
    for(auto & it : animal_array){
        sum = sum + it->getAnimalAge();

    }
    amount_milk=amount_milk+sum;
    return sum;

}

void CowFarm::BuyAnimal() {
    Cow cow;
    if (Money<cow.getAnimalPrice()){
        return ;
    }
    int AnimalToBuy=Money/ cow.getAnimalPrice();

    for (int i = 0; i < AnimalToBuy; ++i) {
        animal_array.push_back(new Cow());


    }
    this->Money=this->Money-cow.getAnimalPrice()*AnimalToBuy;
    cout<<"Cow farm("<< to_string(ID)<<") bought "<< to_string(AnimalToBuy)<<" cows for "<<
    to_string(cow.getAnimalPrice()*AnimalToBuy)<<" dollars"<<endl;
}


void CowFarm::SetAmountWool(int amount) {
    if (amount+amount_wool<0){
        return;
    }
    amount_wool=amount_wool+amount;
}

void CowFarm::SetAmountEggs(int amount) {
    if (amount+amount_eggs<0){
        return;
    }
    amount_eggs=amount_eggs+amount;

}

void CowFarm::SetAmountMilk(int amount) {
    if (amount+amount_milk<0){
        return;
    }
    amount_milk=amount_milk+amount;

}

void CowFarm::SetMoney(int amount) {
    if (amount+Money<0){
        return;
    }
    Money=Money+amount;
}


void CowFarm::SaleProducts() {
    int amount=0;
    if (amount_milk==0){
        return;
    }

    for (auto & sheep : Customers){
        int x = sheep->GetMoney()/PriceMilk;
        for (int i = 0; i < x; ++i) {
            if (this->amount_milk-1<0){
                break;
            }
            this->Money= this->Money+PriceMilk;
            amount_milk=amount_milk-1;
            sheep->SetMoney(-PriceMilk);
            sheep->SetAmountMilk(1);
            amount++;

        }
        if (amount!=0){

            std::cout<<"Sheep farm("<<std::to_string(sheep->getID())<<") bought "<<std::to_string(amount)<<" milk for "<<
            std::to_string(amount*PriceMilk)<<" dollars from Cow farm("<< std::to_string(ID)<<")"<<std::endl;
        }
        amount=0;


    }


}

void CowFarm::PrintFarm() {
    std::cout << "Farm Id: " <<std::to_string(ID) <<", type: Cow farm, Money: "<<std::to_string(Money)<<", Animals: "
              <<std::to_string(animal_array.size())<<" cows, Products: Milk["<<std::to_string(amount_milk)<<"], Wool["<<
              std::to_string(amount_wool)<<"], Eggs["<<std::to_string(amount_eggs)<<"]"<<
              std::endl;

}

void CowFarm::AddCustomer(Farm *sheepFarm) {
    Customers.push_back(sheepFarm);
    cout<<"Cow farm("<<to_string(ID)<<") Added Sheep farm("<<to_string(sheepFarm->getID())<<") to his client list"<<endl;
}

