CXX = g++
CFLAGS = -g -Wall -std=c++11
main: main.o menu.o facility.o renderable.o cell.o road.o restaurant.o park.o zoo.o animal.o habitat.o wolf.o lion.o zebra.o elephant.o hog.o macaque.o shark.o morayeel.o dugong.o turtle.o dolphin.o whale.o eagle.o owl.o hummingbird.o cockatoo.o robin.o bat.o penguin.o hippopotamus.o pelican.o goose.o crane.o draco_lizard.o colugo.o sugar_glider.o
	$(CXX) $(CFLAGS) -o main main.o menu.o facility.o renderable.o cell.o road.o restaurant.o park.o zoo.o animal.o habitat.o wolf.o lion.o zebra.o elephant.o hog.o macaque.o shark.o morayeel.o dugong.o turtle.o dolphin.o whale.o eagle.o owl.o hummingbird.o cockatoo.o robin.o bat.o penguin.o hippopotamus.o pelican.o goose.o crane.o draco_lizard.o colugo.o sugar_glider.o
	
menu.o: menu.cpp menu.h zoo.h
	$(CXX) $(CFLAGS) -c menu.cpp

cell.o: cell.cpp cell.h renderable.h
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

macaque.o: realAnimals/macaque.cpp
	$(CXX) $(CFLAGS) -c realAnimals/macaque.cpp

shark.o: realAnimals/shark.cpp
	$(CXX) $(CFLAGS) -c realAnimals/shark.cpp

morayeel.o: realAnimals/morayeel.cpp
	$(CXX) $(CFLAGS) -c realAnimals/morayeel.cpp

dugong.o: realAnimals/dugong.cpp
	$(CXX) $(CFLAGS) -c realAnimals/dugong.cpp

turtle.o: realAnimals/turtle.cpp
	$(CXX) $(CFLAGS) -c realAnimals/turtle.cpp

dolphin.o: realAnimals/dolphin.cpp
	$(CXX) $(CFLAGS) -c realAnimals/dolphin.cpp

whale.o: realAnimals/whale.cpp
	$(CXX) $(CFLAGS) -c realAnimals/whale.cpp

eagle.o: realAnimals/eagle.cpp
	$(CXX) $(CFLAGS) -c realAnimals/eagle.cpp

owl.o: realAnimals/owl.cpp
	$(CXX) $(CFLAGS) -c realAnimals/owl.cpp

hummingbird.o: realAnimals/hummingbird.cpp
	$(CXX) $(CFLAGS) -c realAnimals/hummingbird.cpp

cockatoo.o: realAnimals/cockatoo.cpp
	$(CXX) $(CFLAGS) -c realAnimals/cockatoo.cpp

robin.o: realAnimals/robin.cpp
	$(CXX) $(CFLAGS) -c realAnimals/robin.cpp

bat.o: realAnimals/bat.cpp
	$(CXX) $(CFLAGS) -c realAnimals/bat.cpp

penguin.o: realAnimals/penguin.cpp
	$(CXX) $(CFLAGS) -c realAnimals/penguin.cpp

hippopotamus.o: realAnimals/hippopotamus.cpp
	$(CXX) $(CFLAGS) -c realAnimals/hippopotamus.cpp			

pelican.o: realAnimals/pelican.cpp
	$(CXX) $(CFLAGS) -c realAnimals/pelican.cpp

goose.o: realAnimals/goose.cpp
	$(CXX) $(CFLAGS) -c realAnimals/goose.cpp

crane.o: realAnimals/crane.cpp
	$(CXX) $(CFLAGS) -c realAnimals/crane.cpp

draco_lizard.o: realAnimals/draco_lizard.cpp
	$(CXX) $(CFLAGS) -c realAnimals/draco_lizard.cpp

colugo.o: realAnimals/colugo.cpp
	$(CXX) $(CFLAGS) -c realAnimals/colugo.cpp

sugar_glider.o: realAnimals/sugar_glider.cpp
	$(CXX) $(CFLAGS) -c realAnimals/sugar_glider.cpp
						
renderable.o: renderable.cpp
	$(CXX) $(CFLAGS) -c renderable.cpp			

clean: 
	$(RM) count *.o *~
