//File hog.cpp

#include "hog.h"
#include "../animal.h"
#include <iostream>
using namespace std;

int Hog::hog_nb = 0;

Hog::Hog(pair<int,int> _position):
     Animal("HG", ++hog_nb, '6', 68, food, 'O', _position) {
  eat = food;
  habitat.insert('L');
  compatible.insert("ZBR");
  compatible.insert("ELP");
  compatible.insert("MCQ");
  compatible.insert("HG");
  compatible.insert("HPP");
}

Hog::Hog(float _weight, pair<int,int> _position):
     Animal("HG", ++hog_nb, '6', _weight, food, 'O', _position) {
  eat = food;
  habitat.insert('L');
  compatible.insert("ZBR");
  compatible.insert("ELP");
  compatible.insert("MCQ");
  compatible.insert("HG");
  compatible.insert("HPP");
}

Hog::~Hog() {}

Hog::Hog(const Hog& h):
     Animal(h.id, h.number, h.legend, h.weight, h.eat, h.type, h.position) {
  habitat = h.habitat;
}

Hog& Hog::operator=(const Hog& h) {
  SetWeight(h.GetWeight());
  SetPos(h.GetPos());
  return *this;
}

void Hog::Act() const {
  cout << id << "-";
  if (number < 10) {
    cout << "0";
  }
  cout << number  << ": *oink*" << endl;
}

void Hog::Interact() const {
  Description("hog");
  Act();
}
