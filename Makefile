CXX=g++
CXXFLAGS=-g -Wall
COMPILE=$(CXX) $(CXXFLAGS)

all: build battleship

battleship: src/main.cpp out/grid.o out/player.o out/game.o
	$(COMPILE) $< out/*.o -o $@

out/grid.o: src/grid.cpp src/grid.hpp out
	$(COMPILE) -c $< -o $@

out/player.o: src/player.cpp src/player.hpp out
	$(COMPILE) -c $< -o $@

out/game.o: src/game.cpp src/game.hpp out
	$(COMPILE) -c $< -o $@

build:
	mkdir -p out

clean:
	rm -rf out battleship

.PHONY: build clean
