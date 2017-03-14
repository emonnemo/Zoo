//File shark.cpp

#include "shark.h"
#include "../animal.h"
#include <iostream>
using namespace std;

int Shark::shark_nb = 0;

Shark::Shark(pair<int,int> _position): Animal("SHK", ++shark_nb, '7', 771, food, 'K', _position) {
  eat = food;
  habitat.insert('W');
  compatible.insert("SHK");
  compatible.insert("WHL");
}

Shark::Shark(float _weight, pair<int,int> _position): Animal("SHK", ++shark_nb, '7', _weight, food, 'K', _position) {
  eat = food;
  habitat.insert('W');
  compatible.insert("SHK");
  compatible.insert("WHL");
}

Shark::~Shark(){}

Shark::Shark(const Shark& s): Animal(s.id, s.number, s.legend, s.weight, s.eat, s.type, s.position) {
  habitat = s.habitat;
}

Shark& Shark::operator= (const Shark& s) {
  SetWeight(s.GetWeight());
  SetPos(s.GetPos());
  return *this;
}

void Shark::Act() const {
  cout << id << "-";
  if (number < 10){
    cout << "0"; 
  }
  cout << number  << ": *cruise*" << endl;
}

void Shark::Interact() const {
  Description("shark");
  Act();
}
