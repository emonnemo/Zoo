//File hummingbird.cpp

#include "hummingbird.h"
#include "../animal.h"
#include <iostream>
using namespace std;

int Hummingbird::hummingbird_nb = 0;

Hummingbird::Hummingbird(pair<int,int> _position):
             Animal("HMB",
              ++hummingbird_nb,
              '%',
              0.0002,
              food,
              'H',
              _position) {
  eat = food;
  habitat.insert('A');
  compatible.insert("HMB");
  compatible.insert("CKT");
  compatible.insert("RBN");
  compatible.insert("BT");
  compatible.insert("PLC");
  compatible.insert("GSE");
  compatible.insert("CRN");
  compatible.insert("CLG");
  compatible.insert("SGL");
}

Hummingbird::Hummingbird(float _weight, pair<int,int> _position):
             Animal("HMB",
                    ++hummingbird_nb,
                    '%',
                    _weight,
                    food,
                    'H',
                    _position) {
  eat = food;
  habitat.insert('A');
  compatible.insert("HMB");
  compatible.insert("CKT");
  compatible.insert("RBN");
  compatible.insert("BT");
  compatible.insert("PLC");
  compatible.insert("GSE");
  compatible.insert("CRN");
  compatible.insert("CLG");
  compatible.insert("SGL");
}

Hummingbird::~Hummingbird() {}

Hummingbird::Hummingbird(const Hummingbird& h):
             Animal(h.id,
                    h.number,
                    h.legend,
                    h.weight,
                    h.eat,
                    h.type,
                    h.position) {
  habitat = h.habitat;
}

Hummingbird& Hummingbird::operator=(const Hummingbird& h) {
  SetWeight(h.GetWeight());
  SetPos(h.GetPos());
  return *this;
}

void Hummingbird::Act() const {
  cout << id << "-";
  if (number < 10) {
    cout << "0";
  }
  cout << number  << ": *hum*" << endl;
}

void Hummingbird::Interact() const {
  Description("hummingbird");
  Act();
}
