CXX = g++
CFLAGS = -std=c++11
LFLAGS = -g -Wall -std=c++11

FACILPATH = src/cells/facilities
MAINPATH = src
DRIVERPATH = src/driver
ANIMALPATH = src/animals
ZOOPATH = src/zoo
CELLPATH = src/cells/cell
HABITATPATH = src/cells/habitat
RENDERPATH = src/cells/renderable

main: main.o driver.o facility.o cell.o road.o restaurant.o park.o zoo.o animal.o habitat.o wolf.o lion.o zebra.o elephant.o hog.o macaque.o shark.o moray_eel.o dugong.o turtle.o dolphin.o whale.o eagle.o owl.o hummingbird.o cockatoo.o robin.o bat.o penguin.o hippopotamus.o pelican.o goose.o crane.o draco_lizard.o colugo.o sugar_glider.o
	$(CXX) $(LFLAGS) -o main main.o driver.o facility.o cell.o road.o restaurant.o park.o zoo.o animal.o habitat.o wolf.o lion.o zebra.o elephant.o hog.o macaque.o shark.o moray_eel.o dugong.o turtle.o dolphin.o whale.o eagle.o owl.o hummingbird.o cockatoo.o robin.o bat.o penguin.o hippopotamus.o pelican.o goose.o crane.o draco_lizard.o colugo.o sugar_glider.o

main.o: src/main.cpp src/driver/driver.h
	$(CXX) $(CFLAGS) -c src/main.cpp

driver.o: src/driver/driver.cpp src/driver/driver.h src/zoo/zoo.h
	$(CXX) $(CFLAGS) -c src/driver/driver.cpp
 
facility.o: $(FACILPATH)/facility/facility.cpp $(FACILPATH)/facility//facility.h src/cells/cell/cell.h
	$(CXX) $(CFLAGS) -c $(FACILPATH)/facility/facility.cpp
 
cell.o: $(CELLPATH)/cell.cpp $(CELLPATH)/cell.h $(RENDERPATH)/renderable.h
	$(CXX) $(CFLAGS) -c $(CELLPATH)/cell.cpp
 
road.o: $(FACILPATH)/road/road.cpp $(FACILPATH)/road/road.h $(FACILPATH)/facility/facility.h
	$(CXX) $(CFLAGS) -c $(FACILPATH)/road/road.cpp
 
restaurant.o: $(FACILPATH)/restaurant/restaurant.cpp $(FACILPATH)/restaurant/restaurant.h $(FACILPATH)/facility/facility.h
	$(CXX) $(CFLAGS) -c $(FACILPATH)/restaurant/restaurant.cpp
 
park.o: $(FACILPATH)/park/park.cpp $(FACILPATH)/park/park.h $(FACILPATH)/facility/facility.h
	$(CXX) $(CFLAGS) -c $(FACILPATH)/park/park.cpp
 
zoo.o: $(ZOOPATH)/zoo.cpp $(ZOOPATH)/zoo.h
	$(CXX) $(CFLAGS) -c $(ZOOPATH)/zoo.cpp
 
animal.o: $(ANIMALPATH)/animal/animal.cpp $(ANIMALPATH)/animal/animal.h
	$(CXX) $(CFLAGS) -c $(ANIMALPATH)/animal/animal.cpp
 
habitat.o: $(HABITATPATH)/habitat.cpp $(HABITATPATH)/habitat.h
	$(CXX) $(CFLAGS) -c $(HABITATPATH)/habitat.cpp
 
wolf.o: $(ANIMALPATH)/wolf/wolf.cpp
	$(CXX) $(CFLAGS) -c $(ANIMALPATH)/wolf/wolf.cpp
 
lion.o: $(ANIMALPATH)/lion/lion.cpp
	$(CXX) $(CFLAGS) -c $(ANIMALPATH)/lion/lion.cpp
 
zebra.o: $(ANIMALPATH)/zebra/zebra.cpp
	$(CXX) $(CFLAGS) -c $(ANIMALPATH)/zebra/zebra.cpp
 
elephant.o: $(ANIMALPATH)/elephant/elephant.cpp
	$(CXX) $(CFLAGS) -c $(ANIMALPATH)/elephant/elephant.cpp
 
