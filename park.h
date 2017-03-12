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
	/** @brief Constructor tanpa parameter
	  * Menciptakan park yang berisi plant string kosong
	  */
	Park();

	/**
	 * \brief Constructor dengan parameter
	 * \details Mencipatakan park yang berisi plant p
	 * \param p tanaman yang ditanam di park
	 */
	Park(string p);

	/** @brief Destructor.
	  */
	~Park();

	/**
	 * \brief Interact
	 * \details Menunjukkan tanaman apa yang ditanam di taman tersebut
	 */
	void Interact() const;

	//Tidak diimplementtasi
	void ToggleSekat(int direction);
		
	//Tidak diimplementasi
	bool GetSekat(int direction);

private:
	string plant;
};

#endif