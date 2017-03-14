#include "cell.h"
#include <iostream>

using namespace std;

Cell::Cell() {}

Cell::Cell(char c) {
  initsymbol = c;
  symbol = c;
}

Cell::~Cell() {

}

ostream& operator<<(ostream& os, const Cell& c) {
  os << c.symbol;
  return os;
}

char Cell::GetInitSymbol() const {
  return initsymbol;
}

char Cell::GetSymbol() const {
  return symbol;
}

void Cell::SetSymbol(char s) {
  symbol = s;
}

void Cell::Render(){
	cout << symbol;
}
