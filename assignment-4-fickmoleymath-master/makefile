CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

LDFLAGS = -lboost_date_time

OBJS = bats.o gold.o map.o menu.o pit.o room.o wumpus.o

SRCS = bats.cpp event.cpp gold.cpp main.cpp map.cpp menu.cpp pit.cpp room.cpp wumpus.cpp

HEADERS = bats.hpp event.hpp gold.hpp map.hpp menu.hpp pit.hpp room.hpp wumpus.hpp

huntTheWumpus: $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o game

clean:
	-rm* .o$(OBJS) game
