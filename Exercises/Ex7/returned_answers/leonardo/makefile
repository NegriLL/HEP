INC = -I/home/$(USER)/FeynHiggs-2.19.0/build
LIB = -L/home/$(USER)/FeynHiggs-2.19.0/build/ -lFH -lstdc++

all:
	gfortran FHWidths.cc $(INC) $(LIB) -o FHWidths.exe
	
cleanAll:
	rm *.png *.exe results.txt
