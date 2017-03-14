/* Author    : Andika Kusuma / 13515033
 * File      : facility.h
 */

#ifndef FACILITY_H
#define FACILITY_H

#include <iostream>
#include "cell.h"

using namespace std;
/** \brief Class Facility
  * \details Kelas abstrak facility turunan dari kelas cell berupa restoran, road, atau park
  */
class Facility: public Cell {
public:
    /**
     * \brief Constructor tanpa parameter.
     * \details Menciptakan facility dengan symbol c.
     */
    Facility();

    /**
     * \brief Destructor.
     */
    ~Facility();

    /**
     * \brief Interact
     * \details Menampilkan interaksi facility;
     * tidak diimplementasi pada class ini
     */
    virtual void Interact() const = 0;

    /**
     * \brief ToggleSekat
     * \details Memasang atau menghilangkan sekat antar-Cell;
     * tidak diimplementasi pada class ini
     * 
     * \param direction arah yang ingin dibuka
     */
    virtual void ToggleSekat(int direction) = 0;
    
    /**
     * \brief GetSekat
     * \details Mengecek apakah ke arah direction terdapat sekat;
     * tidak diimplementasi pada class ini
     * 
     * \param direction arah yang ingin dicek
     */
    virtual bool GetSekat(int direction) const = 0;
};

#endif
