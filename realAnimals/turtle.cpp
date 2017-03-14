//File turtle.cpp

#include "turtle.h"
#include "../animal.h"
#include <iostream>
using namespace std;

int Turtle::turtle_nb = 0;

Turtle::Turtle(pair<int,int> _position): Animal("TRL", ++turtle_nb, '0', 453, food, 'H', _position) {
  eat = food;
  habitat.insert('W');
  compatible.insert("MRE");
  compatible.insert("DGG");
  compatible.insert("TRL");
  compatible.insert("DLP");
  compatible.insert("WHL");
  compatible.insert("PNG");
  compatible.insert("HPP");
  compatible.insert("GSE");
  compatible.insert("CRN");
}

Turtle::Turtle(float _weight, pair<int,int> _position): Animal("TRL", ++turtle_nb, '0', _weight, food, 'H', _position) {
  eat = food;
  habitat.insert('W');
  compatible.insert("MRE");
  compatible.insert("DGG");
  compatible.insert("TRL");
  compatible.insert("DLP");
  compatible.insert("WHL");
  compatible.insert("PNG");
  compatible.insert("HPP");
  compatible.insert("GSE");
  compatible.insert("CRN");
}

Turtle::~Turtle(){}

Turtle::Turtle(const Turtle& w): Animal(w.id,w.number,w.legend,w.weight,w.eat,w.type,w.position) {
  habitat = w.habitat;
}

Turtle& Turtle::operator= (const Turtle& t) {
  SetWeight(t.GetWeight());
  SetPos(t.GetPos());
  return *this;
}

void Turtle::Act() const {
  cout << id << "-";
  if (number < 10){
    cout << "0"; 
  }
  cout << number  << ": *swim*" << endl;
}

void Turtle::Interact() const {
  Description("turtle");
  Act();
}
