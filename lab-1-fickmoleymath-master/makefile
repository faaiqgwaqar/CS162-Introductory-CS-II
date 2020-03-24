XX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

LDFLAGS = -lboost_date_time

OBJS = muldiv.o

SRCS = muldiv.cpp muldiv_func.cpp

HEADERS = muldiv.hpp

recursive: $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o muldiv

clean:
	-rm* .o$(OBJS) muldiv
