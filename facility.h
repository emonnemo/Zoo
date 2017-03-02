/* Author		: Andika Kusuma / 13515033
 * File			: facility.h
 */

#ifndef FACILITY_H
#define FACILITY_H

#include <iostream>
#include "cell.h"

using namespace std;
/** @class Facility
  * Kelas abstrak facility turunan dari kelas cell berupa restoran, road, atau park
  */
class Facility : public Cell{
	/** @brief Constructor.
	  * Menciptakan facility dengan letak (x,y)
	  * @param x nilai posisi x yang diinginkan
	  * @param y nilai posisi y yang diinginkan
	  */
	Facility(int x, int y);

	/**
	 * @brief destructor
	 */
	~Facility();
	
};

#endif
