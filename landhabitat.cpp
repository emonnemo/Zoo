/* Author		: Gisela Supardi / 13515009
 * File			: landhabitat.cpp
 */

#include <iostream>
#include "landhabitat.h"
using namespace std;

 
LandHabitat::LandHabitat(): Habitat('x') {}

LandHabitat::LandHabitat(const LandHabitat& lh){
	symbol = lh.symbol;
	initsymbol = lh.symbol;
}

LandHabitat& LandHabitat::operator= (const LandHabitat& lh) {
	symbol = lh.symbol;
	initsymbol = lh.initsymbol;
	return (*this);
}
