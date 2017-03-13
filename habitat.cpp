/* Author    : Gisela Supardi / 13515009
 * File      : habitat.cpp
 */

#include "habitat.h"
using namespace std;

Habitat::Habitat(char s) {
  symbol = s;
  initsymbol = s;
  for (int i = 0; i < 4; ++i) {
    sekat[i] = false;
  }
}

Habitat::~Habitat() {
  
}

void Habitat::ToggleSekat(int direction) {
  if (sekat[direction]) {
    sekat[direction] = false;
  } else {
    sekat[direction] = true;
  }
}

bool Habitat::GetSekat(int direction) const {
  return sekat[direction];
}

void Habitat::Interact() const {
  
}
