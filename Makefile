CXX = g++
CFLAGS = -g -Wall
driver: driver.o facility.o cell.o
	$(CXX) $(CFLAGS) -o driver driver.o facility.o
	
cell.o: cell.cpp cell.h
	$(CXX) $(CFLAGS) -c cell.cpp

facility.o: facility.cpp facility.h cell.h
	$(CXX) $(CFLAGS) -c facility.cpp
	
driver.o: driver.cpp facility.h cell.h
	$(CXX) $(CFLAGS) -c driver.cpp

clean: 
	$(RM) count *.o *~
