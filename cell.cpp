#include "cell.h"
#include <iostream>

using namespace std;

Cell::Cell(){
	cout << "cell ctor\n";
}
Cell::~Cell(){
	cout << "cell dtor\n";
}
char Cell::GetSymbol() const{
	return symbol;
}