//File zebra.cpp

#include "zebra.h"
#include "../animal.h"
#include <iostream>
using namespace std;

int Zebra::zebraNB = 0;

Zebra::Zebra(pair<int,int> _position): Animal("ZBR",++zebraNB,226./,food,'H',_position) {
	eat = food;
}

Zebra::Zebra(float _weight, pair<int,int> _position): Animal("ZBR",++zebraNB,_weight,food,'H',_position) {
	eat = food;
}

Zebra::~Zebra(){}

Zebra::Zebra(const Zebra& z): Animal(z.ID,z.id,z.weight,z.eat,z.type,z.position) {
	
}

Zebra& Zebra::operator= (const Zebra& z) {
	SetWeight(z.GetWeight());
	SetPos(z.GetPos());
	return *this;
}

void Zebra::Act() const {
	cout << ID << "-";
	if (id < 10){
		cout << "0"; 
	}
	cout << id	<< ": *snort*" << endl;
}

void Zebra::Interact() const {
	Description("Zebra");
	Act();
}