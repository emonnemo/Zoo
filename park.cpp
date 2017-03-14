#include "park.h"
#include <iostream>

using namespace std;

Park::Park() {
  symbol = 'P'; 
  initsymbol = 'P';
  plant = "";
}

Park::Park(string p) {
  symbol = 'P';
  initsymbol = 'P';
  plant = p;
}

Park::~Park() {

}

string Park::GetPlant() const {
  return plant;
}

void Park::SetPlant(string p) {
  plant = p;
}

void Park::Interact() const {
  cout << "This park has ";
  if (plant != "") {
    cout << plant;
  } else {
    cout << "nothing";
  }
  cout << " planted on it" << endl;
}

void Park::ToggleSekat(int direction) {

}
    
bool Park::GetSekat(int direction) const {
  return false;
}
