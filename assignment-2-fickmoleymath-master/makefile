CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

LDFLAGS = -lboost_date_time

OBJS = card.o deck.o hand.o player.o game.o

SRCS = card.cpp deck.cpp hand.cpp player.cpp game.cpp gofish.cpp

HEADERS = card.hpp deck.hpp hand.hpp player.hpp game.hpp

recursive: $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o gofish

clean:
	-rm* .o$(OBJS) gofish

