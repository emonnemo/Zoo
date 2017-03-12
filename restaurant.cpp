#include "restaurant.h"
#include <iostream>

using namespace std;

Restaurant::Restaurant(){
	symbol = 'R';
	initsymbol = 'R';
	food = "";
	open = false;
}

Restaurant::Restaurant(string f, bool o){
	symbol = 'R';
	initsymbol = 'R';
	food = f;
	open = 0;
}

Restaurant::~Restaurant(){
	
}

void Restaurant::Interact() const{
	if (open){
		cout << "This restaurant sells " << food << endl;
	} else{
		cout << "This restaurant is closed" << endl;
	}
}


void Restaurant::ToggleSekat(int direction){

}
		
bool Restaurant::GetSekat(int direction) const{
	return false;
}