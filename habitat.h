/* Author    : Gisela Supardi / 13515009
 * File      : habitat.h
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
   * \brief OpenSekat
   * \details Membuka sekat dengan arah sesuai direction jika sedang tertutup. Menutup sekat jika sedang terbuka
   * \details I.S Sekat yang dibuka selalu valid (tidak membuka sekat ke luar cage)
   * \param direction 0 untuk atas, 1 untuk kiri, 2 untuk kanan, 3 untuk bawah
   */
  void ToggleSekat(int direction);

  /**
   * \brief GetSekat
   * \details Mengembalikan kondisi sekat ke arah direction
   * \param direction 0 u ntuk ke atas, 1 untuk ke kiri, 2 untuk ke kanan, 3 untuk ke bawah
   * \return bool true jika terbuka, false jika tertutup
   */
  bool GetSekat(int direction) const;
  
  //Tidak diimplementasi
  void Interact() const;

protected:
  bool sekat[4];
};

#endif
