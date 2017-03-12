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
	for(int i = 0; i < 3; i++){
		Wolf a(make_pair(i+1,0));
		Lion b(make_pair(i+1,1));
		Zebra c(make_pair(i+1,2));
		x.AddAnimal(c);
		c.Interact();
		x.AddAnimal(b);
		b.Interact();
		x.AddAnimal(a);
		a.Interact();
	}
	x.Display(0,0,15,5);
	cout << "meat :" << x.GetTotalMeat() << endl;
	x.DelAnimal("WF", 11);
	//x.AddAnimal(a);
	//a.Interact();
	return 0;
}