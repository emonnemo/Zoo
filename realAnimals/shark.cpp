//File shark.cpp

#include "shark.h"
#include "../animal.h"
#include <iostream>
using namespace std;

int Shark::SharkNB = 0;

Shark::Shark(pair<int,int> _position): Animal("SHK",++SharkNB,'7',771,food,'K',_position) {
  eat = food;
  habitat.insert('W');
  compatible.insert("SHK");
  compatible.insert("WHL");
}

Shark::Shark(float _weight, pair<int,int> _position): Animal("SHK",++SharkNB,'7',_weight,food,'K',_position) {
  eat = food;
  habitat.insert('W');
  compatible.insert("SHK");
  compatible.insert("WHL");
}

Shark::~Shark(){}

Shark::Shark(const Shark& w): Animal(w.ID,w.id,w.legend,w.weight,w.eat,w.type,w.position) {
  habitat = w.habitat;
}

Shark& Shark::operator= (const Shark& w) {
  SetWeight(w.GetWeight());
  SetPos(w.GetPos());
  return *this;
}

void Shark::Act() const {
  cout << ID << "-";
  if (id < 10){
    cout << "0"; 
  }
  cout << id  << ": *cruise*" << endl;
}

void Shark::Interact() const {
  Description("shark");
  Act();
}
