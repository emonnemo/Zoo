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

Park::~Park(){

}

void Park::Interact() const{
	cout << "This park has " << plant << " planted on it" << endl;
}

void Park::ToggleSekat(int direction){

}
		
bool Park::GetSekat(int direction) const{
	return false;
}