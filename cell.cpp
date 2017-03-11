#include "cell.h"
#include <iostream>

using namespace std;

Cell::Cell(){
	symbol = '';
}

Cell::Cell(char c){
	initsymbol = c;
	symbol = c;
}

Cell::Cell(const Cell& c){
	initsymbol = c.initsymbol;
	symbol = c.symbol;
}

Cell& operator=(const Cell& c){
	initsymbol = c.initsymbol;
	symbol = c.symbol;
}

friend ostream& operator<< (ostream& os, const Cell& c){
	os << c.symbol;
	return os;
}
<<<<<<< HEAD
Cell& Cell::operator=(const Cell& c){
	cout << "cell opr=\n";
}
=======

>>>>>>> f36fb222cdf3260e152db16ef21dbe10d2b7b08c
char Cell::GetSymbol() const{
	return symbol;
}

void Cell::SetInitSymbol(char is){
	initsymbol = is;
}

void Cell:SetSymbol(char s){
	symbol = s;
}
