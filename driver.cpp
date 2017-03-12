#include "facility.h"
#include "zoo.h"
#include <iostream>

int main(){

	Zoo z;
	//z.Display(0,0,15,5);
	Zoo x;
	x.Display(0,0,15,5);
	Animal a("TG", 1, 100.1, 0.1, 'K', make_pair(1,1));
	x.AddAnimal(a);
	a.Interact();
	return 0;
}
