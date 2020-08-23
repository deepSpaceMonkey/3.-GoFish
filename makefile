# target: dependencies
# <tab> rule

# make (without arguments) executes first rule in file
# Ideally, one target for every object file and a target for final binary. 

final: go_fish.o player.o card.o deck.o 
	g++ -std=c++0x -o test go_fish.o player.o card.o deck.o 
driver: go_fish.cpp player.h card.h deck.h 
	g++ -std=c++0x -c go_fish.cpp
player.o: player.cpp player.h card.h 
	g++ -std=c++0x -c player.cpp
card.o: card.cpp card.h 
	g++ -std=c++0x -c card.cpp
deck.o: deck.cpp deck.h card.h 
	g++ -std=c++0x -c deck.cpp
