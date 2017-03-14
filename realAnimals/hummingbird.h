//File hummingbird.h

#ifndef HUMMINGBIRD_H
#define HUMMINGBIRD_H

#include "../animal.h"
#include <iostream>
#include <set>
using namespace std;

/**
 * \class Hummingbird
 * \details real class dari animal, yaitu burung kiwi
 */
class Hummingbird: public Animal {
public:
  /**
   * \brief Constructor default weight
   * \details Menciptakan objek burung kiwi dengan default weight untuk burung kiwi 
   * 
   * \param _weight berat badan
   * \param _position posisi burung kiwi
   */
  Hummingbird(pair<int,int> _position);
  /**
   * \brief Constructor dengan weight
   * \details Menciptakan objek burung kiwi dengan weight sebagai parameter
   * 
   * \param _weight berat badan
   * \param _position posisi burung kiwi
   */
  Hummingbird(float _weight, pair<int,int> _position);
  /**
   * \brief Destructor
   */
  ~Hummingbird();
  /**
   * \brief Copy Constructor
   * \details copy constructor, menjamin tidak bitwise copy
   * 
   * \param h Hummingbird yang ingin dikopi
   */
  Hummingbird(const Hummingbird& h);
  /**
   * \brief Operator =
   * \details operator=, menjamin tidak bitwise copy
   * 
   * \param h Hummingbird yang ingin dikopi
   * \return Hummingbird yang sama dengan h
   */
  Hummingbird& operator=(const Hummingbird& h);
  /**
   * \brief Act
   * \details Hummingbird's behaviour
   */
  void Act() const;
  /**
   * \brief Interact
   * \details mengoutput hasil interaksi dengan Hummingbird
   */
  void Interact() const;
private:
  static int hummingbird_nb;
  const float food = 0.3;
};

#endif
