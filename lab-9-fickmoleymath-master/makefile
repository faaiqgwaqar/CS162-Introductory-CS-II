CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

LDFLAGS = -lboost_date_time

OBJS = instructor.o level.o location.o maze.o menu.o open.o person.o student.o ta.o wall.o

SRCS = instructor.cpp level.cpp location.cpp main.cpp maze.cpp menu.cpp open.cpp person.cpp student.cpp ta.cpp wall.cpp

HEADERS = instructor.hpp level.hpp location.hpp maze.hpp menu.hpp open.hpp person.hpp student.hpp ta.hpp wall.hpp

escapeFrom162: $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o game

clean:
	-rm* .o$(OBJS) game
