cmake_minimum_required(VERSION 3.20)
project(FinalProject)

set(CMAKE_CXX_STANDARD 14)

add_executable(FinalProject farmMarket.cpp Farm.cpp Farm.h Market.cpp Market.h Animal.cpp Animal.h Cow.cpp Cow.h Sheep.cpp Sheep.h Chicken.cpp Chicken.h CowFarm.cpp CowFarm.h SheepFarm.cpp SheepFarm.h ChickenFarm.cpp ChickenFarm.h error.h)
