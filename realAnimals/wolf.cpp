//File wolf.cpp

#include "wolf.h"
#include "../animal.h"
#include <iostream>
using namespace std;

int Wolf::wolfNB = 0;

Wolf::Wolf(pair<int,int> _position): Animal("WF",++wolfNB,45,food,'K',_position) {
	eat = food;
	habitat.insert('L');
}

Wolf::Wolf(float _weight, pair<int,int> _position): Animal("WF",++wolfNB,_weight,food,'K',_position) {
	eat = food;
	habitat.insert('L');
}

Wolf::~Wolf(){}

Wolf::Wolf(const Wolf& w): Animal(w.ID,w.id,w.weight,w.eat,w.type,w.position) {
	
}

Wolf& Wolf::operator= (const Wolf& w) {
	SetWeight(w.GetWeight());
	SetPos(w.GetPos());
	return *this;
}

char Wolf::GetLegend() const{
	return legend;
}

set<char> Wolf::GetHabitat() const{
	return habitat;
}

void Wolf::Act() const {
	cout << ID << "-";
	if (id < 10){
		cout << "0"; 
	}
	cout << id	<< ": *howl*" << endl;
}

void Wolf::Interact() const {
	Description("wolf");
	Act();
}