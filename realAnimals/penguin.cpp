//File penguin.cpp

#include "penguin.h"
#include "../animal.h"
#include <iostream>
using namespace std;

int Penguin::penguin_nb = 0;

Penguin::Penguin(pair<int,int> _position): Animal("PNG", ++penguin_nb, '(', 22, food, 'K', _position) {
  eat = food;
  habitat.insert('L');  
  habitat.insert('W');
  compatible.insert("ZBR");
  compatible.insert("ELP");
  compatible.insert("PNG");
  compatible.insert("HPP");
  compatible.insert("DRL");
  compatible.insert("CLG");
  compatible.insert("SGL");
  compatible.insert("DGG");
  compatible.insert("TRL");
  compatible.insert("DLP");
  compatible.insert("WHL");
  compatible.insert("PLC");
  compatible.insert("GSE");
  compatible.insert("CRN");
}

Penguin::Penguin(float _weight, pair<int,int> _position): Animal("PNG", ++penguin_nb, '(', _weight, food, 'K', _position) {
  eat = food;
  habitat.insert('L');
  habitat.insert('W');
  compatible.insert("ZBR");
  compatible.insert("ELP");
  compatible.insert("PNG");
  compatible.insert("HPP");
  compatible.insert("DRL");
  compatible.insert("CLG");
  compatible.insert("SGL");
  compatible.insert("DGG");
  compatible.insert("TRL");
  compatible.insert("DLP");
  compatible.insert("WHL");
  compatible.insert("PLC");
  compatible.insert("GSE");
  compatible.insert("CRN");
}

Penguin::~Penguin(){}

Penguin::Penguin(const Penguin& p): Animal(p.id,p.number,p.legend,p.weight,p.eat,p.type,p.position) {
  habitat = p.habitat;
}

Penguin& Penguin::operator= (const Penguin& p) {
  SetWeight(p.GetWeight());
  SetPos(p.GetPos());
  return *this;
}

void Penguin::Act() const {
  cout << id << "-";
  if (number < 10){
    cout << "0"; 
  }
  cout << number  << ": *slide*" << endl;
}

void Penguin::Interact() const {
  Description("penguin");
  Act();
}
