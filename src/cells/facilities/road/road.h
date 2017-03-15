//	file	: road.h

#ifndef ROAD_H
#define ROAD_H

#include <iostream>
#include "../facility/facility.h"

using namespace std;
/** \brief Class Road
  * \details Kelas road turunan dari kelas facility berupa jalanan di zoo
  */
class Road : public Facility {
public:
  /** \brief Constructor tanpa parameter
    * \details Menciptakan road dengan type=r (road biasa)
    */
  Road();

  /**
   * \brief Constructor dengan parameter
   * \details Menciptakan road dengan type=t
   * \param t type road (r untuk road biasa, n untuk entrance, dan x untuk exit);
   */
  Road(char t);

  /** \brief Destructor.
    */
  ~Road();

  /**
     * \brief Interact
     * \details Menampilkan interaksi road
     */
  void Interact() const;

  /**
   * \brief ToggleSekat
   * \details Memasang atau menghilangkan sekat antar-Cell;
   * tidak diimplementasi pada class ini, hanya pendukung ABC Cell dan Facility
   * 
   * \param direction arah yang ingin dibuka
   */
  void ToggleSekat(int direction);
    
  /**
   * \brief GetSekat
   * \details Mengecek apakah ke arah direction terdapat sekat;
   * tidak diimplementasi pada class ini, hanya pendukung ABC Cell dan Facility
   * 
   * \param direction arah yang ingin dicek
   */
  bool GetSekat(int direction) const;
};

#endif
