OBJS = src/MET.o

OPT = -O -Wall -fPIC

INC = -Iinclude

LIBS = -L. -lMET

all:
	$(MAKE) libMET.so
	$(CXX) test.cpp $(INC) $(LIBS) -o test

libMET.so: $(OBJS)
	$(CXX) -shared -O $(OBJS) -o libMET.so

.cc.o:
	$(CXX) -c $(OPT) $(INC) $< -o $@



clean:
	rm -f *~ $(OBJS)

cleanAll:
	$(MAKE) clean
	rm -f MET libMET.so test
