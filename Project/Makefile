PYTHIA8_URL = https://pythia.org/download/pythia83/pythia8311.tgz
PYTHIA8_TGZ = $(notdir $(PYTHIA8_URL))
PYTHIA8_DIR = $(basename $(PYTHIA8_TGZ))

OPT = -g -Wall
INC = -I$(PYTHIA8_DIR)/include
LIBSPY = -L$(PYTHIA8_DIR)/lib -lpythia8 -ldl
LIBSRT = $(shell root-config --libs)
CXXFLAGS = $(shell root-config --cflags)

all: $(PYTHIA8_DIR)
	$(MAKE) main

$(PYTHIA8_DIR):
	wget $(PYTHIA8_URL)
	tar xfvz $(PYTHIA8_TGZ)
	cd $(PYTHIA8_DIR) && ./configure && make

main: main.cc
	$(CXX) $(CXXFLAGS) $(OPT) $(INC) main.cc $(LIBSPY) $(shell root-config --libs) -o main

files = $(wildcard *~ pythia*)
clean:
	rm -rf $(files)

allfiles = $(wildcard main *.out *.eps)
cleanAll:
	$(MAKE) clean
	rm -rf $(allfiles)
