//File zebra.h

#ifndef ZEBRA_H
#define ZEBRA_H

#include "../animal.h"
#include <iostream>
#include <set>
using namespace std;

/**
 * \class Zebra
 * \details real class dari animal, yaitu zebra
 */
class Zebra: public Animal {
public:
  /**
   * \brief Constructor default weight
   * \details Menciptakan objek zebra dengan default weight untuk zebra 
   * 
   * \param _weight berat badan
   * \param _position posisi zebra
   */
  Zebra(pair<int,int> _position);
  /**
   * \brief Constructor dengan weight
   * \details Menciptakan objek zebra dengan weight sebagai parameter
   * 
   * \param _weight berat badan
   * \param _position posisi zebra
   */
  Zebra(float _weight, pair<int,int> _position);
  /**
   * \brief Destructor
   */
  ~Zebra();
  /**
   * \brief Copy Constructor
   * \details copy constructor, menjamin tidak bitwise copy
   * 
   * \param z Zebra yang ingin dikopi
   */
  Zebra(const Zebra& z);
  /**
   * \brief Operator =
   * \details operator=, menjamin tidak bitwise copy
   * 
   * \param z Zebra yang ingin dikopi
   * \return Zebra yang sama dengan z
   */
  Zebra& operator= (const Zebra& z);
  /**
   * \brief Act
   * \details Zebra's behaviour
   */
  void Act() const;
  /**
   * \brief Interact
   * \details mengoutput hasil interaksi dengan Zebra
   */
  void Interact() const;
private:
  static int zebra_nb;
  const float food = 0.3;
};

#endif
