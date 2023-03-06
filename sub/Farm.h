//
// Created by ise on 1/5/22.
//

#ifndef FINALPROJECT_FARM_H
#define FINALPROJECT_FARM_H
#include "Animal.h"
#include <vector>
using namespace std;
class Farm {
protected:
    vector<Farm*> Customers;
    int ID;
    int Money;
    int amount_eggs;
    int amount_milk;
    int amount_wool;
    vector<Animal*> animal_array;
    static int FarmCounter;
    static int PriceMilk;
    static int PriceWool;
    static int PriceEggs;

public:
    Farm();
    virtual ~Farm();
    virtual int FarmOutput()=0;
    virtual void SaleProducts()=0;
    virtual void BuyAnimal()=0;
    virtual void PrintFarm()=0;
    virtual void handleCowFarm(Farm*)=0;
    virtual void handleSheepFarm(Farm*)=0;
    virtual void handleChickenFarm(Farm*)=0;
    virtual void SheepFarmWantsToHaveMe(Farm*)=0;
    virtual void ChickenFarmWantsToHaveMe(Farm*)=0;
    virtual void CowFarmWantsToHaveMe(Farm*)=0;
    virtual void SetAmountMilk(int amount);
    virtual void SetAmountWool(int amount);
    virtual void SetAmountEggs(int amount);
    virtual void SetMoney(int amount);
    virtual int GetMoney()const;
    virtual int getAmountMilk()const;
    virtual int getAmountWool()const;
    virtual int getAmountEggs()const;
    virtual int getID()const{return ID;};
    virtual void AddCustomer(Farm*)=0;
    virtual void SetAnimalArray();



};


#endif //FINALPROJECT_FARM_H
