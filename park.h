/* Author		: Andika Kusuma / 13515033
 * File			: park.h
 */

#ifndef PARK_H
#define PARK_H

#include <iostream>
#include "facility.h"

using namespace std;
/** @class Park
  * Kelas Park turunan dari kelas facility berupa taman di zoo
  */
class Park : public Facility{
public:
	/** @brief Constructor.
	  * Menciptakan park dengan posisi (x,y)
	  * @param x nilai posisi x yang diinginkan
	  * @param x nilai posisi y yang diinginkan
	  */
	Park();

	/** @brief Destructor.
	  */
	~Park();
	
};

#endif