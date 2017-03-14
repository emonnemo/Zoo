#include "road.h"
#include <iostream>

using namespace std;

Road::Road() {
  symbol = 'r';
  initsymbol = 'r';
}

Road::Road(char t) {
  symbol = t;
  initsymbol = t;
}

Road::~Road() {

}

void Road::Interact() const {}

void Road::ToggleSekat(int direction) {}
    
bool Road::GetSekat(int direction) const {
  return false;
}
