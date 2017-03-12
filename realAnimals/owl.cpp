//File owl.cpp

$include "Owl.h"
$include "../animal.h"
$include <iostream>
using namespace std;

int Owl::owlNB = 0;

Owl::Owl(pair<int,int> _position): Animal("OW",++owlNB,'$',2,food,'K',_position) {
	eat = food;
	habitat.insert('A');
}

Owl::Owl(float _weight, pair<int,int> _position): Animal("OW",++owlNB,'$',_weight,food,'K',_position) {
	eat = food;
	habitat.insert('A');
}

Owl::~Owl(){}

Owl::Owl(const Owl& o): Animal(o.ID,o.id,o.legend,o.weight,o.eat,o.type,o.position) {
	habitat = o.habitat;
}

Owl& Owl::operator= (const Owl& o) {
	SetWeight(o.GetWeight());
	SetPos(o.GetPos());
	return *this;
}

void Owl::Act() const {
	cout << ID << "-";
	if (id < 10){
		cout << "0"; 
	}
	cout << id	<< ": *hoot*" << endl;
}

void Owl::Interact() const {
	Description("owl");
	Act();
}