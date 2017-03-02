/* Author		: Andika Kusuma / 13515033
 * File			: cell.h
 */

#ifndef CELL_H
#define CELL_H

#include <iostream>

using namespace std;
/** @class Cell
  * Kelas abstrak cell
  */
class Cell{
	public	:
		/** @brief Constructor.
		  * Menciptakan cell dengan letak (x,y)
		  * @param x nilai posisi x yang diinginkan
		  * @param y nilai posisi y yang diinginkan
		  */
		Cell();

		/** @brief Destructor.
		  */
		~Cell();
		/**
		 * \brief GetSymbol
		 * \details mengembalikan nilai simbol cell
		 * \return symbol
		 */
		virtual char GetSymbol() const;
	private :
		char symbol;
};

#endif
