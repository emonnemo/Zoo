#include "facility.h"
#include "cell.h"
#include <iostream>

using namespace std;

Facility::Facility() {
	symbol = 'F';
	initsymbol = 'F';
}

Facility::Facility(const Facility& f){
	symbol = f.symbol;
	initsymbol = f.initsymbol;
}

Facility::~Facility(){

}

Facility& Facility::operator= (const Facility& f){
	initsymbol = f.initsymbol;
	symbol = f.symbol;
	return *this;
}
