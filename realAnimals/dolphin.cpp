//File dolphin.cpp

#include "dolphin.h"
#include "../animal.h"
#include <iostream>
using namespace std;

int Dolphin::dolphin_nb = 0;

Dolphin::Dolphin(pair<int,int> _position): Animal("DLP", ++dolphin_nb, '!', 226, food, 'K', _position) {
  eat = food;
  habitat.insert('W');
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
}

Dolphin::Dolphin(float _weight, pair<int,int> _position): Animal("DLP", ++dolphin_nb, '!', _weight, food, 'K', _position) {
  eat = food;
  habitat.insert('W');
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
}

Dolphin::~Dolphin(){}

Dolphin::Dolphin(const Dolphin& d): Animal(d.ID,d.id,d.legend,d.weight,d.eat,d.type,d.position) {
  habitat = d.habitat;
}

Dolphin& Dolphin::operator= (const Dolphin& d) {
  SetWeight(d.GetWeight());
  SetPos(d.GetPos());
  return *this;
}

void Dolphin::Act() const {
  cout << ID << "-";
  if (id < 10){
    cout << "0"; 
  }
  cout << id  << ": *click*" << endl;
}

void Dolphin::Interact() const {
  Description("dolphin");
  Act();
}
