/* Author    : Andika Kusuma / 13515033
 * File      : cell.h
 */

#ifndef CELL_H
#define CELL_H

#include "../renderable/renderable.h"
#include <iostream>

using namespace std;
/** \brief Class Cell.
  * \details Kelas abstrak cell.
  */
class Cell: public Renderable {
  public  :
    /** \brief Constructor.
      * \details Menciptakan cell dengan symbol "-".
      */
    Cell();

    /**
     * \brief Constructor dengan parameter.
     * \details Menciptakan cell dengan symbol c.
     * \param c symbol input.
     */
    Cell(char c);

    /**
     * \brief destructor.
     */
    virtual ~Cell();

    /**
     * \brief GetInitSymbol.
     * \details membalikan nilai initsymbol cell.
     * \return init symbol.
     */
    char GetInitSymbol() const;

    /**
     * \brief GetSymbol.
     * \details mengembalikan nilai simbol cell.
     * \return symbol.
     */
    char GetSymbol() const;

    /**
     * \brief SetSymbol.
     * \details mengubah symbol dengan s.
     * \param s symbol yang baru.
     */
    void SetSymbol(char s);

    /**
     * \brief Render
     * \details Menampilkan representasi cell pada layar
     */
    void Render();

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

    /**
     * \brief Interact
     * \details Interaksi dengan Cell; tidak diimplementasi pada class ini
     */
    virtual void Interact() const = 0;

  protected:
    char initsymbol; /**< simbol asli untuk sel dengan jenis tertentu*/
    char symbol; /**< simbol yang akan ditampilkan pada layar (dapat dioverwrite animal)*/
};

#endif
