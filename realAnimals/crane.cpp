//File crane.cpp

#include "crane.h"
#include "../animal.h"
#include <iostream>
using namespace std;

int Crane::crane_nb = 0;

Crane::Crane(pair<int,int> _position):
       Animal("CRN", ++crane_nb, '-', 3, food, 'O', _position) {
  eat = food;
  habitat.insert('W');  
  habitat.insert('A');
  compatible.insert("MRE");
  compatible.insert("DGG");
  compatible.insert("TRL");
  compatible.insert("DLP");
  compatible.insert("WHL");
  compatible.insert("PNG");
  compatible.insert("HPP");
  compatible.insert("PLC");
  compatible.insert("GSE");
  compatible.insert("CRN");
  compatible.insert("HMB");
  compatible.insert("CKT");
  compatible.insert("RBN");
  compatible.insert("BT");
  compatible.insert("DRL");
  compatible.insert("CLG");
  compatible.insert("SGL");
}

Crane::Crane(float _weight, pair<int,int> _position):
       Animal("CRN", ++crane_nb, '-', _weight, food, 'O', _position) {
  eat = food;
  habitat.insert('W');
  habitat.insert('A');
  compatible.insert("MRE");
  compatible.insert("DGG");
  compatible.insert("TRL");
  compatible.insert("DLP");
  compatible.insert("WHL");
  compatible.insert("PNG");
  compatible.insert("HPP");
  compatible.insert("PLC");
  compatible.insert("GSE");
  compatible.insert("CRN");
  compatible.insert("HMB");
  compatible.insert("CKT");
  compatible.insert("RBN");
  compatible.insert("BT");
  compatible.insert("DRL");
  compatible.insert("CLG");
  compatible.insert("SGL");
}

Crane::~Crane() {}

Crane::Crane(const Crane& c):
       Animal(c.id, c.number, c.legend, c.weight, c.eat, c.type, c.position) {
  habitat = c.habitat;
}

Crane& Crane::operator=(const Crane& c) {
  SetWeight(c.GetWeight());
  SetPos(c.GetPos());
  return *this;
}

void Crane::Act() const {
  cout << id << "-";
  if (number < 10) {
    cout << "0";
  }
  cout << number  << ": *soar*" << endl;
}

void Crane::Interact() const {
  Description("crane");
  Act();
}
