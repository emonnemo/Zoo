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
	  * Menciptakan restaurant dengan food string kosong dan restaurant tutup
	  */
	Restaurant();

	/**
	 * \brief Constructor dengan parameter
	 * \details Menciptakan restaurant dengan 
	 * \param f makanan yang dijual oleh restaurant
	 * \param o true jika restaurant buka
	 */
	Restaurant(string f, bool o);

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
	 * \details Memunculkan dialog tentang makanan apa yang dijual suatu restaurant jika restaurant buka, jika tidak katakan restaurant tutup
	 */
	void Interact();

private:
	string food;
	bool open;	
};

#endif