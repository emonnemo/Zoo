/* Author		: Gisela Supardi / 13515009
 * File			: airhabitat.h
 */

#ifndef HABITAT_H
#define HABITAT_H

#include <iostream>
#include "habitat.h"
using namespace std;

/**
 * \brief Class LandHabitat
 * \details real class untuk habitat udara
 * \return suatu sel yang memiliki karakteristik habitat udara
 */
class AirHabitat: public Habitat () {
public:
	/**
	 * \brief Constructor
	 * \details Menciptakan air habitat yaitu cell yang di-assign simbol 'o'
	 * 
	 * \param x posisi baris yang diinginkan
	 * \param y posisi kolom yang diinginkan
	 */
	AirHabitat(int x, int y);
	/**
	 * \brief Destructor
	 * \details Mengembalikan memori kepada sistem
	 */
	~AirHabitat();
	/**
	 * \brief Copy Constructor
	 * \details copy constructor menjamin tidak bitwise copy.
	 * 
	 * \param ah air habitat yang ingin dikopi
	 */
	AirHabitat(const AirHabitat& ah);
	/**
	 * \brief Operator =
	 * \details operator = menjamin tidak bitwise copy.
	 * 
	 * \param ah air habitat yang ingin di-copy
	 * \return air habitat yang sama dengan wh
	 */
	AirHabitat& operator= (const AirHabitat& ah);
};

#endif
