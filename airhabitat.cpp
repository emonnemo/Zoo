/* Author		: Gisela Supardi / 13515009
 * File			: airhabitat.cpp
 */

#ifndef HABITAT_H
#define HABITAT_H

#include <iostream>
#include "habitat.h"
using namespace std;

AirHabitat::AirHabitat() {
	symbol = 'o';
}

AirHabitat::~AirHabitat(){}

AirHabitat::AirHabitat(const AirHabitat& ah) {
	symbol = ah.symbol;
}

AirHabitat& AirHabitat::operator= (const AirHabitat& ah){
	symbol = ah.symbol;
	return (*this);
}
