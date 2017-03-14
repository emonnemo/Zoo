//File eagle.cpp

#include "eagle.h"
#include "../animal.h"
#include <iostream>
using namespace std;

int Eagle::eagle_nb = 0;

Eagle::Eagle(pair<int,int> _position):
       Animal("EGL", ++eagle_nb, '#', 4, food, 'K', _position) {
  eat = food;
  habitat.insert('A');
  compatible.insert("EGL");
  compatible.insert("OW");
  compatible.insert("PLC");
}

Eagle::Eagle(float _weight, pair<int,int> _position):
       Animal("EGL", ++eagle_nb, '#', _weight, food, 'K', _position) {
  eat = food;
  habitat.insert('A');
  compatible.insert("EGL");
  compatible.insert("OW");
  compatible.insert("PLC");
}

Eagle::~Eagle() {}

Eagle::Eagle(const Eagle& e):
       Animal(e.id, e.number, e.legend, e.weight, e.eat, e.type, e.position) {
  habitat = e.habitat;
}

Eagle& Eagle::operator=(const Eagle& e) {
  SetWeight(e.GetWeight());
  SetPos(e.GetPos());
  return *this;
}

void Eagle::Act() const {
  cout << id << "-";
  if (number < 10) {
    cout << "0";
  }
  cout << number  << ": *scream*" << endl;
}

void Eagle::Interact() const {
  Description("eagle");
  Act();
}
