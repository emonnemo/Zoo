#include "restaurant.h"
#include <iostream>

using namespace std;

Restaurant::Restaurant(){
	symbol = 'R';
	initsymbol = 'R';
	food = "";
	open = false;
}

Restauramt::Restaurant(string f, bool o){
	symbol = 'R';
	initsymbol = 'R';
	food = f;
	open = 0;
}

Restaurant::Restaurant(Restaurant& r){
	symbol = r.symbol;
	initsymbol = r.initsymbol;
	food = r.food;
}

Restaurant::~Restaurant(){
	
}

void Restaurant::Interact(){
	if (o){
		cout << "This restaurant sells " << f << endl;
	} else{
		cout << "This restaurant is closed"
	}
}