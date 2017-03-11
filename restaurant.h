/* Author		: Andika Kusuma / 13515033
 * File			: restaurant.h
 */

#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <iostream>
#include "facility.h"

using namespace std;
/** @class Restaurant
  * Kelas restaurant turunan dari kelas facility berupa restoran di zoo
  */
class Restaurant : public Facility{
public:
	/** @brief Constructor.
	  * Menciptakan restaurant dengan posisi (x,y)
	  * @param x nilai posisi x yang diinginkan
	  * @param x nilai posisi y yang diinginkan
	  */
	Restaurant();

	/** @brief Destructor.
	  */
	~Restaurant();
	
};

#endif