macaque.o: $(ANIMALPATH)/macaque/macaque.cpp
	$(CXX) $(CFLAGS) -c $(ANIMALPATH)/macaque/macaque.cpp
 
hog.o: $(ANIMALPATH)/hog/hog.cpp
	$(CXX) $(CFLAGS) -c $(ANIMALPATH)/hog/hog.cpp
 
shark.o: $(ANIMALPATH)/shark/shark.cpp
	$(CXX) $(CFLAGS) -c $(ANIMALPATH)/shark/shark.cpp
 
moray_eel.o: $(ANIMALPATH)/moray_eel/moray_eel.cpp
	$(CXX) $(CFLAGS) -c $(ANIMALPATH)/moray_eel/moray_eel.cpp
 
dugong.o: $(ANIMALPATH)/dugong/dugong.cpp
	$(CXX) $(CFLAGS) -c $(ANIMALPATH)/dugong/dugong.cpp
 
turtle.o: $(ANIMALPATH)/turtle/turtle.cpp
	$(CXX) $(CFLAGS) -c $(ANIMALPATH)/turtle/turtle.cpp
 
dolphin.o: $(ANIMALPATH)/dolphin/dolphin.cpp
	$(CXX) $(CFLAGS) -c $(ANIMALPATH)/dolphin/dolphin.cpp
 
whale.o: $(ANIMALPATH)/whale/whale.cpp
	$(CXX) $(CFLAGS) -c $(ANIMALPATH)/whale/whale.cpp
 
eagle.o: $(ANIMALPATH)/eagle/eagle.cpp
	$(CXX) $(CFLAGS) -c $(ANIMALPATH)/eagle/eagle.cpp
 
owl.o: $(ANIMALPATH)/owl/owl.cpp
	$(CXX) $(CFLAGS) -c $(ANIMALPATH)/owl/owl.cpp
 
hummingbird.o: $(ANIMALPATH)/hummingbird/hummingbird.cpp
	$(CXX) $(CFLAGS) -c $(ANIMALPATH)/hummingbird/hummingbird.cpp
 
cockatoo.o: $(ANIMALPATH)/cockatoo/cockatoo.cpp
	$(CXX) $(CFLAGS) -c $(ANIMALPATH)/cockatoo/cockatoo.cpp
 
robin.o: $(ANIMALPATH)/robin/robin.cpp
	$(CXX) $(CFLAGS) -c $(ANIMALPATH)/robin/robin.cpp
 
bat.o: $(ANIMALPATH)/bat/bat.cpp
	$(CXX) $(CFLAGS) -c $(ANIMALPATH)/bat/bat.cpp
 
penguin.o: $(ANIMALPATH)/penguin/penguin.cpp
	$(CXX) $(CFLAGS) -c $(ANIMALPATH)/penguin/penguin.cpp
 
hippopotamus.o: $(ANIMALPATH)/hippopotamus/hippopotamus.cpp
	$(CXX) $(CFLAGS) -c $(ANIMALPATH)/hippopotamus/hippopotamus.cpp
 
pelican.o: $(ANIMALPATH)/pelican/pelican.cpp
	$(CXX) $(CFLAGS) -c $(ANIMALPATH)/pelican/pelican.cpp
 
goose.o: $(ANIMALPATH)/goose/goose.cpp
	$(CXX) $(CFLAGS) -c $(ANIMALPATH)/goose/goose.cpp
 
crane.o: $(ANIMALPATH)/crane/crane.cpp
	$(CXX) $(CFLAGS) -c $(ANIMALPATH)/crane/crane.cpp
 
draco_lizard.o: $(ANIMALPATH)/draco_lizard/draco_lizard.cpp
	$(CXX) $(CFLAGS) -c $(ANIMALPATH)/draco_lizard/draco_lizard.cpp
 
colugo.o: $(ANIMALPATH)/colugo/colugo.cpp
	$(CXX) $(CFLAGS) -c $(ANIMALPATH)/colugo/colugo.cpp
 
sugar_glider.o: $(ANIMALPATH)/sugar_glider/sugar_glider.cpp
	$(CXX) $(CFLAGS) -c $(ANIMALPATH)/sugar_glider/sugar_glider.cpp

clean: 
	$(RM) count *o *~
