//File penguin.cpp

#include "penguin.h"
#include "../animal.h"
#include <iostream>
using namespace std;

int Penguin::penguinNB = 0;

Penguin::Penguin(pair<int,int> _position): Animal("PNG",++penguinNB,'(',22,food,'K',_position) {
	eat = food;
	habitat.insert('L');	
	habitat.insert('W');
}

Penguin::Penguin(float _weight, pair<int,int> _position): Animal("PNG",++penguinNB,'(',_weight,food,'K',_position) {
	eat = food;
	habitat.insert('L');
	habitat.insert('W');
}

Penguin::~Penguin(){}

Penguin::Penguin(const Penguin& p): Animal(p.ID,p.id,p.legend,p.weight,p.eat,p.type,p.position) {
	habitat = p.habitat;
}

Penguin& Penguin::operator= (const Penguin& p) {
	SetWeight(p.GetWeight());
	SetPos(p.GetPos());
	return *this;
}

void Penguin::Act() const {
	cout << ID << "-";
	if (id < 10){
		cout << "0"; 
	}
	cout << id	<< ": *slide*" << endl;
}

void Penguin::Interact() const {
	Description("penguin");
	Act();
}