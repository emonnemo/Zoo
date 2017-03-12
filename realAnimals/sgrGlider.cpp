//File sgrGlider.cpp

#include "sgrGlider.h"
#include "../animal.h"
#include <iostream>
using namespace std;

int SgrGlider::sgrGliderNB = 0;

SgrGlider::SgrGlider(pair<int,int> _position): Animal("SGL",++sgrGliderNB,'>',0.12,food,'O',_position) {
	eat = food;
	habitat.insert('L');	
	habitat.insert('A');
}

SgrGlider::SgrGlider(float _weight, pair<int,int> _position): Animal("SGL",++sgrGliderNB,'>',_weight,food,'O',_position) {
	eat = food;
	habitat.insert('L');
	habitat.insert('A');
}

SgrGlider::~SgrGlider(){}

SgrGlider::SgrGlider(const SgrGlider& s): Animal(s.ID,s.id,s.legend,s.weight,s.eat,s.type,s.position) {
	habitat = s.habitat;
}

SgrGlider& SgrGlider::operator= (const SgrGlider& s) {
	SetWeight(s.GetWeight());
	SetPos(s.GetPos());
	return *this;
}

void SgrGlider::Act() const {
	cout << ID << "-";
	if (id < 10){
		cout << "0"; 
	}
	cout << id	<< ": *crab*" << endl;
}

void SgrGlider::Interact() const {
	Description("sugar glider");
	Act();
}