/* Author		: Gisela Supardi / 13515009
 * File			: waterhabitat.h
 */

#ifndef HABITAT_H
#define HABITAT_H

#include <iostream>
#include "habitat.h"
using namespace std;

/**
 * \brief Class WaterHabitat
 * \details real class untuk habitat air
 * \return suatu sel yang memiliki karakteristik habitat air
 */
class WaterHabitat: public Habitat () {
public:
	/**
	 * \brief Constructor
	 * \details Menciptakan water habitat yaitu cell yang di-assign simbol '#'
	 * 
	 * \param x posisi baris yang diinginkan
	 * \param y posisi kolom yang diinginkan
	 */
	WaterHabitat();
	/**
	 * \brief Copy Constructor
	 * \details copy constructor menjamin tidak bitwise copy.
	 * 
	 * \param wh water habitat yang ingin dikopi
	 */
	WaterHabitat(const WaterHabitat& wh);
	/**
	 * \brief Operator =
	 * \details operator = menjamin tidak bitwise copy.
	 * 
	 * \param wh water habitat yang ingin di-copy
	 * \return water habitat yang sama dengan wh
	 */
	WaterHabitat& operator= (const WaterHabitat& wh);
};

#endif
