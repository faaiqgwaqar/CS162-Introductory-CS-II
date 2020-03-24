XXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

LDFLAGS = -lboost_date_time

OBJS = econdata.o

SRCS = econdata.cpp explore_econdata.cpp

HEADERS = econdata.hpp

recursive: $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o econdata

clean:
	-rm* .o$(OBJS) econdata

