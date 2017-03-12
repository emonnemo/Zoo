//File eagle.cpp

#include "eagle.h"
#include "../animal.h"
#include <iostream>
using namespace std;

int Eagle::eagleNB = 0;

Eagle::Eagle(pair<int,int> _position): Animal("EGL",++eagleNB,'/',4,food,'K',_position) {
	eat = food;
	habitat.insert('A');
}

Eagle::Eagle(float _weight, pair<int,int> _position): Animal("EGL",++eagleNB,'/',_weight,food,'K',_position) {
	eat = food;
	habitat.insert('A');
}

Eagle::~Eagle(){}

Eagle::Eagle(const Eagle& e): Animal(e.ID,e.id,e.legend,e.weight,e.eat,e.type,e.position) {
	habitat = e.habitat;
}

Eagle& Eagle::operator= (const Eagle& e) {
	SetWeight(e.GetWeight());
	SetPos(e.GetPos());
	return *this;
}

void Eagle::Act() const {
	cout << ID << "-";
	if (id < 10){
		cout << "0"; 
	}
	cout << id	<< ": *scream*" << endl;
}

void Eagle::Interact() const {
	Description("eagle");
	Act();
}