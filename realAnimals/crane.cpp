//File crane.cpp

#include "crane.h"
#include "../animal.h"
#include <iostream>
using namespace std;

int Crane::CraneNB = 0;

Crane::Crane(pair<int,int> _position): Animal("CRN",++CraneNB,'-',3,food,'O',_position) {
	eat = food;
	habitat.insert('W');	
	habitat.insert('A');
}

Crane::Crane(float _weight, pair<int,int> _position): Animal("CRN",++CraneNB,'-',_weight,food,'O',_position) {
	eat = food;
	habitat.insert('W');
	habitat.insert('A');
}

Crane::~Crane(){}

Crane::Crane(const Crane& c): Animal(c.ID,c.id,c.legend,c.weight,c.eat,c.type,c.position) {
	habitat = c.habitat;
}

Crane& Crane::operator= (const Crane& c) {
	SetWeight(c.GetWeight());
	SetPos(c.GetPos());
	return *this;
}

void Crane::Act() const {
	cout << ID << "-";
	if (id < 10){
		cout << "0"; 
	}
	cout << id	<< ": *soar*" << endl;
}

void Crane::Interact() const {
	Description("crane");
	Act();
}