//File elephant.cpp

#include "elephant.h"
#include "../animal.h"
#include <iostream>
using namespace std;

int Elephant::elephantNB = 0;

Elephant::Elephant(pair<int,int> _position): Animal("ELP",++elephantNB,'4',5000,food,'H',_position) {
	eat = food;
	habitat.insert('L');
}

Elephant::Elephant(float _weight, pair<int,int> _position): Animal("ELP",++elephantNB,'4',_weight,food,'H',_position) {
	eat = food;
	habitat.insert('L');
}

Elephant::~Elephant(){}

Elephant::Elephant(const Elephant& e): Animal(e.ID,e.id,e.legend,e.weight,e.eat,e.type,e.position) {
	habitat = e.habitat;
}

Elephant& Elephant::operator= (const Elephant& e) {
	SetWeight(e.GetWeight());
	SetPos(e.GetPos());
	return *this;
}

void Elephant::Act() const {
	cout << ID << "-";
	if (id < 10){
		cout << "0"; 
	}
	cout << id	<< ": *trumpet*" << endl;
}

void Elephant::Interact() const {
	Description("Elephant");
	Act();
}