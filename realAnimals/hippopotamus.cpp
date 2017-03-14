//File hippopotamus.cpp

#include "hippopotamus.h"
#include "../animal.h"
#include <iostream>
using namespace std;

int Hippopotamus::hippopotamus_nb = 0;

Hippopotamus::Hippopotamus(pair<int,int> _position): Animal("HPP", ++hippopotamus_nb, ')', 1496, food, 'H', _position) {
  eat = food;
  habitat.insert('L');  
  habitat.insert('W');
  compatible.insert("WF");
  compatible.insert("ZBR");
  compatible.insert("ELP");
  compatible.insert("MCQ");
  compatible.insert("HG");
  compatible.insert("PNG");
  compatible.insert("HPP");
  compatible.insert("CLG");
  compatible.insert("MRE");
  compatible.insert("DGG");
  compatible.insert("TRL");
  compatible.insert("DLP");
  compatible.insert("WHL");
  compatible.insert("PLC");
  compatible.insert("GSE");
  compatible.insert("CRN");
}

Hippopotamus::Hippopotamus(float _weight, pair<int,int> _position): Animal("HPP", ++hippopotamus_nb, ')', _weight, food, 'H', _position) {
  eat = food;
  habitat.insert('L');
  habitat.insert('W');
  compatible.insert("WF");
  compatible.insert("ZBR");
  compatible.insert("ELP");
  compatible.insert("MCQ");
  compatible.insert("HG");
  compatible.insert("PNG");
  compatible.insert("HPP");
  compatible.insert("CLG");
  compatible.insert("MRE");
  compatible.insert("DGG");
  compatible.insert("TRL");
  compatible.insert("DLP");
  compatible.insert("WHL");
  compatible.insert("PLC");
  compatible.insert("GSE");
  compatible.insert("CRN");
}

Hippopotamus::~Hippopotamus(){}

Hippopotamus::Hippopotamus(const Hippopotamus& h): Animal(h.id,h.number,h.legend,h.weight,h.eat,h.type,h.position) {
  habitat = h.habitat;
}

Hippopotamus& Hippopotamus::operator= (const Hippopotamus& h) {
  SetWeight(h.GetWeight());
  SetPos(h.GetPos());
  return *this;
}

void Hippopotamus::Act() const {
  cout << id << "-";
  if (number < 10){
    cout << "0"; 
  }
  cout << number  << ": *grunt*" << endl;
}

void Hippopotamus::Interact() const {
  Description("hippopotamus");
  Act();
}
