/* Author		: Gisela Supardi / 13515009
 * File			: habitat.cpp
 */

#include "habitat.h"
using namespace std;

Habitat::Habitat(char s): Cell(s){}

Habitat::Habitat(const Habitat& h){
	symbol = h.symbol;
	initsymbol = h.initsymbol;
}

Habitat& Habitat::operator= (const Habitat& h){
	symbol = h.symbol;
	initsymbol = h.initsymbol;
	return (*this);
}
