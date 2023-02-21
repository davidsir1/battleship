CXX=g++
CXXFLAGS=-g -Wall
COMPILE=$(CXX) $(CXXFLAGS)

OBJS=main.o grid.o player.o game.o

battleship: $(OBJS)
	$(COMPILE) out/*.o -o $@

main.o: src/main.cpp
	$(COMPILE) -c src/main.cpp -o out/$@

grid.o: src/grid.cpp
	$(COMPILE) -c src/grid.cpp -o out/$@

player.o: src/player.cpp
	$(COMPILE) -c src/player.cpp -o out/$@

game.o: src/game.cpp
	$(COMPILE) -c src/game.cpp -o out/$@

clean:
	rm -rf out/*.o battleship

