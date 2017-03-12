//File colugo.cpp

#include "colugo.h"
#include "../animal.h"
#include <iostream>
using namespace std;

int Colugo::colugoNB = 0;

Colugo::Colugo(pair<int,int> _position): Animal("CLG",++colugoNB,'<',0.035,food,'H',_position) {
	eat = food;
	habitat.insert('L');	
	habitat.insert('A');
}

Colugo::Colugo(float _weight, pair<int,int> _position): Animal("CLG",++colugoNB,'<',_weight,food,'H',_position) {
	eat = food;
	habitat.insert('L');
	habitat.insert('A');
}

Colugo::~Colugo(){}

Colugo::Colugo(const Colugo& c): Animal(c.ID,c.id,c.legend,c.weight,c.eat,c.type,c.position) {
	habitat = c.habitat;
}

Colugo& Colugo::operator= (const Colugo& c) {
	SetWeight(c.GetWeight());
	SetPos(c.GetPos());
	return *this;
}

void Colugo::Act() const {
	cout << ID << "-";
	if (id < 10){
		cout << "0"; 
	}
	cout << id	<< ": *glide*" << endl;
}

void Colugo::Interact() const {
	Description("colugo");
	Act();
}