/* Author		: Gisela Supardi / 13515009
 * File			: landhabitat.h
 */

#ifndef HABITAT_H
#define HABITAT_H

#include <iostream>
#include "habitat.h"
using namespace std;

/**
 * \brief Class LandHabitat
 * \details real class untuk habitat darat
 * \return suatu sel yang memiliki karakteristik habitat darat
 */
class LandHabitat: public Habitat () {
public:
	/**
	 * \brief Constructor
	 * \details Menciptakan land habitat yaitu cell yang di-assign simbol 'x'
	 * 
	 */
	LandHabitat();
	/**
	 * \brief Copy Constructor
	 * \details copy constructor menjamin tidak bitwise copy.
	 * 
	 * \param lh land habitat yang ingin dikopi
	 */
	LandHabitat(const LandHabitat& lh);
	/**
	 * \brief Operator =
	 * \details operator = menjamin tidak bitwise copy.
	 * 
	 * \param lh land habitat yang ingin di-copy
	 * \return land habitat yang sama dengan lh
	 */
	LandHabitat& operator= (const LandHabitat& lh);
};

#endif
