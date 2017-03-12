//File dugong.cpp

#include "dugong.h"
#include "../animal.h"
#include <iostream>
using namespace std;

int Dugong::DugongNB = 0;

Dugong::Dugong(pair<int,int> _position): Animal("DGG",++DugongNB,'9',294,food,'H',_position) {
	eat = food;
	habitat.insert('W');
}

Dugong::Dugong(float _weight, pair<int,int> _position): Animal("DGG",++DugongNB,'9',_weight,food,'H',_position) {
	eat = food;
	habitat.insert('W');
}

Dugong::~Dugong(){}

Dugong::Dugong(const Dugong& w): Animal(w.ID,w.id,w.legend,w.weight,w.eat,w.type,w.position) {
	habitat = w.habitat;
}

Dugong& Dugong::operator= (const Dugong& w) {
	SetWeight(w.GetWeight());
	SetPos(w.GetPos());
	return *this;
}

void Dugong::Act() const {
	cout << ID << "-";
	if (id < 10){
		cout << "0"; 
	}
	cout << id	<< ": *splash*" << endl;
}

void Dugong::Interact() const {
	Description("Dugong");
	Act();
}