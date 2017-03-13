#include "zoo.h"
#include "menu.h"
#include <iostream>
using namespace std;

int main(){
	char option;
	int width = 16, length = 0;
	Zoo z;
	do{
		cout << "Auto generate zoo? (y/n) ";
		cin >> option;	
	} while(option != 'Y' && option != 'y' && option != 'N' && option != 'n');

	if (option == 'N' || option == 'n'){
		do{
			cout << "Input lebar dan panjang zoo: ";
			cin >> width >> length;
		} while (width <= 0 || length <= 0);
		Zoo temp (0, width, length);
		z = temp;
	}
	do{
		Menu m;	
		switch (m.GetOption()){
			case '1':
				z.Display(0, 0, width-1, length-1);
				break;
			case '2':
				cout << "Daging: " << z.GetTotalMeat() << " kg"<< endl << "Tumbuhan: " << z.GetTotalVegetables() << "kg" << endl;
				break;
			case '3':
				z.Tour();
				break;
			case '4':
				z.ToggleAllSekat();
				break;
		}
		z.MoveAllAnimal();
		option = m.GetOption();
	} while (option != '5');
	return 0;
}