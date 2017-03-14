//File dugong.cpp

#include "dugong.h"
#include "../animal.h"
#include <iostream>
using namespace std;

int Dugong::dugong_nb = 0;

Dugong::Dugong(pair<int,int> _position):
        Animal("DGG", ++dugong_nb, '9', 294, food, 'H', _position) {
  eat = food;
  habitat.insert('W');
  compatible.insert("MRE");
  compatible.insert("DGG");
  compatible.insert("TRL");
  compatible.insert("DLP");
  compatible.insert("WHL");
  compatible.insert("PNG");
  compatible.insert("HPP");
  compatible.insert("PLC");
  compatible.insert("GSE");
  compatible.insert("CRN");
}

Dugong::Dugong(float _weight, pair<int,int> _position):
        Animal("DGG", ++dugong_nb, '9', _weight, food, 'H', _position) {
  eat = food;
  habitat.insert('W');
  compatible.insert("MRE");
  compatible.insert("DGG");
  compatible.insert("TRL");
  compatible.insert("DLP");
  compatible.insert("WHL");
  compatible.insert("PNG");
  compatible.insert("HPP");
  compatible.insert("PLC");
  compatible.insert("GSE");
  compatible.insert("CRN");
}

Dugong::~Dugong() {}

Dugong::Dugong(const Dugong& d):
       Animal(d.id, d.number, d.legend, d.weight, d.eat, d.type, d.position) {
  habitat = d.habitat;
}

Dugong& Dugong::operator=(const Dugong& d) {
  SetWeight(d.GetWeight());
  SetPos(d.GetPos());
  return *this;
}

void Dugong::Act() const {
  cout << id << "-";
  if (number < 10) {
    cout << "0";
  }
  cout << number  << ": *splash*" << endl;
}

void Dugong::Interact() const {
  Description("dugong");
  Act();
}
