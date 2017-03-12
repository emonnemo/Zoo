//File lion.cpp

#include "lion.h"
#include "../animal.h"
#include <iostream>
using namespace std;

int Lion::lionNB = 0;

Lion::Lion(pair<int,int> _position): Animal("LI",++lionNB,158,food,'K',_position) {
	eat = food;
}

Lion::Lion(float _weight, pair<int,int> _position): Animal("LI",++lionNB,_weight,food,'K',_position) {
	eat = food;
}

Lion::~Lion(){}

Lion::Lion(const Lion& l): Animal(l.ID,l.id,l.weight,l.eat,l.type,l.position) {
	
}

Lion& Lion::operator= (const Lion& l) {
	SetWeight(l.GetWeight());
	SetPos(l.GetPos());
	return *this;
}

void Lion::Act() const {
	cout << ID << "-";
	if (id < 10){
		cout << "0"; 
	}
	cout << id	<< ": *roar*" << endl;
}

void Lion::Interact() const {
	Description("lion");
	Act();
}