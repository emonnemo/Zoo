//File pelican.cpp

#include "pelican.h"
#include "../animal.h"
#include <iostream>
using namespace std;

int Pelican::pelican_nb = 0;

Pelican::Pelican(pair<int,int> _position): Animal("PLC", ++pelican_nb, '~', 7, food, 'K', _position) {
  eat = food;
  habitat.insert('W');  
  habitat.insert('A');
  compatible.insert("MRE");
  compatible.insert("DGG");
  compatible.insert("DLP");
  compatible.insert("WHL");
  compatible.insert("PNG");
  compatible.insert("HPP");
  compatible.insert("PLC");
  compatible.insert("GSE");
  compatible.insert("CRN");
  compatible.insert("EGL");
  compatible.insert("OW");
  compatible.insert("HMB");
  compatible.insert("CKT");
  compatible.insert("RBN");
  compatible.insert("BT");
  compatible.insert("CLG");
  compatible.insert("SGL");
}

Pelican::Pelican(float _weight, pair<int,int> _position): Animal("PLC", ++pelican_nb, '~', _weight, food, 'K', _position) {
  eat = food;
  habitat.insert('W');
  habitat.insert('A');
  compatible.insert("MRE");
  compatible.insert("DGG");
  compatible.insert("DLP");
  compatible.insert("WHL");
  compatible.insert("PNG");
  compatible.insert("HPP");
  compatible.insert("PLC");
  compatible.insert("GSE");
  compatible.insert("CRN");
  compatible.insert("EGL");
  compatible.insert("OW");
  compatible.insert("HMB");
  compatible.insert("CKT");
  compatible.insert("RBN");
  compatible.insert("BT");
  compatible.insert("CLG");
  compatible.insert("SGL");
}

Pelican::~Pelican(){}

Pelican::Pelican(const Pelican& p): Animal(p.id,p.number,p.legend,p.weight,p.eat,p.type,p.position) {
  habitat = p.habitat;
}

Pelican& Pelican::operator= (const Pelican& p) {
  SetWeight(p.GetWeight());
  SetPos(p.GetPos());
  return *this;
}

void Pelican::Act() const {
  cout << id << "-";
  if (number < 10){
    cout << "0"; 
  }
  cout << number  << ": “hrraa-hrraa”" << endl;
}

void Pelican::Interact() const {
  Description("pelican");
  Act();
}
