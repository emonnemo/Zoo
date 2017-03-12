#include "facility.h"
#include "zoo.h"
#include <iostream>
#include "realAnimals/wolf.h"

int main(){

	//Zoo z;
	//z.Display(0,0,15,5);
	Zoo x;
	x.Display(0,0,15,5);
	//Animal a("TG", 1, 100, 0.1, 'K', make_pair(1,1));
	for(int i = 0; i < 10; i++){
		Wolf a(make_pair(i+1,0));
		x.AddAnimal(a);
		a.Interact();
	}
	cout << "meat :" << x.GetTotalMeat() << endl;
	//x.AddAnimal(a);
	//a.Interact();
	return 0;
}