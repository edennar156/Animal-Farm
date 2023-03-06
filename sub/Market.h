//
// Created by ise on 1/5/22.
//

#ifndef FINALPROJECT_MARKET_H
#define FINALPROJECT_MARKET_H
#include <vector>
#include "Farm.h"
#include "Animal.h"

class Market {
    int year;
    vector<Farm*> FarmsInMarket;

public:
    Market();
    ~Market();
    void CreateNewFarms(Farm* farm_type);
    void TradeDay();
    void nextYear();
    void fastForwardYears();
    void printMarketFarms();
    int getYear()const{return year;};
    static void CreateCow(int num);
    static void CreateSheep(int num);
    static void CreateChicken(int num);



};


#endif //FINALPROJECT_MARKET_H
