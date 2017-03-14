//File wolf.cpp

#include "wolf.h"
#include "../animal.h"
#include <iostream>
using namespace std;

int Wolf::wolf_nb = 0;

Wolf::Wolf(pair<int,int> _position):
      Animal("WF", ++wolf_nb, '1', 45, food, 'K', _position) {
  eat = food;
  habitat.insert('L');
  compatible.insert("LI");
  compatible.insert("ELP");
  compatible.insert("HPP");
}

Wolf::Wolf(float _weight, pair<int,int> _position):
      Animal("WF", ++wolf_nb, '1', _weight, food, 'K', _position) {
  eat = food;
  habitat.insert('L');
  compatible.insert("LI");
  compatible.insert("ELP");
  compatible.insert("HPP");
}

Wolf::~Wolf() {}

Wolf::Wolf(const Wolf& w):
      Animal(w.id, w.number, w.legend, w.weight, w.eat, w.type, w.position) {
  habitat = w.habitat;
}

Wolf& Wolf::operator=(const Wolf& w) {
  SetWeight(w.GetWeight());
  SetPos(w.GetPos());
  return *this;
}

void Wolf::Act() const {
  cout << id << "-";
  if (number < 10) {
    cout << "0";
  }
  cout << number  << ": *howl*" << endl;
}

void Wolf::Interact() const {
  Description("wolf");
  Act();
}
