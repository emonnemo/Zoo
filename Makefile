CXX = g++
CFLAGS = -g -Wall -std=c++11
driver: driver.o facility.o cell.o
	$(CXX) $(CFLAGS) -o driver driver.o facility.o
	
cell.o: cell.cpp cell.h
	$(CXX) $(CFLAGS) -c cell.cpp

facility.o: facility.cpp facility.h cell.h
	$(CXX) $(CFLAGS) -c facility.cpp

road.o: road.cpp road.h cell.h
	$(CXX) $(CFLAGS) -c road.cpp

entrance.o: entrance.cpp entrance.h cell.h
	$(CXX) $(CFLAGS) -c entrance.cpp

exit.o: exit.cpp exit.h cell.h
	$(CXX) $(CFLAGS) -c exit.cpp

restaurant.o: restaurant.cpp restaurant.h cell.h
	$(CXX) $(CFLAGS) -c restaurant.cpp

park.o: park.cpp park.h cell.h
	$(CXX) $(CFLAGS) -c park.cpp
	
driver.o: driver.cpp facility.h cell.h
	$(CXX) $(CFLAGS) -c driver.cpp

clean: 
	$(RM) count *.o *~
