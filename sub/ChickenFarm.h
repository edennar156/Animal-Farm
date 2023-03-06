//
// Created by ise on 1/7/22.
//

#ifndef FINALPROJECT_CHICKENFARM_H
#define FINALPROJECT_CHICKENFARM_H
#include "Farm.h"
#include <vector>

using namespace std;

class ChickenFarm: public Farm{


public:
    ChickenFarm();
    ~ChickenFarm() override =default;
    int FarmOutput() override;
    void BuyAnimal() override;
    void SaleProducts() override;
    void handleCowFarm(Farm* Pfarm) override{Pfarm->ChickenFarmWantsToHaveMe(this);};
    void handleSheepFarm(Farm* Pfarm) override{};
    void handleChickenFarm(Farm* Pfarm) override{};
    void SheepFarmWantsToHaveMe(Farm* sheep_farm) override{sheep_farm->AddCustomer(this);};
    void ChickenFarmWantsToHaveMe(Farm* farm) override{};
    void CowFarmWantsToHaveMe(Farm* farm) override { };
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
    void AddCustomer(Farm* cowFarm) override;


};


#endif //FINALPROJECT_CHICKENFARM_H
