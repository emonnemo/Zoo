//File sugar_glider.h

#ifndef SUGAR_GLIDER_H
#define SUGAR_GLIDER_H

#include "../animal.h"
#include <iostream>
#include <set>
using namespace std;

/**
 * \class SugarGlider
 * \details real class dari animal, yaitu sugar glider
 */
class SugarGlider: public Animal {
public:
  /**
   * \brief Constructor default weight
   * \details Menciptakan objek sugar glider dengan default weight untuk sugar glider 
   * 
   * \param _weight berat badan
   * \param _position posisi sugar glider
   */
  SugarGlider(pair<int,int> _position);
  /**
   * \brief Constructor dengan weight
   * \details Menciptakan objek sugar glider dengan weight sebagai parameter
   * 
   * \param _weight berat badan
   * \param _position posisi sugar glider
   */
  SugarGlider(float _weight, pair<int,int> _position);
  /**
   * \brief Destructor
   */
  ~SugarGlider();
  /**
   * \brief Copy Constructor
   * \details copy constructor, menjamin tidak bitwise copy
   * 
   * \param s SugarGlider yang ingin dikopi
   */
  SugarGlider(const SugarGlider& s);
  /**
   * \brief Operator =
   * \details operator=, menjamin tidak bitwise copy
   * 
   * \param s SugarGlider yang ingin dikopi
   * \return SugarGlider yang sama dengan s
   */
  SugarGlider& operator=(const SugarGlider& s);
  /**
   * \brief Act
   * \details SugarGlider's behaviour
   */
  void Act() const;
  /**
   * \brief Interact
   * \details mengoutput hasil interaksi dengan SugarGlider
   */
  void Interact() const;
private:
  static int sugar_glider_nb;
  const float food = 0.5;
};

#endif
