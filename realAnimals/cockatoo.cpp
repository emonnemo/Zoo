//File cockatoo.cpp

#include "cockatoo.h"
#include "../animal.h"
#include <iostream>
using namespace std;

int Cockatoo::cockatooNB = 0;

Cockatoo::Cockatoo(pair<int,int> _position): Animal("CKT",++cockatooNB,'^',0.09,food,'H',_position) {
  eat = food;
  habitat.insert('A');
  compatible.insert("HMB");
  compatible.insert("CKT");
  compatible.insert("RBN");
  compatible.insert("BT");
  compatible.insert("PLC");
  compatible.insert("GSE");
  compatible.insert("CRN");
  compatible.insert("CLG");
}

Cockatoo::Cockatoo(float _weight, pair<int,int> _position): Animal("CKT",++cockatooNB,'^',_weight,food,'H',_position) {
  eat = food;
  habitat.insert('A');
  compatible.insert("HMB");
  compatible.insert("CKT");
  compatible.insert("RBN");
  compatible.insert("BT");
  compatible.insert("PLC");
  compatible.insert("GSE");
  compatible.insert("CRN");
  compatible.insert("CLG");
}

Cockatoo::~Cockatoo(){}

Cockatoo::Cockatoo(const Cockatoo& c): Animal(c.ID,c.id,c.legend,c.weight,c.eat,c.type,c.position) {
  habitat = c.habitat;
}

Cockatoo& Cockatoo::operator= (const Cockatoo& c) {
  SetWeight(c.GetWeight());
  SetPos(c.GetPos());
  return *this;
}

void Cockatoo::Act() const {
  cout << ID << "-";
  if (id < 10){
    cout << "0"; 
  }
  cout << id  << ": *talk*" << endl;
}

void Cockatoo::Interact() const {
  Description("cockatoo");
  Act();
}
