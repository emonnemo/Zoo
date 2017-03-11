/* Author		: Gisela Supardi / 13515009
 * File			: waterhabitat.cpp
 */

#ifndef HABITAT_H
#define HABITAT_H

#include <iostream>
#include "habitat.h"
using namespace std;

WaterHabitat::WaterHabitat() {
	symbol = '#';
}

WaterHabitat::~WaterHabitat(){}

WaterHabitat::WaterHabitat(const WaterHabitat& wh) {
	symbol = wh.symbol;
}

WaterHabitat& WaterHabitat::operator= (const WaterHabitat& wh){
	symbol = wh.symbol;
	return (*this);
}
