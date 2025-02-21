OPT = -O -Wall -fPIC

INC = -Iinclude

LIBS = $(shell root-config --libs)
CXX = $(shell root-config --cxx)
CXXFLAGS = $(shell root-config --cflags)

all:
	@ $(CXX) $(CXXFLAGS) makeTree.cpp $(INC) $(LIBS) -o makeTree
	@ $(CXX) $(CXXFLAGS) makeHist.cpp $(INC) $(LIBS) -o makeHist

%o : %.C
	@ $(CXX) $(CXXFLAGS) -c $(OPT) $(INC) $< -o $@

clean:
	@ rm random_numbers.root

cleanAll:
	@ rm makeTree makeHist
	@ $(MAKE) clean
