//File goose.cpp

#include "Goose.h"
#include "../animal.h"
#include <iostream>
using namespace std;

int Goose::GooseNB = 0;

Goose::Goose(pair<int,int> _position): Animal("GSE",++GooseNB,'+',4,food,'H',_position) {
	eat = food;
	habitat.insert('W');	
	habitat.insert('A');
}

Goose::Goose(float _weight, pair<int,int> _position): Animal("GSE",++GooseNB,'+',_weight,food,'H',_position) {
	eat = food;
	habitat.insert('W');
	habitat.insert('A');
}

Goose::~Goose(){}

Goose::Goose(const Goose& g): Animal(g.ID,g.id,g.legend,g.weight,g.eat,g.type,g.position) {
	habitat = g.habitat;
}

Goose& Goose::operator= (const Goose& g) {
	SetWeight(g.GetWeight());
	SetPos(g.GetPos());
	return *this;
}

void Goose::Act() const {
	cout << ID << "-";
	if (id < 10){
		cout << "0"; 
	}
	cout << id	<< ": *quack*" << endl;
}

void Goose::Interact() const {
	Description("Goose");
	Act();
}