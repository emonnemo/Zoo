/* Author    : Andika Kusuma / 13515033
 * File      : facility.h
 */

#ifndef FACILITY_H
#define FACILITY_H

#include <iostream>
#include "cell.h"

using namespace std;
/** \class Facility
  * \details Kelas abstrak facility turunan dari kelas cell berupa restoran, road, atau park
  */
class Facility : public Cell {
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
     * \details Menampilkan interaksi facility
     */
    virtual void Interact() const = 0;

    /**
     * \brief ToggleSekat
     * \details Memasang atau menghilangkan sekat antar-Cell;
     * tidak diimplementasi
     * 
     * \param direction arah yang ingin dibuka
     */
    virtual void ToggleSekat(int direction) = 0;
    
     /**
     * \brief GetSekat
     * \details Mengecek apakah ke arah direction terdapat sekat;
     * tidak diimplementasi
     * 
     * \param direction arah yang ingin dicek
     * \return true jika ada sekat, false jika tidak
     */
    virtual bool GetSekat(int direction) const = 0;
};

#endif
