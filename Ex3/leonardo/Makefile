FILE = twod

Library:	$(FILE).cpp	$(FILE).h
	$(MAKE) twod.so

twod.so:
	g++ -c $(FILE).cpp -o $(FILE).o
	g++ -shared $(FILE).o -o $(FILE).so
	
test.out:	twod.so
	g++ -c main.cpp -o main.o
	g++ main.o -L. twod.so -o test.out -Wl,-rpath,$(PWD)

clean:
	rm *.o
	
cleanAll:
	rm *.so *.out *.o
