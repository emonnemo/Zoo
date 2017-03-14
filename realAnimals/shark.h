//File Shark.h

#ifndef SHARK_H
#define SHARK_H

#include "../animal.h"
#include <iostream>
#include <set>
using namespace std;

/**
 * \class Shark
 * \details real class dari animal, yaitu hiu
 */
class Shark: public Animal {
public:
  /**
   * \brief Constructor default weight
   * \details Menciptakan objek hiu dengan default weight untuk hiu 
   * 
   * \param _weight berat badan
   * \param _position posisi hiu
   */
  Shark(pair<int,int> _position);
  /**
   * \brief Constructor dengan weight
   * \details Menciptakan objek hiu dengan weight sebagai parameter
   * 
   * \param _weight berat badan
   * \param _position posisi hiu
   */
  Shark(float _weight, pair<int,int> _position);
  /**
   * \brief Destructor
   */
  ~Shark();
  /**
   * \brief Copy Constructor
   * \details copy constructor, menjamin tidak bitwise copy
   * 
   * \param s Shark yang ingin dikopi
   */
  Shark(const Shark& s);
  /**
   * \brief Operator =
   * \details operator=, menjamin tidak bitwise copy
   * 
   * \param s Shark yang ingin dikopi
   * \return Shark yang sama dengan s
   */
  Shark& operator=(const Shark& s);
  /**
   * \brief Act
   * \details Shark's behaviour
   */
  void Act() const;
  /**
   * \brief Interact
   * \details mengoutput hasil interaksi dengan Shark
   */
  void Interact() const;
private:
  static int shark_nb;
  const float food = 0.2;
};

#endif
