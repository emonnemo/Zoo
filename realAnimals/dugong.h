//File dugong.h

#ifndef DUGONG_H
#define DUGONG_H

#include "../animal.h"
#include <iostream>
#include <set>
using namespace std;

/**
 * \class Dugong
 * \details real class dari animal, yaitu dugong
 */
class Dugong: public Animal {
public:
  /**
   * \brief Constructor default weight
   * \details Menciptakan objek dugong dengan default weight untuk dugong 
   * 
   * \param _weight berat badan
   * \param _position posisi dugong
   */
  Dugong(pair<int,int> _position);
  /**
   * \brief Constructor dengan weight
   * \details Menciptakan objek dugong dengan weight sebagai parameter
   * 
   * \param _weight berat badan
   * \param _position posisi dugong
   */
  Dugong(float _weight, pair<int,int> _position);
  /**
   * \brief Destructor
   */
  ~Dugong();
  /**
   * \brief Copy Constructor
   * \details copy constructor, menjamin tidak bitwise copy
   * 
   * \param d Dugong yang ingin dikopi
   */
  Dugong(const Dugong& d);
  /**
   * \brief Operator =
   * \details operator=, menjamin tidak bitwise copy
   * 
   * \param d Dugong yang ingin dikopi
   * \return Dugong yang sama dengan d
   */
  Dugong& operator=(const Dugong& d);
  /**
   * \brief Act
   * \details Dugong's behaviour
   */
  void Act() const;
  /**
   * \brief Interact
   * \details mengoutput hasil interaksi dengan Dugong
   */
  void Interact() const;
private:
  static int dugong_nb;
  const float food = 0.2;
};

#endif
