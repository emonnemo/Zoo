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
public:
		/**
		 * \brief Constructor tanpa parameter.
		 * \details Menciptakan facility dengan symbol c.
		 */
		Facility();

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

		virtual void Interact();
};

#endif
