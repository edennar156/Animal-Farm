//
// Created by ise on 1/7/22.
//
#include <iostream>
#include "ChickenFarm.h"
#include "Chicken.h"
#include <string>

using namespace std;
ChickenFarm::ChickenFarm() {

    if (animal_array.empty()){
        animal_array.push_back(new Chicken());
        animal_array.push_back(new Chicken());
        animal_array.push_back(new Chicken());
    }


}

int ChickenFarm::FarmOutput() {
    int sum=0;
    for(auto & it : animal_array){
        sum = sum + it->getAnimalAge();

    }
    amount_eggs=amount_eggs+sum;
    return sum;

}

void ChickenFarm::BuyAnimal() {
    Chicken chicken ;
    if (Money<chicken.getAnimalPrice()){

        return ;
    }
    int AnimalToBuy=Money/ chicken.getAnimalPrice();
    for (int i = 0; i < AnimalToBuy; ++i) {
        animal_array.push_back(new Chicken());

    }
    this->Money=this->Money-chicken.getAnimalPrice()*AnimalToBuy;
    cout<< "Chicken farm("<< to_string(ID)<<") bought "<< to_string(AnimalToBuy)<<" chickens for "<<
                  to_string(chicken.getAnimalPrice()*AnimalToBuy)<<" dollars"<<endl;
}


void ChickenFarm::SetAmountWool(int amount) {
    if (amount+amount_wool<0){
        return;
    }
    amount_wool=amount_wool+amount;
}

void ChickenFarm::SetAmountEggs(int amount) {
    if (amount+amount_eggs<0){
        return;
    }
    amount_eggs=amount_eggs+amount;

}

void ChickenFarm::SetAmountMilk(int amount) {
    if (amount+amount_milk<0){
        return;
    }
    amount_milk=amount_milk+amount;

}

void ChickenFarm::SetMoney(int amount) {
    if (amount+Money<0){
        return;
    }
    this->Money=this->Money+amount;
}


void ChickenFarm::SaleProducts() {
    if (amount_eggs==0){
        return;
    }
    int amount=0;
    for (auto & cow : Customers){
        int y = cow->GetMoney()/PriceEggs;
        for (int i = 0; i <y; ++i) {
            if (this->amount_eggs-1<0){
                break;
            }
            this->Money= this->Money+PriceEggs;
            this->amount_eggs=this->amount_eggs-1;
            cow->SetMoney(-PriceEggs);
            cow->SetAmountEggs(1);
            amount++;

        }
        if ( amount!=0){

            std::cout<<"Cow farm("<<std::to_string(cow->getID())<<") bought "<<std::to_string(amount)<<" eggs for "<<
            std::to_string(amount*PriceEggs)<<" dollars from Chicken farm("<< std::to_string(ID)<<")"<<std::endl;
        }
        amount=0;


    }
}

void ChickenFarm::PrintFarm() {
    std::cout << "Farm Id: " <<std::to_string(ID) <<", type: Chicken Farm, Money: "<<std::to_string(Money)<<", Animals: "
    <<std::to_string(animal_array.size())<<" chickens, Products: Milk["<<std::to_string(amount_milk)<<"], Wool["<<
    std::to_string(amount_wool)<<"], Eggs["<<std::to_string(amount_eggs)<<"]"<<
    std::endl;

}

void ChickenFarm::AddCustomer(Farm *cowFarm) {
    Customers.push_back(cowFarm);
    cout<<"Chicken farm("<<to_string(ID)<<") Added Cow farm("<<to_string(cowFarm->getID())<<") to his client list"<<endl;
}