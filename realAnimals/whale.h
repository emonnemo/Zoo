//File whale.h

#ifndef WHALE_H
#define WHALE_H

#include "../animal.h"
#include <iostream>
#include <set>
using namespace std;

/**
 * \class Whale
 * \details real class dari animal, yaitu paus
 */
class Whale: public Animal {
public:
  /**
   * \brief Constructor default weight
   * \details Menciptakan objek paus dengan default weight untuk paus 
   * 
   * \param _weight berat badan
   * \param _position posisi paus
   */
  Whale(pair<int,int> _position);
  /**
   * \brief Constructor dengan weight
   * \details Menciptakan objek paus dengan weight sebagai parameter
   * 
   * \param _weight berat badan
   * \param _position posisi paus
   */
  Whale(float _weight, pair<int,int> _position);
  /**
   * \brief Destructor
   */
  ~Whale();
  /**
   * \brief Copy Constructor
   * \details copy constructor, menjamin tidak bitwise copy
   * 
   * \param w Whale yang ingin dikopi
   */
  Whale(const Whale& w);
  /**
   * \brief Operator =
   * \details operator=, menjamin tidak bitwise copy
   * 
   * \param w Whale yang ingin dikopi
   * \return Whale yang sama dengan w
   */
  Whale& operator=(const Whale& w);
  /**
   * \brief Act
   * \details Whale's behaviour
   */
  void Act() const;
  /**
   * \brief Interact
   * \details mengoutput hasil interaksi dengan Whale
   */
  void Interact() const;
private:
  static int whale_nb;
  const float food = 0.1;
};

#endif
