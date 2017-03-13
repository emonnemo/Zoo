//File draco_lizard.cpp

#include "draco_lizard.h"
#include "../animal.h"
#include <iostream>
using namespace std;

int Draco_Lizard::dracoLizardNB = 0;

<<<<<<< HEAD:realAnimals/dLizard.cpp
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
=======
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
>>>>>>> cb17fe74f29bee37f98ee210c4c55ed3edd81339:realAnimals/draco_lizard.cpp
}

Draco_Lizard::~Draco_Lizard(){}

<<<<<<< HEAD:realAnimals/dLizard.cpp
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
  cout << id  << ": *jump*" << endl;
}

void DLizard::Interact() const {
  Description("draco lizard");
  Act();
}
=======
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
	cout << id	<< ": *jump*" << enDraco_L;
}

void Draco_Lizard::Interact() const {
	Description("draco lizard");
	Act();
}
>>>>>>> cb17fe74f29bee37f98ee210c4c55ed3edd81339:realAnimals/draco_lizard.cpp
