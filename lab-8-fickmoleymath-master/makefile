CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

LDFLAGS = -lboost_date_time

OBJS = matrix.o

SRCS = matrix.cpp main.cpp

HEADERS = matrix.hpp

matrix: $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o matrix

clean:
	-rm* .o$(OBJS) matrix
