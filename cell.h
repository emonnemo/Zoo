/* Author		: Andika Kusuma / 13515033
 * File			: cell.h
 */

#ifndef CELL_H
#define CELL_H

#include <iostream>

using namespace std;
/** \class Cell.
  * Kelas abstrak cell.
  */
class Cell{
	public	:
		/** \brief Constructor.
		  * Menciptakan cell dengan symbol "-".
		  */
		Cell();

		/**
		 * \brief Constructor dengan parameter.
		 * \details Menciptakan cell dengan symbol "c".
		 * \param c symbol input.
		 */
		Cell(char c);

		/**
		 * \brief Copy Constructor.
		 * \details copy constructor menjamin tidak bitwise copy.
		 * \param c cell yang ingin dicopy.
		 */
		Cell(const Cell& c);

		/**
		 * \brief destructor.
		 */
		~Cell();
		
		/**
		 * \brief Operator =.
		 * \details operator = menjamin tidak bitwise copy.
		 * \param c cell yang ingin dicopy.
		 */
		Cell& operator=(const Cell& c);

		/**
		 * \brief Operator <<.
		 * \details mengoutput symbol Cell.
		 * \param os output stream.
		 * \param c Cell yang ingin dioutput. 
		 */
		friend ostream& operator<< (ostream& os, const Cell& c);

		/**
		 * \brief GetSymbol.
		 * \details mengembalikan nilai simbol cell.
		 * \return symbol.
		 */
		char GetSymbol() const;

		/**
		 * \brief SetInitSymbol
		 * \details mengubah initsymbol dengan is
		 * \param is initial symbol baru
		 */
		void SetInitSymbol(char is);

		/**
		 * \brief SetSymbol
		 * \details mengubah symbol dengan s
		 * \param s symbol yang baru
		 */
		void SetSymbol(char s);
	private :
		char initsymbol;
		char symbol;
};

#endif
