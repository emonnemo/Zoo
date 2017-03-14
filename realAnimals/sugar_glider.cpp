//File sugar_glider.cpp

#include "sugar_glider.h"
#include "../animal.h"
#include <iostream>
using namespace std;

int SugarGlider::sugar_glider_nb = 0;

SugarGlider::SugarGlider(pair<int,int> _position):
             Animal("SGL", ++sugar_glider_nb, '>', 0.12, food, 'O', _position) {
  eat = food;
  habitat.insert('L');  
  habitat.insert('A');
  compatible.insert("ZBR");
  compatible.insert("MCQ");
  compatible.insert("HG");
  compatible.insert("PNG");
  compatible.insert("DRL");
  compatible.insert("CLG");
  compatible.insert("SGL");
  compatible.insert("HMB");
  compatible.insert("GSE");
  compatible.insert("CRN");
}

SugarGlider::SugarGlider(float _weight, pair<int,int> _position):
             Animal("SGL",
               ++sugar_glider_nb,
               '>',
               _weight,
               food,
               'O',
               _position) {
  eat = food;
  habitat.insert('L');
  habitat.insert('A');
  compatible.insert("ZBR");
  compatible.insert("MCQ");
  compatible.insert("HG");
  compatible.insert("PNG");
  compatible.insert("DRL");
  compatible.insert("CLG");
  compatible.insert("SGL");
  compatible.insert("HMB");
  compatible.insert("GSE");
  compatible.insert("CRN");
}

SugarGlider::~SugarGlider() {}

SugarGlider::SugarGlider(const SugarGlider& s):
             Animal(s.id,
               s.number,
               s.legend,
               s.weight,
               s.eat,
               s.type,
               s.position) {
  habitat = s.habitat;
}

SugarGlider& SugarGlider::operator=(const SugarGlider& s) {
  SetWeight(s.GetWeight());
  SetPos(s.GetPos());
  return *this;
}

void SugarGlider::Act() const {
  cout << id << "-";
  if (number < 10) {
    cout << "0";
  }
  cout << number  << ": *crab*" << endl;
}

void SugarGlider::Interact() const {
  Description("sugar glider");
  Act();
}
