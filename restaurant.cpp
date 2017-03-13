#include "restaurant.h"
#include <iostream>

using namespace std;

Restaurant::Restaurant() {
  symbol = 'R';
  initsymbol = 'R';
  food = "";
  open = false;
}

Restaurant::Restaurant(string f, bool o) {
  symbol = 'R';
  initsymbol = 'R';
  food = f;
  open = 0;
}

Restaurant::~Restaurant() {
  
}

string Restaurant::GetFood() const {
  return food;
}


bool Restaurant::GetOpen() const {
  return open;
}

void Restaurant::SetFood(string f) {
  food = f;
}

void Restaurant::ToggleOpen() {
  if (open) {
    open = false;
  } else {
    open = true;
  }
}

void Restaurant::Interact() const {
  if (open) {
    cout << "This restaurant sells " << food << endl;
  } else {
    cout << "This restaurant is closed" << endl;
  }
}


void Restaurant::ToggleSekat(int direction) {

}
    
bool Restaurant::GetSekat(int direction) const {
  return false;
}
