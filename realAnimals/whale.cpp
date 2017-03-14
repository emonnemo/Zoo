//File whale.cpp

#include "whale.h"
#include "../animal.h"
#include <iostream>
using namespace std;

int Whale::whale_nb = 0;

Whale::Whale(pair<int,int> _position):
       Animal("WHL", ++whale_nb, '@', 40000, food, 'O', _position) {
  eat = food;
  habitat.insert('W');
  compatible.insert("SHK");
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

Whale::Whale(float _weight, pair<int,int> _position):
       Animal("WHL", ++whale_nb, '@', _weight, food, 'O', _position) {
  eat = food;
  habitat.insert('W');
  compatible.insert("SHK");
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

Whale::~Whale() {}

Whale::Whale(const Whale& w):
       Animal(w.id, w.number, w.legend, w.weight, w.eat, w.type, w.position) {
  habitat = w.habitat;
}

Whale& Whale::operator=(const Whale& w) {
  SetWeight(w.GetWeight());
  SetPos(w.GetPos());
  return *this;
}

void Whale::Act() const {
  cout << id << "-";
  if (number < 10) {
    cout << "0";
  }
  cout << number  << ": *sing*" << endl;
}

void Whale::Interact() const {
  Description("whale");
  Act();
}
