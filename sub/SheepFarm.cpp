//
// Created by ise on 1/7/22.
//

#include "SheepFarm.h"
#include "Sheep.h"
#include <iostream>
using namespace std;
SheepFarm::SheepFarm() {
    animal_array.push_back(new Sheep);
    animal_array.push_back(new Sheep);
    animal_array.push_back(new Sheep);
}


int SheepFarm::FarmOutput() {
    int sum=0;
    for(auto & it : animal_array){
        sum = sum + it->getAnimalAge();

    }
    amount_wool=amount_wool+sum;
    return sum;

}

void SheepFarm::BuyAnimal() {
    Sheep sheep;
    if (Money<sheep.getAnimalPrice()){
        return ;
    }
    int AnimalToBuy=Money/ sheep.getAnimalPrice();
    for (int i = 0; i < AnimalToBuy; ++i) {
        animal_array.push_back(new Sheep());



    }
    this->Money=this->Money-sheep.getAnimalPrice()*AnimalToBuy;
    cout<< "Sheep farm("<< to_string(ID)<<") bought "<< to_string(AnimalToBuy)<<" sheeps for "<<
           to_string(sheep.getAnimalPrice()*AnimalToBuy)<<" dollars"<<endl;
}


void SheepFarm::SetAmountWool(int amount) {
    if (amount+amount_wool<0){
        return;
    }
    amount_wool=amount_wool+amount;
}

void SheepFarm::SetAmountEggs(int amount) {
    if (amount+amount_eggs<0){
        return;
    }
    amount_eggs=amount_eggs+amount;

}

void SheepFarm::SetAmountMilk(int amount) {
    if (amount+amount_milk<0){
        return;
    }
    amount_milk=amount_milk+amount;

}

void SheepFarm::SetMoney(int amount) {
    if (amount+Money<0){
        return;
    }
    Money=Money+amount;
}


void SheepFarm::SaleProducts() {
    if (amount_wool==0){
        return;
    }
    int amount=0;
    for (auto & chicken : Customers){
        int z = chicken->GetMoney()/PriceWool;
        for (int i = 0; i < z; ++i) {
            if (this->amount_wool-1<0){
                break;
            }
            this->Money=this->Money+PriceWool;
            amount_wool=amount_wool-1;
            chicken->SetMoney(-PriceWool);
            chicken->SetAmountWool(1);
            amount++;

        }
        if ( amount!=0){
            std::cout<<"Chicken farm("<<std::to_string(chicken->getID())<<") bought "<<std::to_string(amount)<<" wool for "<<
            std::to_string(amount*PriceWool)<<" dollars from Sheep farm("<< std::to_string(ID)<<")"<<std::endl;
        }
        amount=0;


    }
}

void SheepFarm::PrintFarm() {
    std::cout << "Farm Id: " <<std::to_string(ID) <<", type: Sheep farm, Money: "<<std::to_string(Money)<<", Animals: "
              <<std::to_string(animal_array.size())<<" sheep, Products: Milk["<<std::to_string(amount_milk)<<"], Wool["<<
              std::to_string(amount_wool)<<"], Eggs["<<std::to_string(amount_eggs)<<"]"<<
              std::endl;

}

void SheepFarm::AddCustomer(Farm *chickenFarm) {
    Customers.push_back(chickenFarm);
    cout<<"Sheep farm("<<to_string(ID)<<") Added Chicken farm("<<to_string(chickenFarm->getID())<<") to his client list"<<endl;

}