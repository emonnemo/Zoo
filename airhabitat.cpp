/* Author		: Gisela Supardi / 13515009
 * File			: airhabitat.cpp
 */

#ifndef HABITAT_H
#define HABITAT_H

#include <iostream>
#include "habitat.h"
using namespace std;

AirHabitat::AirHabitat(): Habitat('o'){}

AirHabitat::AirHabitat(const AirHabitat& ah) {
	symbol = ah.symbol;
	initsymbol = ah.initsymbol;
}

AirHabitat& AirHabitat::operator= (const AirHabitat& ah){
	symbol = ah.symbol;
	initsymbol = ah.initsymbol;
	return (*this);
}
