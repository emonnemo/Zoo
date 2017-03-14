//File owl.cpp

#include "owl.h"
#include "../animal.h"
#include <iostream>
using namespace std;

int Owl::owl_nb = 0;

Owl::Owl(pair<int,int> _position): Animal("OW",++owl_nb,'$',2,food,'K',_position) {
  eat = food;
  habitat.insert('A');
  compatible.insert("EGL");
  compatible.insert("OW");
  compatible.insert("PLC");
  compatible.insert("DRL");
}

Owl::Owl(float _weight, pair<int,int> _position): Animal("OW",++owl_nb,'$',_weight,food,'K',_position) {
  eat = food;
  habitat.insert('A');
  compatible.insert("EGL");
  compatible.insert("OW");
  compatible.insert("PLC");
  compatible.insert("DRL");
}

Owl::~Owl(){}

Owl::Owl(const Owl& o): Animal(o.id,o.number,o.legend,o.weight,o.eat,o.type,o.position) {
  habitat = o.habitat;
}

Owl& Owl::operator= (const Owl& o) {
  SetWeight(o.GetWeight());
  SetPos(o.GetPos());
  return *this;
}

void Owl::Act() const {
  cout << id << "-";
  if (number < 10){
    cout << "0"; 
  }
  cout << number  << ": *hoot*" << endl;
}

void Owl::Interact() const {
  Description("owl");
  Act();
}
