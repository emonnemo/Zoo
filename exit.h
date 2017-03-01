/* Author		: Andika Kusuma / 13515033
 * File			: exit.h
 */

#ifndef EXIT_H
#define EXIT_H

#include <iostream>
#include "road.h"

using namespace std;
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

#endif