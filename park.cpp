#include "park.h"
#include <iostream>

using namespace std;

Park::Park(){
	symbol = 'P';
	initsymbol = 'P';
	plant = "";
}

Park::Park(string p){
	symbol = 'P';
	initsymbol = 'P';
	plant = p;
}

Park::Park(Park& p){
	symbol = p.symbol;
	initsymbol = p.initsymbol;
	plant = p.plant;
}

Park::~Park(){

}

void Interact(){
	cout << "This park has " << plant << " planted on it" << endl;
}