//File bat.cpp

#include "bat.h"
#include "../animal.h"
#include <iostream>
using namespace std;

int Bat::bat_nb = 0;

Bat::Bat(pair<int,int> _position):
     Animal("BT", ++bat_nb, '*', 0.15, food, 'O', _position) {
  eat = food;
  habitat.insert('A');
  msg = " ";
  compatible.insert("HMB");
  compatible.insert("CKT");
  compatible.insert("RBN");
  compatible.insert("BT");
  compatible.insert("PLC");
  compatible.insert("GSE");
  compatible.insert("CRN");
}

Bat::Bat(float _weight, pair<int,int> _position):
     Animal("BT", ++bat_nb, '*', _weight, food, 'O', _position) {
  eat = food;
  habitat.insert('A');
  compatible.insert("HMB");
  compatible.insert("CKT");
  compatible.insert("RBN");
  compatible.insert("BT");
  compatible.insert("PLC");
  compatible.insert("GSE");
  compatible.insert("CRN");
}

Bat::~Bat(){}

Bat::Bat(const Bat& b): 
     Animal(b.id, b.number, b.legend, b.weight, b.eat, b.type, b.position) {
  habitat = b.habitat;
}

Bat& Bat::operator=(const Bat& b) {
  SetWeight(b.GetWeight());
  SetPos(b.GetPos());
  return *this;
}

void Bat::Act() const {
  cout << id << "-";
  if (number < 10){
    cout << "0"; 
  }
  cout << number  << ": *screech*" << endl;
}

void Bat::Interact() const {
  Description("bat");
  Act();
}
