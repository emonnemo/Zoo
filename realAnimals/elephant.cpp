//File elephant.cpp

#include "elephant.h"
#include "../animal.h"
#include <iostream>
using namespace std;

int Elephant::elephant_nb = 0;

Elephant::Elephant(pair<int,int> _position):
          Animal("ELP", ++elephant_nb, '4', 5000, food, 'H', _position) {
  eat = food;
  habitat.insert('L');
  compatible.insert("WF");
  compatible.insert("ZBR");
  compatible.insert("ELP");
  compatible.insert("MCQ");
  compatible.insert("HG");
  compatible.insert("PNG");
  compatible.insert("HPP");
}

Elephant::Elephant(float _weight, pair<int,int> _position):
          Animal("ELP", ++elephant_nb, '4', _weight, food, 'H', _position) {
  eat = food;
  habitat.insert('L');
  compatible.insert("WF");
  compatible.insert("ZBR");
  compatible.insert("ELP");
  compatible.insert("MCQ");
  compatible.insert("HG");
  compatible.insert("PNG");
  compatible.insert("HPP");
}

Elephant::~Elephant() {}

Elephant::Elephant(const Elephant& e):
          Animal(e.id,
                 e.number,
                 e.legend,
                 e.weight,
                 e.eat,
                 e.type,
                 e.position) {
  habitat = e.habitat;
}

Elephant& Elephant::operator=(const Elephant& e) {
  SetWeight(e.GetWeight());
  SetPos(e.GetPos());
  return *this;
}

void Elephant::Act() const {
  cout << id << "-";
  if (number < 10) {
    cout << "0";
  }
  cout << number  << ": *trumpet*" << endl;
}

void Elephant::Interact() const {
  Description("elephant");
  Act();
}
