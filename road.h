/* Author		: Andika Kusuma / 13515033
 * File			: road.h
 */

#ifndef ROAD_H
#define ROAD_H

#include <iostream>
#include "facility.h"

using namespace std;
/** \class Road
  * \details Kelas road turunan dari kelas facility berupa jalanan di zoo
  */
class Road : public Facility{
public :
	/** \brief Constructor.
	  * \details Menciptakan road dengan posisi (x,y)
	  * \param x nilai posisi x yang diinginkan
	  * \param x nilai posisi y yang diinginkan
	  */
	Road();

	/** \brief Destructor.
	  */
	~Road();
private :
};

#endif