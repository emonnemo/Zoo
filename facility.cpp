#include "facility.h"
#include "cell.h"
#include <iostream>

using namespace std;

Facility::Facility(){

}

Facility::Facility(char c){

}

Facility::Facility(const Facility& f){

}

Facility::~Facility(){

}

Facility& Facility::operator= (const Facility& f){

	return *this;
}

char Facility::GetSymbol() const{
	return Cell::GetSymbol();
}

