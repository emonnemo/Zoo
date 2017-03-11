#include "cell.h"
#include <iostream>

using namespace std;

Cell::Cell(){
	symbol = ' ';
	initsymbol = ' ';
}

Cell::Cell(char c){
	initsymbol = c;
	symbol = c;
}

Cell::Cell(const Cell& c){
	initsymbol = c.initsymbol;
	symbol = c.symbol;
}

Cell::~Cell(){

}

Cell& Cell::operator=(const Cell& c){
	initsymbol = c.initsymbol;
	symbol = c.symbol;
	return *this;
}

ostream& operator<< (ostream& os, const Cell& c){
	os << c.symbol;
	return os;
}

char Cell::GetInitSymbol() const{
	return initsymbol;
}

char Cell::GetSymbol() const{
	return symbol;
}

void Cell::SetSymbol(char s){
	symbol = s;
}
