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

/** @class Exit
  * Kelas exit turunan dari kelas road yang merupakan pintu keluar di zoo
  */
class Exit : public Road{
	/** @brief Constructor.
	  * Menciptakan exit dengan posisi (x,y)
	  * @param x nilai posisi x yang diinginkan
	  * @param x nilai posisi y yang diinginkan
	  */
	Exit(int x, int y);

	/** @brief Destructor.
	  */
	~Exit();
	
};

/** @class Restaurant
  * Kelas restaurant turunan dari kelas facility berupa restoran di zoo
  */
class Restaurant : public Facility{
	/** @brief Constructor.
	  * Menciptakan restaurant dengan posisi (x,y)
	  * @param x nilai posisi x yang diinginkan
	  * @param x nilai posisi y yang diinginkan
	  */
	Restaurant(int x, int y);

	/** @brief Destructor.
	  */
	~Restaurant();
	
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
