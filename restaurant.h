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
	/** @brief Constructor tanpa parameter
	  * Menciptakan restaurant dengan food string kosong
	  */
	Restaurant();

	/**
	 * \brief Constructor dengan parameter
	 * \details Menciptakan restaurant dengan 
	 * \param f makanan yang dijual oleh restaurant
	 */
	Restaurant(string f);

	/**
	 * \brief CopyConstructor
	 * \details Menjamin tidak mengcopy
 	 * \param r restaurant yang akan dicopy
	 */	
	Restaurant(Restaurant& r);

	/** @brief Destructor.
	  */
	~Restaurant();

	/**
	 * \brief Interact
	 * \details Memunculkan dialog tentang makanan apa yang dijual suatu restaurant
	 */
	void Interact();
	
private:
	string food;	
};

#endif