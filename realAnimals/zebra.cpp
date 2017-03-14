//File zebra.cpp

#include "zebra.h"
#include "../animal.h"
#include <iostream>
using namespace std;

int Zebra::zebra_nb = 0;

Zebra::Zebra(pair<int,int> _position): Animal("ZBR", ++zebra_nb, '3', 226, food, 'H', _position) {
  eat = food;
  habitat.insert('L');
  compatible.insert("ZBR");
  compatible.insert("ELP");
  compatible.insert("MCQ");
  compatible.insert("HG");
  compatible.insert("PNG");
  compatible.insert("HPP");
  compatible.insert("DRL");
  compatible.insert("CLG");
  compatible.insert("SGL");
}

Zebra::Zebra(float _weight, pair<int,int> _position): Animal("ZBR", ++zebra_nb, '3', _weight, food, 'H', _position) {
  eat = food;
  habitat.insert('L');
  compatible.insert("ZBR");
  compatible.insert("ELP");
  compatible.insert("MCQ");
  compatible.insert("HG");
  compatible.insert("PNG");
  compatible.insert("HPP");
  compatible.insert("DRL");
  compatible.insert("CLG");
  compatible.insert("SGL");
}

Zebra::~Zebra(){}

Zebra::Zebra(const Zebra& z): Animal(z.id, z.number, z.legend, z.weight, z.eat, z.type, z.position) {
  habitat = z.habitat;
}

Zebra& Zebra::operator= (const Zebra& z) {
  SetWeight(z.GetWeight());
  SetPos(z.GetPos());
  return *this;
}

void Zebra::Act() const {
  cout << id << "-";
  if (number < 10){
    cout << "0"; 
  }
  cout << number  << ": *snort*" << endl;
}

void Zebra::Interact() const {
  Description("zebra");
  Act();
}
