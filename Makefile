COMPILER=g++
OPTIONS=-g -Wall
COMPILE=$(COMPILER) $(OPTIONS)
SOURCE=src
BUILD=out

all: battleship

battleship: $(SOURCE)/main.cpp $(BUILD)/*.o
	$(COMPILE) $< $(BUILD)/*.o -o $@

$(BUILD)/grid.o: $(SOURCE)/grid.cpp $(SOURCE)/grid.hpp out
	$(COMPILE) -c $<

$(BUILD)/game.o: $(SOURCE)/game.cpp $(SOURCE)/game.hpp out
	$(COMPILE) -c $<

$(BUILD)/player.o: $(SOURCE)/player.cpp $(SOURCE)/player.hpp out
	$(COMPILE) -c $<

build:
	mkdir -p $(BUILD)

clean:
	rm -rf $(BUILD) battleship

.PHONY: clean build
