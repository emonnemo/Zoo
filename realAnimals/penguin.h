//File penguin.h

#ifndef PENGUIN_H
#define PENGUIN_H

#include "../animal.h"
#include <iostream>
#include <set>
using namespace std;

/**
 * \class Penguin
 * \details real class dari animal, yaitu penguin
 */
class Penguin: public Animal {
public:
  /**
   * \brief Constructor default weight
   * \details Menciptakan objek penguin dengan default weight untuk penguin 
   * 
   * \param _weight berat badan
   * \param _position posisi penguin
   */
  Penguin(pair<int,int> _position);
  /**
   * \brief Constructor dengan weight
   * \details Menciptakan objek penguin dengan weight sebagai parameter
   * 
   * \param _weight berat badan
   * \param _position posisi penguin
   */
  Penguin(float _weight, pair<int,int> _position);
  /**
   * \brief Destructor
   */
  ~Penguin();
  /**
   * \brief Copy Constructor
   * \details copy constructor, menjamin tidak bitwise copy
   * 
   * \param p Penguin yang ingin dikopi
   */
  Penguin(const Penguin& p);
  /**
   * \brief Operator =
   * \details operator=, menjamin tidak bitwise copy
   * 
   * \param p Penguin yang ingin dikopi
   * \return Penguin yang sama dengan p
   */
  Penguin& operator= (const Penguin& p);
  /**
   * \brief Act
   * \details Penguin's behaviour
   */
  void Act() const;
  /**
   * \brief Interact
   * \details mengoutput hasil interaksi dengan Penguin
   */
  void Interact() const;
private:
  static int penguin_nb;
  const float food = 0.25;
};

#endif
