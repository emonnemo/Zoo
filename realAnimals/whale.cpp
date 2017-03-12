//File whale.cpp

#include "whale.h"
#include "../animal.h"
#include <iostream>
using namespace std;

int Whale::WhaleNB = 0;

Whale::Whale(pair<int,int> _position): Animal("WHL",++WhaleNB,'@',1360,food,'O',_position) {
	eat = food;
	habitat.insert('W');
}

Whale::Whale(float _weight, pair<int,int> _position): Animal("WHL",++WhaleNB,'@',_weight,food,'O',_position) {
	eat = food;
	habitat.insert('W');
}

Whale::~Whale(){}

Whale::Whale(const Whale& w): Animal(w.ID,w.id,w.legend,w.weight,w.eat,w.type,w.position) {
	habitat = w.habitat;
}

Whale& Whale::operator= (const Whale& w) {
	SetWeight(w.GetWeight());
	SetPos(w.GetPos());
	return *this;
}

void Whale::Act() const {
	cout << ID << "-";
	if (id < 10){
		cout << "0"; 
	}
	cout << id	<< ": *sing*" << endl;
}

void Whale::Interact() const {
	Description("whale");
	Act();
}