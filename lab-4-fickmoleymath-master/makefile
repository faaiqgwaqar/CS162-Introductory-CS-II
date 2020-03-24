CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

LDFLAGS = -lboost_date_time

OBJS = gamerule.o

SRCS = gamerule.cpp gofish.cpp

HEADERS = gamerule.hpp

recursive: $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o gofish

clean:
	-rm* .o$(OBJS) gofish

