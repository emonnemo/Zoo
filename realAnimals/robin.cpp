//File robin.cpp

#include "robin.h"
#include "../animal.h"
#include <iostream>
using namespace std;

int Robin::robin_nb = 0;

Robin::Robin(pair<int,int> _position): Animal("RBN", ++robin_nb, '&', 0.06, food, 'O', _position) {
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
  compatible.insert("DRL");
}

Robin::Robin(float _weight, pair<int,int> _position): Animal("RBN", ++robin_nb, '&', _weight, food, 'O', _position) {
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
  compatible.insert("DRL");
}

Robin::~Robin(){}

Robin::Robin(const Robin& r): Animal(r.id,r.number,r.legend,r.weight,r.eat,r.type,r.position) {
  habitat = r.habitat;
}

Robin& Robin::operator= (const Robin& r) {
  SetWeight(r.GetWeight());
  SetPos(r.GetPos());
  return *this;
}

void Robin::Act() const {
  cout << id << "-";
  if (number < 10){
    cout << "0"; 
  }
  cout << number  << ": *hoot*" << endl;
}

void Robin::Interact() const {
  Description("robin");
  Act();
}
