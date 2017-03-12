#include "facility.h"
#include "zoo.h"
#include <iostream>
#include "realAnimals/wolf.h"
#include "realAnimals/lion.h"
#include "realAnimals/zebra.h"

int main(){

	//Zoo z;
	//z.Display(0,0,15,5);
	Zoo x;
	x.Display(0,0,15,5);
	//Animal a("TG", 1, 100, 0.1, 'K', make_pair(1,1));
	for(int i = 0; i < 16; i++){
		for(int j = 0; j < 6; j++){
			Wolf a(100,make_pair(i,j));
			x.AddAnimal(a);
			//a.Interact();
		}
	}
	x.DelAnimal(0,5);
	x.DelAnimal("WF", 12);
	cout << endl;
	x.Display(0,0,15,5);
	cout << "meat :" << x.GetTotalMeat() << endl;
	x.DelAnimal("WF", 11);
	//x.AddAnimal(a);
	//a.Interact();
	return 0;
}