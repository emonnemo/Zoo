//File morayeel.cpp

#include "morayeel.h"
#include "../animal.h"
#include <iostream>
using namespace std;

int MorayEel::MorayEelNB = 0;

MorayEel::MorayEel(pair<int,int> _position): Animal("MRE",++MorayEelNB,'8',13,food,'K',_position) {
	eat = food;
	habitat.insert('W');
}

MorayEel::MorayEel(float _weight, pair<int,int> _position): Animal("MRE",++MorayEelNB,'8',_weight,food,'K',_position) {
	eat = food;
	habitat.insert('W');
}

MorayEel::~MorayEel(){}

MorayEel::MorayEel(const MorayEel& w): Animal(w.ID,w.id,w.legend,w.weight,w.eat,w.type,w.position) {
	habitat = w.habitat;
}

MorayEel& MorayEel::operator= (const MorayEel& w) {
	SetWeight(w.GetWeight());
	SetPos(w.GetPos());
	return *this;
}

void MorayEel::Act() const {
	cout << ID << "-";
	if (id < 10){
		cout << "0"; 
	}
	cout << id	<< ": *hide into rocks*" << endl;
}

void MorayEel::Interact() const {
	Description("morayeel");
	Act();
}