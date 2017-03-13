//File sugar_glider.cpp

#include "sugar_glider.h"
#include "../animal.h"
#include <iostream>
using namespace std;

int Sugar_Glider::sugarGliderNB = 0;

Sugar_Glider::Sugar_Glider(pair<int,int> _position): Animal("SGL",++sugarGliderNB,'>',0.12,food,'O',_position) {
	eat = food;
	habitat.insert('L');	
	habitat.insert('A');
	compatible.insert("ZBR");
	compatible.insert("MCQ");
	compatible.insert("HG");
	compatible.insert("PNG");
	compatible.insert("DRL");
	compatible.insert("CLG");
	compatible.insert("SGL");
	compatible.insert("HMB");
	compatible.insert("GSE");
	compatible.insert("CRN");
}

Sugar_Glider::Sugar_Glider(float _weight, pair<int,int> _position): Animal("SGL",++sugarGliderNB,'>',_weight,food,'O',_position) {
	eat = food;
	habitat.insert('L');
	habitat.insert('A');
	compatible.insert("ZBR");
	compatible.insert("MCQ");
	compatible.insert("HG");
	compatible.insert("PNG");
	compatible.insert("DRL");
	compatible.insert("CLG");
	compatible.insert("SGL");
	compatible.insert("HMB");
	compatible.insert("GSE");
	compatible.insert("CRN");
}

Sugar_Glider::~Sugar_Glider(){}

Sugar_Glider::Sugar_Glider(const Sugar_Glider& s): Animal(s.ID,s.id,s.legend,s.weight,s.eat,s.type,s.position) {
	habitat = s.habitat;
}

Sugar_Glider& Sugar_Glider::operator= (const Sugar_Glider& s) {
	SetWeight(s.GetWeight());
	SetPos(s.GetPos());
	return *this;
}

void Sugar_Glider::Act() const {
	cout << ID << "-";
	if (id < 10){
		cout << "0"; 
	}
	cout << id	<< ": *crab*" << endl;
}

void Sugar_Glider::Interact() const {
	Description("sugar glider");
	Act();
}