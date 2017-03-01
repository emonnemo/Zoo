#ifndef CELL_H
#define CELL_H

#include <iostream>

using namespace std;
/** @class Cell
  * Kelas abstrak cell
  */
class Cell{
	/** @brief Constructor.
	  * Menciptakan cell dengan letak (x,y)
	  * @param x nilai posisi x yang diinginkan
	  * @param y nilai posisi y yang diinginkan
	  */
	Cell(int x, int y);

	/** @brief Destructor.
	  */
	~Cell();
};

#endif
