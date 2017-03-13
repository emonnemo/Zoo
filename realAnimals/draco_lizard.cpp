//File draco_lizard.cpp

#include "draco_lizard.h"
#include "../animal.h"
#include <iostream>
using namespace std;

int Draco_Lizard::dracoLizardNB = 0;

Draco_Lizard::Draco_Lizard(pair<int,int> _position): Animal("DRL",++dracoLizardNB,'=',0.2,food,'K',_position) {
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
	compatible.insert("OW");
	compatible.insert("RBN");
	compatible.insert("GSE");
	compatible.insert("CRN");
}

Draco_Lizard::Draco_Lizard(float _weight, pair<int,int> _position): Animal("DRL",++dracoLizardNB,'=',_weight,food,'K',_position) {
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
	compatible.insert("OW");
	compatible.insert("RBN");
	compatible.insert("GSE");
	compatible.insert("CRN");
}

Draco_Lizard::~Draco_Lizard(){}

Draco_Lizard::Draco_Lizard(const Draco_Lizard& d): Animal(d.ID,d.id,d.legend,d.weight,d.eat,d.type,d.position) {
	habitat = d.habitat;
}

Draco_Lizard& Draco_Lizard::operator= (const Draco_Lizard& d) {
	SetWeight(d.GetWeight());
	SetPos(d.GetPos());
	return *this;
}

void Draco_Lizard::Act() const {
	cout << ID << "-";
	if (id < 10){
		cout << "0"; 
	}
	cout << id	<< ": *jump*" << endl;
}

void Draco_Lizard::Interact() const {
	Description("draco lizard");
	Act();
}
