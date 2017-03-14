//File draco_lizard.cpp

#include "draco_lizard.h"
#include "../animal.h"
#include <iostream>
using namespace std;

int DracoLizard::draco_lizard_nb = 0;

DracoLizard::DracoLizard(pair<int,int> _position):
             Animal("DRL", ++draco_lizard_nb, '=', 0.2, food, 'K', _position) {
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

DracoLizard::DracoLizard(float _weight, pair<int,int> _position):
             Animal("DRL",
                   ++draco_lizard_nb,
                   '=',
                   _weight,
                   food,
                   'K',
                   _position) {
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

DracoLizard::~DracoLizard() {}

DracoLizard::DracoLizard(const DracoLizard& d):
             Animal(d.id,
                   d.number,
                   d.legend,
                   d.weight,
                   d.eat,
                   d.type,
                   d.position) {
  habitat = d.habitat;
}

DracoLizard& DracoLizard::operator=(const DracoLizard& d) {
  SetWeight(d.GetWeight());
  SetPos(d.GetPos());
  return *this;
}

void DracoLizard::Act() const {
  cout << id << "-";
  if (number < 10) {
    cout << "0";
  }
  cout << number  << ": *jump*" << endl;
}

void DracoLizard::Interact() const {
  Description("draco lizard");
  Act();
}
