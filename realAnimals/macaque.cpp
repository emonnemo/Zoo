//File macaque.cpp

#include "macaque.h"
#include "../animal.h"
#include <iostream>
using namespace std;

int Macaque::macaque_nb = 0;

Macaque::Macaque(pair<int,int> _position):
         Animal("MCQ", ++macaque_nb, '5', 9, food, 'O', _position) {
  eat = food;
  habitat.insert('L');
  compatible.insert("ZBR");
  compatible.insert("ELP");
  compatible.insert("MCQ");
  compatible.insert("HG");
  compatible.insert("HPP");
  compatible.insert("DRL");
  compatible.insert("CLG");
  compatible.insert("SGL");
}

Macaque::Macaque(float _weight, pair<int,int> _position):
         Animal("MCQ", ++macaque_nb, '5', _weight, food, 'O', _position) {
  eat = food;
  habitat.insert('L');
  compatible.insert("ZBR");
  compatible.insert("ELP");
  compatible.insert("MCQ");
  compatible.insert("HG");
  compatible.insert("HPP");
  compatible.insert("DRL");
  compatible.insert("CLG");
  compatible.insert("SGL");
}

Macaque::~Macaque() {}

Macaque::Macaque(const Macaque& m):
         Animal(m.id, m.number, m.legend, m.weight, m.eat, m.type, m.position) {
  habitat = m.habitat;
}

Macaque& Macaque::operator=(const Macaque& m) {
  SetWeight(m.GetWeight());
  SetPos(m.GetPos());
  return *this;
}

void Macaque::Act() const {
  cout << id << "-";
  if (number < 10) {
    cout << "0";
  }
  cout << number  << ": *chatter*" << endl;
}

void Macaque::Interact() const {
  Description("macaque");
  Act();
}
