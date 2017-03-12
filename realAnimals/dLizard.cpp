//File dLizard.cpp

#include "dLizard.h"
#include "../animal.h"
#include <iostream>
using namespace std;

int DLizard::dLizardNB = 0;

DLizard::DLizard(pair<int,int> _position): Animal("DRL",++dLizardNB,'=',0.2,food,'K',_position) {
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

DLizard::DLizard(float _weight, pair<int,int> _position): Animal("DRL",++dLizardNB,'=',_weight,food,'K',_position) {
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

DLizard::~DLizard(){}

DLizard::DLizard(const DLizard& d): Animal(d.ID,d.id,d.legend,d.weight,d.eat,d.type,d.position) {
	habitat = d.habitat;
}

DLizard& DLizard::operator= (const DLizard& d) {
	SetWeight(d.GetWeight());
	SetPos(d.GetPos());
	return *this;
}

void DLizard::Act() const {
	cout << ID << "-";
	if (id < 10){
		cout << "0"; 
	}
	cout << id	<< ": *jump*" << endl;
}

void DLizard::Interact() const {
	Description("draco lizard");
	Act();
}