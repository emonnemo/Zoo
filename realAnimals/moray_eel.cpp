//File moray_eel.cpp

#include "moray_eel.h"
#include "../animal.h"
#include <iostream>
using namespace std;

int Moray_Eel::morayEelNB = 0;

Moray_Eel::Moray_Eel(pair<int,int> _position): Animal("MRE",++morayEelNB,'8',13,food,'K',_position) {
  eat = food;
  habitat.insert('W');
  compatible.insert("MRE");
  compatible.insert("DGG");
  compatible.insert("TRL");
  compatible.insert("DLP");
  compatible.insert("WHL");
  compatible.insert("HPP");
}

Moray_Eel::Moray_Eel(float _weight, pair<int,int> _position): Animal("MRE",++morayEelNB,'8',_weight,food,'K',_position) {
  eat = food;
  habitat.insert('W');
  compatible.insert("MRE");
  compatible.insert("DGG");
  compatible.insert("TRL");
  compatible.insert("DLP");
  compatible.insert("WHL");
  compatible.insert("HPP");
}

Moray_Eel::~Moray_Eel(){}

Moray_Eel::Moray_Eel(const Moray_Eel& w): Animal(w.id,w.number,w.legend,w.weight,w.eat,w.type,w.position) {
  habitat = w.habitat;
}

Moray_Eel& Moray_Eel::operator= (const Moray_Eel& w) {
  SetWeight(w.GetWeight());
  SetPos(w.GetPos());
  return *this;
}

void Moray_Eel::Act() const {
  cout << id << "-";
  if (number < 10){
    cout << "0"; 
  }
  cout << number  << ": *hide into rocks*" << endl;
}

void Moray_Eel::Interact() const {
  Description("moray eel");
  Act();
}
