PYTHIA8_URL = https://pythia.org/download/pythia83/pythia8311.tgz
PYTHIA8_TGZ = $(notdir $(PYTHIA8_URL))
PYTHIA8_DIR = $(basename $(PYTHIA8_TGZ))

OPT = -g -Wall
INC = -I$(PYTHIA8_DIR)/include
LIBS = -L$(PYTHIA8_DIR)/lib -lpythia8 -ldl

all: $(PYTHIA8_DIR)
	$(MAKE) main

$(PYTHIA8_DIR):
	wget $(PYTHIA8_URL)
	tar xfvz $(PYTHIA8_TGZ)
	cd $(PYTHIA8_DIR) && ./configure && make

main: main.cc
	$(CXX) $(OPT) $(INC) main.cc $(LIBS) -o main

files = $(wildcard *~ pythia*)
clean:
	rm -rf $(files)

allfiles = $(wildcard main *.out *.eps)
cleanAll:
	$(MAKE) clean
	rm -rf $(allfiles)
