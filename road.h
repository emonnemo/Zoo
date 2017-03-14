/* Author    : Andika Kusuma / 13515033
 * File      : road.h
 */

#ifndef ROAD_H
#define ROAD_H

#include <iostream>
#include "facility.h"

using namespace std;
/** \class Road
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

  //Tidak diimplementtasi
  void ToggleSekat(int direction);
    
  //Tidak diimplementasi
  bool GetSekat(int direction) const;
};

#endif
