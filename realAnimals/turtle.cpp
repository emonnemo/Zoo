//File turtle.cpp

#include "turtle.h"
#include "../animal.h"
#include <iostream>
using namespace std;

int Turtle::TurtleNB = 0;

Turtle::Turtle(pair<int,int> _position): Animal("TRL",++TurtleNB,'0',453,food,'H',_position) {
	eat = food;
	habitat.insert('W');
}

Turtle::Turtle(float _weight, pair<int,int> _position): Animal("TRL",++TurtleNB,'0',_weight,food,'H',_position) {
	eat = food;
	habitat.insert('W');
}

Turtle::~Turtle(){}

Turtle::Turtle(const Turtle& w): Animal(w.ID,w.id,w.legend,w.weight,w.eat,w.type,w.position) {
	habitat = w.habitat;
}

Turtle& Turtle::operator= (const Turtle& w) {
	SetWeight(w.GetWeight());
	SetPos(w.GetPos());
	return *this;
}

void Turtle::Act() const {
	cout << ID << "-";
	if (id < 10){
		cout << "0"; 
	}
	cout << id	<< ": *swim*" << endl;
}

void Turtle::Interact() const {
	Description("turtle");
	Act();
}