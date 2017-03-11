/* Author		: Gisela Supardi / 13515009
 * File			: landhabitat.cpp
 */

#ifndef HABITAT_H
#define HABITAT_H

#include <iostream>
#include "landhabitat.h"
using namespace std;

 
LandHabitat::LandHabitat() {
	symbol = 'x';
}

LandHabitat::~LandHabitat(){}

LandHabitat::LandHabitat(const LandHabitat& lh){
	symbol = lh.symbol;
}

LandHabitat& LandHabitat::operator= (const LandHabitat& lh) {
	symbol = lh.symbol;
}
