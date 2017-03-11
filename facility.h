/* Author		: Andika Kusuma / 13515033
 * File			: facility.h
 */

#ifndef FACILITY_H
#define FACILITY_H

#include <iostream>
#include "cell.h"

using namespace std;
/** \class Facility
  * Kelas abstrak facility turunan dari kelas cell berupa restoran, road, atau park
  */
class Facility : public Cell{
		/**
		 * \brief Constructor tanpa parameter.
		 * \details Menciptakan facility dengan symbol c.
		 */
		Facility();

		/** \brief Constructor dengan parameter.
		  * \details Menciptakan facility dengan symbol c.
		  * \param c symbol facility.
		  */
		Facility(char c);

		/**
		 * \brief Copy Constructor.
		 * \details Copy constructor menjamin tidak bitwise copy.
		 * \param f facility yang ingin dicopy.
		 */
		Facility(const Facility& f);

		/**
		 * \brief destructor.
		 */
		~Facility();
		
		/**
		 * \brief Operator =.
		 * \details operator = menjamin tidak bitwise copy.
		 * \param f Facility yang ingin dicopy.
		 */
		Facility& operator= (const Facility& f);

		/**
		 * \brief Operator <<.
		 * \details mengoutput symbol facility.
		 * \param os output stream.
		 * \param f facility yang ingin dioutput.
		 */
		friend ostream& operator<< (ostream& os, const Facility& f);
};

#endif
