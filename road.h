/* Author		: Andika Kusuma / 13515033
 * File			: road.h
 */

#ifndef ROAD_H
#define ROAD_H

#include <iostream>
#include "facility.h"

using namespace std;
/** @class Road
  * Kelas road turunan dari kelas facility berupa jalanan di zoo
  */
class Road : public Facility{
	/** @brief Constructor.
	  * Menciptakan road dengan posisi (x,y)
	  * @param x nilai posisi x yang diinginkan
	  * @param x nilai posisi y yang diinginkan
	  */
	Road(int x, int y);

	/** @brief Destructor.
	  */
	~Road();
	
};

#endif