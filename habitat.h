/* Author		: Gisela Supardi / 13515009
 * File			: habitat.h
 */

#ifndef HABITAT_H
#define HABITAT_H

#include <iostream>
#include "cell.h"
using namespace std;

/** 
 * \brief Class Habitat
 * \details abstract class dari habitat dalam zoo
 */
class Habitat: public Cell {
public:
	/**
	 * \brief Constructor
	 * \details Menciptakan habitat dengan letak (x,y)
	 * 
	 * \param s simbol pembeda sel yang diinginkan
	 */
	Habitat(char s);
	/**
	 * \brief Destructor
	 * \details Mengembalikan memori kepada sistem
	 */
	~Habitat();
	/**
	 * \brief Copy Constructor
	 * \details copy constructor menjamin tidak bitwise copy.
	 * 
	 * \param h habitat yang ingin dikopi
	 */
	Habitat(const Habitat& h);
	/**
	 * \brief Operator =
	 * \details operator = menjamin tidak bitwise copy.
	 * 
	 * \param h habitat yang ingin di-copy
	 * \return habitat yang sama dengan h
	 */
	Habitat& operator= (const Habitat& h);
};

#endif
