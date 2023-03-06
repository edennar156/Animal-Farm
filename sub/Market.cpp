//
// Created by ise on 1/5/22.
//

#include "Market.h"
#include "CowFarm.h"
#include "SheepFarm.h"
#include "ChickenFarm.h"
#include <algorithm>
#include <iostream>
#include "error.h"
Market::Market() {
    year=0;

}
Market::~Market() {
    for (auto & it : FarmsInMarket){

        delete it;
    }

    FarmsInMarket.clear();
}

void Market::CreateNewFarms(Farm* farm_type) {


    if (FarmsInMarket.empty()){
        FarmsInMarket.push_back(farm_type);
    }
    else{
        for (auto & it : FarmsInMarket){
            farm_type->handleSheepFarm(it);
            farm_type->handleChickenFarm(it);
            farm_type->handleCowFarm(it);
            it->handleSheepFarm(farm_type);
            it->handleChickenFarm(farm_type);
            it->handleCowFarm(farm_type);



        }
        FarmsInMarket.push_back(farm_type);

    }

}


void Market::TradeDay() {
    cout<<"----Begin Market----"<<endl;
    for (auto & it : FarmsInMarket){
        it->SaleProducts();
    }
    cout<<"----Buy Animals----"<<endl;
    for (auto & it : FarmsInMarket){
        it->BuyAnimal();
    }
    year++;
    for (auto & it1 : FarmsInMarket){
        it1->SetAnimalArray();
        it1->SetMoney(10);

    }

}

void Market::nextYear() {
    cout<<"----Creating new farms----"<<endl;
    int cow_farm;
    int sheep_farm;
    int chicken_farm;
    int flag=1;
    while (flag<2){
        cout<<"How many new cow farms will be added this year?"<<endl;
        cin>>cow_farm;
        try{
            CreateCow(cow_farm);
        }
        catch (exception& e) {
            cout<<e.what()<<endl;
            continue;

        }

        cout<<"How many new sheep farms will be added this year?"<<endl;
        cin>>sheep_farm;
        try{
            CreateSheep(sheep_farm);
        }
        catch (exception& e) {
            cout<<e.what()<<endl;
            continue;

        }
        cout<<"How many new chicken farms will be added this year?"<<endl;
        cin>>chicken_farm;
        try{
            CreateChicken(chicken_farm);
        }
        catch (exception& e) {
            cout<<e.what()<<endl;
            continue;

        }
        flag=2;


    }

    cout<<"----Adding new farms to market----"<<endl;


    for (int i = 0; i < cow_farm; ++i) {
        CreateNewFarms(new CowFarm());
    }
    for (int i = 0; i < sheep_farm; ++i) {
        CreateNewFarms(new SheepFarm());
    }
    for (int i = 0; i < chicken_farm; ++i) {
        CreateNewFarms(new ChickenFarm());
    }
    for (auto & it : FarmsInMarket){
        it->FarmOutput();
    }
    this->TradeDay();

}

void Market::fastForwardYears() {
    int years_to_fast_forward;
    cout<<"How many years to fast forward?"<<endl;
    cin>>years_to_fast_forward;
    for (int i = 0; i < years_to_fast_forward; ++i) {
        for (auto & it : FarmsInMarket){
            it->FarmOutput();
        }
        this->TradeDay();

    }

}

void Market::printMarketFarms() {
    cout<<"----Market Farms----"<<endl;
    for (auto & it : FarmsInMarket){
        it->PrintFarm();
    }

}

void Market::CreateCow(int num) {
    if (num<0){
        throw CowException();
    }

}

void Market::CreateSheep(int num) {
    if (num<0){
        throw SheepException();
    }
}

void Market::CreateChicken(int num) {
    if(num<0){
        throw ChickenException();
    }
}