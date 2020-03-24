CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

LDFLAGS = -lboost_date_time

OBJS = animal.o menu.o penguin.o tiger.o turtle.o zoo.o

SRCS = animal.cpp main.cpp menu.cpp monkey.cpp otter.cpp sloth.cpp zoo.cpp

HEADERS = animal.hpp monkey.hpp otter.hpp sloth.hpp menu.hpp zoo.hpp

zooTycoon: $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o zoo

clean:
	-rm* .o$(OBJS) zoo

