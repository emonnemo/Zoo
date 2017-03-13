//File macaque.cpp

#include "macaque.h"
#include "../animal.h"
#include <iostream>
using namespace std;

int Macaque::MacaqueNB = 0;

Macaque::Macaque(pair<int,int> _position): Animal("MCQ",++MacaqueNB,'5',9,food,'O',_position) {
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

Macaque::Macaque(float _weight, pair<int,int> _position): Animal("MCQ",++MacaqueNB,'5',_weight,food,'O',_position) {
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

Macaque::~Macaque(){}

Macaque::Macaque(const Macaque& w): Animal(w.ID,w.id,w.legend,w.weight,w.eat,w.type,w.position) {
  habitat = w.habitat;
}

Macaque& Macaque::operator= (const Macaque& w) {
  SetWeight(w.GetWeight());
  SetPos(w.GetPos());
  return *this;
}

void Macaque::Act() const {
  cout << ID << "-";
  if (id < 10){
    cout << "0"; 
  }
  cout << id  << ": *chatter*" << endl;
}

void Macaque::Interact() const {
  Description("macaque");
  Act();
}
