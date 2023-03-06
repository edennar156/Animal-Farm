//
// Created by ise on 1/7/22.
//

#ifndef FINALPROJECT_SHEEPFARM_H
#define FINALPROJECT_SHEEPFARM_H
#include "Farm.h"
#include <iostream>
using namespace std;
class SheepFarm :public Farm{
public:
    SheepFarm();
    ~SheepFarm() override =default;
    int FarmOutput() override;
    void BuyAnimal() override;
    void SaleProducts() override;
    void handleCowFarm(Farm* Pfarm) override{};
    void handleSheepFarm(Farm* Pfarm) override{};
    void handleChickenFarm(Farm* Pfarm) override{ Pfarm->SheepFarmWantsToHaveMe(this);};
    void SheepFarmWantsToHaveMe(Farm* farm) override{};
    void ChickenFarmWantsToHaveMe(Farm* farm) override{};
    void CowFarmWantsToHaveMe(Farm* cow_farm) override { cow_farm->AddCustomer(this);};
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
    void AddCustomer(Farm* chickenFarm) override;



};


#endif //FINALPROJECT_SHEEPFARM_H
