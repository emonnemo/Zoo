//File macaque.h

#ifndef MACAQUE_H
#define MACAQUE_H

#include "../animal.h"
#include <iostream>
#include <set>
using namespace std;

/**
 * \class Macaque
 * \details real class dari animal, yaitu monyet
 */
class Macaque: public Animal {
public:
  /**
   * \brief Constructor default weight
   * \details Menciptakan objek monyet dengan default weight untuk monyet 
   * 
   * \param _weight berat badan
   * \param _position posisi monyet
   */
  Macaque(pair<int,int> _position);
  /**
   * \brief Constructor dengan weight
   * \details Menciptakan objek monyet dengan weight sebagai parameter
   * 
   * \param _weight berat badan
   * \param _position posisi monyet
   */
  Macaque(float _weight, pair<int,int> _position);
  /**
   * \brief Destructor
   */
  ~Macaque();
  /**
   * \brief Copy Constructor
   * \details copy constructor, menjamin tidak bitwise copy
   * 
   * \param m Macaque yang ingin dikopi
   */
  Macaque(const Macaque& m);
  /**
   * \brief Operator =
   * \details operator=, menjamin tidak bitwise copy
   * 
   * \param m Macaque yang ingin dikopi
   * \return Macaque yang sama dengan m
   */
  Macaque& operator= (const Macaque& m);
  /**
   * \brief Act
   * \details Macaque's behaviour
   */
  void Act() const;
  /**
   * \brief Interact
   * \details mengoutput hasil interaksi dengan Macaque
   */
  void Interact() const;
private:
  static int macaque_nb;
  const float food = 0.2;
};

#endif
