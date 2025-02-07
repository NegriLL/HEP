OBJRT = src/RT.o
OBJSP = src/SP.o

OPT = -O -Wall -fPIC

INC = -Iinclude

LIBS = -L. -lRT -lSP

all:
	$(MAKE) libRT.so
	$(MAKE) libSP.so
	$(CXX) test.cpp $(INC) $(LIBS) -o test

libRT.so: $(OBJRT)
	$(CXX) -shared -O $(OBJRT) -o libRT.so
	
libSP.so: $(OBJSP)
	$(CXX) -shared -O $(OBJSP) -o libSP.so -L. -lRT

.cc.o:
	$(CXX) -c $(OPT) $(INC) $< -o $@

clean:
	rm -f *~ $(OBJRT) $(OBJSP)

cleanAll:
	$(MAKE) clean
	rm -f RT libRT.so test SP libSP.so 
