TRK = fourmoment
SIM = simulated

Library:	$(TRK).cpp	$(TRK).h $(SIM).cpp	$(SIM).h 
	@$(MAKE) fsim.so
	@echo Track Library Completed
	@$(MAKE) test.out
	@echo Test file completed

fsim.so:
	@g++ -c $(TRK).cpp -o $(TRK).o -fPIC
	@g++ -c $(SIM).cpp -o $(SIM).o -fPIC
	@g++ -shared $(TRK).o $(SIM).o -o fsim.so
	
test.out:	$(SIM).so
	@g++ -c main.cpp -o main.o
	@g++ main.o -L. -l:fsim.so -o test.out -Wl,-rpath,$(PWD)

clean:
	rm *.o
	
cleanAll:
	rm *.so *.out *.o
