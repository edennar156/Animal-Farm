//
// Created by ise on 1/7/22.
//

#ifndef FINALPROJECT_COWFARM_H
#define FINALPROJECT_COWFARM_H
#include "Farm.h"
#include <iostream>
using namespace std;

class CowFarm :public Farm{
public:
    CowFarm();
    ~CowFarm() override =default;
    int FarmOutput() override;
    void BuyAnimal() override;
    void SaleProducts() override;
    void handleCowFarm(Farm* Pfarm) override{};
    void handleSheepFarm(Farm* Pfarm) override{return Pfarm->CowFarmWantsToHaveMe(this);};
    void handleChickenFarm(Farm* Pfarm) override{};
    void SheepFarmWantsToHaveMe(Farm* farm) override{};
    void ChickenFarmWantsToHaveMe(Farm* chicken_farm) override{return chicken_farm->AddCustomer(this);};
    void CowFarmWantsToHaveMe(Farm* farm) override {};
    void PrintFarm() override;
    void SetAmountMilk(int amount) override;
    void SetAmountWool(int amount) override;
    void SetAmountEggs(int amount) override;
    void SetMoney(int amount) override;
    int GetMoney()const override{return Money;};
    int getAmountMilk()const override{return amount_milk;};
    int getAmountWool()const override{return amount_wool;};
    int getAmountEggs()const override{return amount_eggs;};
    int getID()const override{return ID;};
    void AddCustomer(Farm* sheepFarm) override;



};


#endif //FINALPROJECT_COWFARM_H
