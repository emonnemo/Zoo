//File lion.cpp

#include "lion.h"
#include "../animal.h"
#include <iostream>
using namespace std;

int Lion::lion_nb = 0;

Lion::Lion(pair<int,int> _position):
      Animal("LI",++lion_nb,'2',158,food,'K',_position) {
  eat = food;
  habitat.insert('L');
  compatible.insert("LI");
}

Lion::Lion(float _weight, pair<int,int> _position):
      Animal("LI",++lion_nb,'2',_weight,food,'K',_position) {
  eat = food;
  habitat.insert('L');
  compatible.insert("LI");
}

Lion::~Lion() {}

Lion::Lion(const Lion& l):
      Animal(l.id, l.number, l.legend, l.weight, l.eat, l.type, l.position) {
  habitat = l.habitat;
}

Lion& Lion::operator=(const Lion& l) {
  SetWeight(l.GetWeight());
  SetPos(l.GetPos());
  return *this;
}

void Lion::Act() const {
  cout << id << "-";
  if (number < 10) {
    cout << "0";
  }
  cout << number  << ": *roar*" << endl;
}

void Lion::Interact() const {
  Description("lion");
  Act();
}
