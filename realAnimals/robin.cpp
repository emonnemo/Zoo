//File robin.cpp

#include "robin.h"
#include "../animal.h"
#include <iostream>
using namespace std;

int Robin::robinNB = 0;

Robin::Robin(pair<int,int> _position): Animal("RBN",++robinNB,'&',0.06,food,'O',_position) {
	eat = food;
	habitat.insert('A');
}

Robin::Robin(float _weight, pair<int,int> _position): Animal("RBN",++robinNB,'&',_weight,food,'O',_position) {
	eat = food;
	habitat.insert('A');
}

Robin::~Robin(){}

Robin::Robin(const Robin& r): Animal(r.ID,r.id,r.legend,r.weight,r.eat,r.type,r.position) {
	habitat = r.habitat;
}

Robin& Robin::operator= (const Robin& r) {
	SetWeight(r.GetWeight());
	SetPos(r.GetPos());
	return *this;
}

void Robin::Act() const {
	cout << ID << "-";
	if (id < 10){
		cout << "0"; 
	}
	cout << id	<< ": *hoot*" << endl;
}

void Robin::Interact() const {
	Description("robin");
	Act();
}