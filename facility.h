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

	/** @brief Destructor.
	  */
	~Facility();
	
};

/** @class Park
  * Kelas Park turunan dari kelas facility berupa taman di zoo
  */
class Park : public Facility{
	/** @brief Constructor.
	  * Menciptakan park dengan posisi (x,y)
	  * @param x nilai posisi x yang diinginkan
	  * @param x nilai posisi y yang diinginkan
	  */
	Park(int x, int y);

	/** @brief Destructor.
	  */
	~Park();
	
};

#endif
