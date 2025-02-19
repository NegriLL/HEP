OPT = -O -Wall -fPIC

INC = -Iinclude

LIBS = $(shell root-config --libs)
CXX = $(shell root-config --cxx)
CXXFLAGS = $(shell root-config --cflags)

all:
	@ $(CXX) $(CXXFLAGS) hist.cpp $(INC) $(LIBS) -o histogram

%o : %.C
	@ $(CXX) $(CXXFLAGS) -c $(OPT) $(INC) $< -o $@

clean:
	@ rm random_numbers.root

cleanAll:
	@ rm histogram
	@ $(MAKE) clean
