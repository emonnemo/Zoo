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
	Shark a(make_pair(0,0));
	x.AddAnimal(a);
	cout << (*(x.FindAnimal(make_pair(0,0))))->GetID() << endl;;
	for(int i = 0; i < 16; i++){
		for(int j = 0; j < 6; j++){
			Eagle a(make_pair(i,j));
			x.AddAnimal(a);
		}
	}
	Eagle e(make_pair(4,0));
	x.AddAnimal(a);
	x.DelAnimal(0,5);
	Wolf b(make_pair(0,5));
	x.AddAnimal(b);
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