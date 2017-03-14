//File dolphin.cpp

#include "dolphin.h"
#include "../animal.h"
#include <iostream>
using namespace std;

int Dolphin::DolphinNB = 0;

Dolphin::Dolphin(pair<int,int> _position): Animal("DLP",++DolphinNB,'!',226,food,'K',_position) {
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

Dolphin::Dolphin(float _weight, pair<int,int> _position): Animal("DLP",++DolphinNB,'!',_weight,food,'K',_position) {
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

Dolphin::Dolphin(const Dolphin& w): Animal(w.id,w.number,w.legend,w.weight,w.eat,w.type,w.position) {
  habitat = w.habitat;
}

Dolphin& Dolphin::operator= (const Dolphin& w) {
  SetWeight(w.GetWeight());
  SetPos(w.GetPos());
  return *this;
}

void Dolphin::Act() const {
  cout << id << "-";
  if (number < 10){
    cout << "0"; 
  }
  cout << number  << ": *click*" << endl;
}

void Dolphin::Interact() const {
  Description("dolphin");
  Act();
}
