CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

LDFLAGS = -lboost_date_time

OBJS = shape.o rectangle.o circle.o square.o

SRCS = shape.cpp rectangle.cpp circle.cpp square.cpp main.cpp

HEADERS = shape.hpp rectangle.hpp circle.hpp square.hpp

zooTycoon: $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o shape

clean:
	-rm* .o$(OBJS) shape

