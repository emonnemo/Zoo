/* Author		: Gisela Supardi / 13515009
 * File			: waterhabitat.cpp
 */

#include <iostream>
#include "habitat.h"
using namespace std;

WaterHabitat::WaterHabitat(): Habitat('#'){}

WaterHabitat::WaterHabitat(const WaterHabitat& wh) {
	symbol = wh.symbol;
	initsymbol = wh.initsymbol;
}

WaterHabitat& WaterHabitat::operator= (const WaterHabitat& wh){
	symbol = wh.symbol;
	initsymbol = wh.initsymbol;
	return (*this);
}
