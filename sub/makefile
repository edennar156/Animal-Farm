prog: Animal.o Cow.o Chicken.o Sheep.o Farm.o ChickenFarm.o SheepFarm.o CowFarm.o farmMarket.o Market.o   
	g++ -g Animal.o Cow.o Chicken.o Sheep.o Farm.o ChickenFarm.o SheepFarm.o CowFarm.o farmMarket.o Market.o -o CPP_FARM
Animal.o: Animal.cpp Animal.h
	g++ -c Animal.cpp -g
Cow.o: Cow.cpp Cow.h Animal.h
	g++ -c Cow.cpp -g
Chicken.o: Chicken.cpp Chicken.h Animal.h
	g++ -c Chicken.cpp -g
Sheep.o: Sheep.cpp Sheep.h Animal.h
	g++ -c Sheep.cpp -g
Farm.o: Farm.cpp Farm.h Animal.h Chicken.h Cow.h Sheep.h
	g++ -c Farm.cpp -g
ChickenFarm.o: ChickenFarm.cpp ChickenFarm.h Farm.h Animal.h Chicken.h Cow.h Sheep.h
	g++ -c ChickenFarm.cpp -g
SheepFarm.o: SheepFarm.cpp SheepFarm.h Farm.h Animal.h Chicken.h Cow.h Sheep.h
	g++ -c SheepFarm.cpp -g
CowFarm.o: CowFarm.cpp CowFarm.h Farm.h Animal.h Chicken.h Cow.h Sheep.h
	g++ -c CowFarm.cpp -g
farmMarket.o: farmMarket.cpp Market.h CowFarm.h Farm.h Animal.h Chicken.h Cow.h Sheep.h ChickenFarm.h SheepFarm.h
	g++ -c farmMarket.cpp -g
Market.o: Market.cpp Market.h CowFarm.h Farm.h Animal.h Chicken.h Cow.h Sheep.h ChickenFarm.h SheepFarm.h
	g++ -c Market.cpp -g

clean:
	rm -f *.o
