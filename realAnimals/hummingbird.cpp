//File hummingbird.cpp

#include "hummingbird.h"
#include "../animal.h"
#include <iostream>
using namespace std;

int Hummingbird::humbirdNB = 0;

Hummingbird::Hummingbird(pair<int,int> _position): Animal("HMB",++humbirdNB,'%',0.0002,food,'H',_position) {
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

Hummingbird::Hummingbird(float _weight, pair<int,int> _position): Animal("HMB",++humbirdNB,'%',_weight,food,'H',_position) {
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

Hummingbird::~Hummingbird(){}

Hummingbird::Hummingbird(const Hummingbird& h): Animal(h.ID,h.id,h.legend,h.weight,h.eat,h.type,h.position) {
  habitat = h.habitat;
}

Hummingbird& Hummingbird::operator= (const Hummingbird& h) {
  SetWeight(h.GetWeight());
  SetPos(h.GetPos());
  return *this;
}

void Hummingbird::Act() const {
  cout << ID << "-";
  if (id < 10){
    cout << "0"; 
  }
  cout << id  << ": *hum*" << endl;
}

void Hummingbird::Interact() const {
  Description("hummingbird");
  Act();
}
