//File dolphin.h

#ifndef DOLPHIN_H
#define DOLPHIN_H

#include "../animal.h"
#include <iostream>
#include <set>
using namespace std;

/**
 * \class Dolphin
 * \details real class dari animal, yaitu lumba-lumba
 */
class Dolphin: public Animal {
public:
  /**
   * \brief Constructor default weight
   * \details Menciptakan objek lumba-lumba dengan default weight untuk lumba-lumba 
   * 
   * \param _weight berat badan
   * \param _position posisi lumba-lumba
   */
  Dolphin(pair<int,int> _position);
  /**
   * \brief Constructor dengan weight
   * \details Menciptakan objek lumba-lumba dengan weight sebagai parameter
   * 
   * \param _weight berat badan
   * \param _position posisi lumba-lumba
   */
  Dolphin(float _weight, pair<int,int> _position);
  /**
   * \brief Destructor
   */
  ~Dolphin();
  /**
   * \brief Copy Constructor
   * \details copy constructor, menjamin tidak bitwise copy
   * 
   * \param w Dolphin yang ingin dikopi
   */
  Dolphin(const Dolphin& w);
  /**
   * \brief Operator =
   * \details operator=, menjamin tidak bitwise copy
   * 
   * \param w Dolphin yang ingin dikopi
   * \return Dolphin yang sama dengan w
   */
  Dolphin& operator= (const Dolphin& w);
  /**
   * \brief Act
   * \details Dolphin's behaviour
   */
  void Act() const;
  /**
   * \brief Interact
   * \details mengoutput hasil interaksi dengan Dolphin
   */
  void Interact() const;
private:
  static int DolphinNB;
  const float food = 0.2;
};

#endif
