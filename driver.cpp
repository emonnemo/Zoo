#include "facility.h"
#include "zoo.h"
#include <iostream>

int main(){
	//z.Display(0,0,15,5);
	Zoo x;
	x.Display(0,0,15,5);
	Animal a("TG01", 100, 'K');
	x.AddAnimal(a);
	a.Print();
	return 0;
}
