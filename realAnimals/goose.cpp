//File goose.cpp

#include "goose.h"
#include "../animal.h"
#include <iostream>
using namespace std;

int Goose::goose_nb = 0;

Goose::Goose(pair<int,int> _position):
       Animal("GSE", ++goose_nb, '+', 4, food, 'H', _position) {
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
  compatible.insert("CLG");
  compatible.insert("SGL");
}

Goose::Goose(float _weight, pair<int,int> _position):
       Animal("GSE", ++goose_nb, '+', _weight, food, 'H', _position) {
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
  compatible.insert("CLG");
  compatible.insert("SGL");
}

Goose::~Goose() {}

Goose::Goose(const Goose& g):
       Animal(g.id, g.number, g.legend, g.weight, g.eat, g.type, g.position) {
  habitat = g.habitat;
}

Goose& Goose::operator=(const Goose& g) {
  SetWeight(g.GetWeight());
  SetPos(g.GetPos());
  return *this;
}

void Goose::Act() const {
  cout << id << "-";
  if (number < 10) {
    cout << "0";
  }
  cout << number  << ": *quack*" << endl;
}

void Goose::Interact() const {
  Description("goose");
  Act();
}
