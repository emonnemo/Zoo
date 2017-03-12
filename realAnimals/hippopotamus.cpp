//File hippopotamus.cpp

#include "hippopotamus.h"
#include "../animal.h"
#include <iostream>
using namespace std;

int Hippopotamus::hippopotamusNB = 0;

Hippopotamus::Hippopotamus(pair<int,int> _position): Animal("HPP",++hippopotamusNB,')',1496,food,'H',_position) {
	eat = food;
	habitat.insert('L');	
	habitat.insert('W');
}

Hippopotamus::Hippopotamus(float _weight, pair<int,int> _position): Animal("HPP",++hippopotamusNB,')',_weight,food,'H',_position) {
	eat = food;
	habitat.insert('L');
	habitat.insert('W');
}

Hippopotamus::~Hippopotamus(){}

Hippopotamus::Hippopotamus(const Hippopotamus& h): Animal(h.ID,h.id,h.legend,h.weight,h.eat,h.type,h.position) {
	habitat = h.habitat;
}

Hippopotamus& Hippopotamus::operator= (const Hippopotamus& h) {
	SetWeight(h.GetWeight());
	SetPos(h.GetPos());
	return *this;
}

void Hippopotamus::Act() const {
	cout << ID << "-";
	if (id < 10){
		cout << "0"; 
	}
	cout << id	<< ": *grunt*" << endl;
}

void Hippopotamus::Interact() const {
	Description("hippopotamus");
	Act();
}