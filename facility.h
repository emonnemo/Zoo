/* Author    : Andika Kusuma / 13515033
 * File      : facility.h
 */

#ifndef FACILITY_H
#define FACILITY_H

#include <iostream>
#include "cell.h"

using namespace std;
/** \class Facility
  * Kelas abstrak facility turunan dari kelas cell berupa restoran, road, atau park
  */
class Facility : public Cell {
public:
    /**
     * \brief Constructor tanpa parameter.
     * \details Menciptakan facility dengan symbol c.
     */
    Facility();

    /**
     * \brief destructor.
     */
    ~Facility();

    /**
     * \brief Interact
     * \details Menampilkan interaksi facility
     */
    virtual void Interact() const = 0;

    //Tidak diimplementtasi
    virtual void ToggleSekat(int direction) = 0;
    
    //Tidak diimplementasi
    virtual bool GetSekat(int direction) const = 0;
};

#endif
