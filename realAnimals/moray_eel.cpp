//File moray_eel.cpp

#include "moray_eel.h"
#include "../animal.h"
#include <iostream>
using namespace std;

int MorayEel::moray_eel_nb = 0;

MorayEel::MorayEel(pair<int,int> _position): Animal("MRE", ++moray_eel_nb, '8', 13, food, 'K', _position) {
  eat = food;
  habitat.insert('W');
  compatible.insert("MRE");
  compatible.insert("DGG");
  compatible.insert("TRL");
  compatible.insert("DLP");
  compatible.insert("WHL");
  compatible.insert("HPP");
}

MorayEel::MorayEel(float _weight, pair<int,int> _position): Animal("MRE", ++moray_eel_nb, '8', _weight, food, 'K', _position) {
  eat = food;
  habitat.insert('W');
  compatible.insert("MRE");
  compatible.insert("DGG");
  compatible.insert("TRL");
  compatible.insert("DLP");
  compatible.insert("WHL");
  compatible.insert("HPP");
}

MorayEel::~MorayEel(){}

MorayEel::MorayEel(const MorayEel& m): Animal(m.id, m.number, m.legend, m.weight, m.eat, m.type, m.position) {
  habitat = m.habitat;
}

MorayEel& MorayEel::operator= (const MorayEel& m) {
  SetWeight(m.GetWeight());
  SetPos(m.GetPos());
  return *this;
}

void MorayEel::Act() const {
  cout << id << "-";
  if (number < 10){
    cout << "0"; 
  }
  cout << number  << ": *hide into rocks*" << endl;
}

void MorayEel::Interact() const {
  Description("moray eel");
  Act();
}
