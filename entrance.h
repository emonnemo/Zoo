/* Author		: Andika Kusuma / 13515033
 * File			: entrance.h
 */

#ifndef ENTRANCE_H
#define ENTRANCE_H

#include <iostream>
#include "road.h"

using namespace std;
/** @class Entrance
  * Kelas entrance turunan dari kelas road yang merupakan pintu masuk ke zoo
  */
class Entrance : public Road{
	/** @brief Constructor.
	  * Menciptakan Entrance dengan posisi (x,y)
	  * @param x nilai posisi x yang diinginkan
	  * @param x nilai posisi y yang diinginkan
	  */
	Entrance(int x, int y);

	/** @brief Destructor.
	  */
	~Entrance();
	
};

#endif