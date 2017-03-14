#include "cell.h"
#include <iostream>

using namespace std;

Cell::Cell() {}

Cell::Cell(char c) {
  initsymbol = c;
  symbol = c;
}

Cell::~Cell() {}

char Cell::GetInitSymbol() const {
  return initsymbol;
}

char Cell::GetSymbol() const {
  return symbol;
}

void Cell::SetSymbol(char s) {
  symbol = s;
}

void Cell::Render() {
  cout << symbol;
}
