CXX = g++
CFLAGS = -g -Wall -std=c++11
driver: driver.o facility.o cell.o road.o restaurant.o park.o zoo.o animal.o habitat.o wolf.o lion.o zebra.o elephant.o hog.o
	$(CXX) $(CFLAGS) -o driver driver.o facility.o cell.o road.o restaurant.o park.o zoo.o animal.o habitat.o wolf.o lion.o zebra.o elephant.o hog.o
	
cell.o: cell.cpp cell.h
	$(CXX) $(CFLAGS) -c cell.cpp

facility.o: facility.cpp facility.h cell.h
	$(CXX) $(CFLAGS) -c facility.cpp

road.o: road.cpp road.h facility.h
	$(CXX) $(CFLAGS) -c road.cpp

restaurant.o: restaurant.cpp restaurant.h facility.h
	$(CXX) $(CFLAGS) -c restaurant.cpp

park.o: park.cpp park.h facility.h
	$(CXX) $(CFLAGS) -c park.cpp

zoo.o: zoo.cpp zoo.h
	$(CXX) $(CFLAGS) -c zoo.cpp

habitat.o: habitat.cpp habitat.h
	$(CXX) $(CFLAGS) -c habitat.cpp

driver.o: driver.cpp
	$(CXX) $(CFLAGS) -c driver.cpp

wolf.o: realAnimals/wolf.cpp
	$(CXX) $(CFLAGS) -c realAnimals/wolf.cpp

lion.o: realAnimals/lion.cpp
	$(CXX) $(CFLAGS) -c realAnimals/lion.cpp

zebra.o: realAnimals/zebra.cpp
	$(CXX) $(CFLAGS) -c realAnimals/zebra.cpp

elephant.o: realAnimals/elephant.cpp
	$(CXX) $(CFLAGS) -c realAnimals/elephant.cpp

hog.o: realAnimals/hog.cpp
	$(CXX) $(CFLAGS) -c realAnimals/hog.cpp

clean: 
	$(RM) count *.o *~
