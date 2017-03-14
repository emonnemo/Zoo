//File bat.h

#ifndef BAT_H
#define BAT_H

#include "../animal.h"
#include <iostream>
#include <set>
using namespace std;

/**
 * \class Bat
 * \details real class dari animal, yaitu kelelawar
 */
class Bat: public Animal {
public:
  /**
   * \brief Constructor default weight
   * \details Menciptakan objek kelelawar dengan default weight untuk kelelawar 
   * 
   * \param _weight berat badan
   * \param _position posisi kelelawar
   */
  Bat(pair<int,int> _position);
  /**
   * \brief Constructor dengan weight
   * \details Menciptakan objek kelelawar dengan weight sebagai parameter
   * 
   * \param _weight berat badan
   * \param _position posisi kelelawar
   */
  Bat(float _weight, pair<int,int> _position);
  /**
   * \brief Destructor
   */
  ~Bat();
  /**
   * \brief Copy Constructor
   * \details copy constructor, menjamin tidak bitwise copy
   * 
   * \param b Bat yang ingin dikopi
   */
  Bat(const Bat& b);
  /**
   * \brief Operator =
   * \details operator=, menjamin tidak bitwise copy
   * 
   * \param b Bat yang ingin dikopi
   * \return Bat yang sama dengan b
   */
  Bat& operator=(const Bat& b);
  /**
   * \brief Act
   * \details Bat's behaviour
   */
  void Act() const;
  /**
   * \brief Interact
   * \details mengoutput hasil interaksi dengan Bat
   */
  void Interact() const;
private:
  static int bat_nb;
  const float food = 0.4;
};

#endif
