//	fila	: habitat.h

#ifndef HABITAT_H
#define HABITAT_H

#include <iostream>
#include "../cell/cell.h"
using namespace std;

/** 
 * \brief Class Habitat
 * \details real class dari habitat dalam zoo
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
   * \brief ToggleSekat
   * \details Membuka sekat dengan arah sesuai direction jika sedang tertutup. Menutup sekat jika sedang terbuka
   * I.S Sekat yang dibuka selalu valid (tidak membuka sekat ke luar cage)
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
  
  /**
   * \brief Interact
   * \details Interaksi dengan Animal; tidak diimplementasi
   */
  void Interact() const;

private:
  bool sekat[4]; /**< state dari sekat; true untuk terbuka, false untuk tertutup */
};

#endif
