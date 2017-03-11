#include "restaurant.h"
#include <iostream>

using namespace std;

Restaurant::Restaurant(){
	symbol = 'R';
	initsymbol = 'R';
	food = "";
}

Restauramt::Restaurant(string f){
	symbol = 'R';
	initsymbol = 'R';
	food = f;
}

Restaurant::Restaurant(Restaurant& r){
	symbol = r.symbol;
	initsymbol = r.initsymbol;
	food = r.food;
}

Restaurant::~Restaurant(){
	
}

void Restaurant::Interact(){
	cout << "This restaurant sells " << f << endl;
}