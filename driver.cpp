#include "facility.h"
#include "zoo.h"
#include <iostream>
#include "realAnimals/wolf.h"
#include "realAnimals/lion.h"
#include "realAnimals/zebra.h"
#include "realAnimals/elephant.h"
#include "realAnimals/macaque.h"
#include "realAnimals/hog.h"
#include "realAnimals/shark.h"
#include "realAnimals/morayeel.h"
#include "realAnimals/dugong.h"
#include "realAnimals/turtle.h"
#include "realAnimals/dolphin.h"
#include "realAnimals/whale.h"
#include "realAnimals/eagle.h"

int main(){

	//Zoo z;
	//z.Display(0,0,15,5);
	Zoo x;
	x.Display(0,0,15,5);
	//Animal a("TG", 1, 100, 0.1, 'K', make_pair(1,1));
	for(int i = 0; i < 16; i++){
		for(int j = 0; j < 6; j++){
			Eagle *pa;
			pa = new Eagle(make_pair(i,j));
			x.AddAnimal(pa);
		}
	}
	//x.DelAnimal("WF", 12);
	cout << endl;
	x.Display(0,0,15,5);
	cout << "meat :" << x.GetTotalMeat() << endl;
	cout << "vege :" << x.GetTotalVegetables() << endl;
	cout << endl;
	//x.DelAnimal("WF", 11);
	//x.AddAnimal(a);
	//a.Interact();
	x.ToggleSekat(4, 0, 3);
	x.MoveAnimal(make_pair(4,0), 3);
	x.Display(0,0,15,5);
	x.Tour();
	return 0;
}