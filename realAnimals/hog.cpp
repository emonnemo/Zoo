//File hog.cpp

#include "hog.h"
#include "../animal.h"
#include <iostream>
using namespace std;

int Hog::HogNB = 0;

Hog::Hog(pair<int,int> _position): Animal("HG",++HogNB,'6',68,food,'O',_position) {
	eat = food;
	habitat.insert('L');
	compatible.insert("ZBR");
	compatible.insert("ELP");
	compatible.insert("MCQ");
	compatible.insert("HG");
	compatible.insert("HPP");
}

Hog::Hog(float _weight, pair<int,int> _position): Animal("HG",++HogNB,'6',_weight,food,'O',_position) {
	eat = food;
	habitat.insert('L');
	compatible.insert("ZBR");
	compatible.insert("ELP");
	compatible.insert("MCQ");
	compatible.insert("HG");
	compatible.insert("HPP");
}

Hog::~Hog(){}

Hog::Hog(const Hog& w): Animal(w.ID,w.id,w.legend,w.weight,w.eat,w.type,w.position) {
	habitat = w.habitat;
}

Hog& Hog::operator= (const Hog& w) {
	SetWeight(w.GetWeight());
	SetPos(w.GetPos());
	return *this;
}

void Hog::Act() const {
	cout << ID << "-";
	if (id < 10){
		cout << "0"; 
	}
	cout << id	<< ": *oink*" << endl;
}

void Hog::Interact() const {
	Description("hog");
	Act();
}