SRCDIR := $(shell pwd)
LIBNAME := libMyAnalysis.so

GARBAGE := $(wildcard *~ *.o)

FILES_SRC := $(wildcard *.cc)
FILES_OBJ := $(patsubst $(SRCDIR)%,$(SRCDIR)%,$(FILES_SRC:.cc=.o))


ROOTINC := $(shell root-config --cflags)
ROOTLIBS := $(shell root-config --glibs)

INC := -I$(SRCDIR) $(ROOTINC)

CXXFLAGS := -O2 -Wall -Wno-unused-local-typedefs -fPIC -D_REENTRANT $(INC) -DSTANDALONE

all:
	$(MAKE) analysisdict.cc
	$(MAKE) $(LIBNAME)

$(LIBNAME): $(FILES_OBJ)
	$(CXX) $(FILES_OBJ) $(LDFLAGS) -shared -o $@

analysisdict.cc: LinkDef.h $(LIB)
	rootcint -f $@ -I$(SRCDIR) -DSTANDALONE MyAnalysis.h LinkDef.h

clean:
	rm $(GARBAGE)

cleanAll:
	$(MAKE) clean
	rm *.so analysisdict* output.root

