//File eagle.h

#ifndef EAGLE_H
#define EAGLE_H

#include "../animal.h"
#include <iostream>
#include <set>
using namespace std;

/**
 * \class Eagle
 * \details real class dari animal, yaitu elang
 */
class Eagle: public Animal {
public:
  /**
   * \brief Constructor default weight
   * \details Menciptakan objek elang dengan default weight untuk elang 
   * 
   * \param _weight berat badan
   * \param _position posisi elang
   */
  Eagle(pair<int,int> _position);
  /**
   * \brief Constructor dengan weight
   * \details Menciptakan objek elang dengan weight sebagai parameter
   * 
   * \param _weight berat badan
   * \param _position posisi elang
   */
  Eagle(float _weight, pair<int,int> _position);
  /**
   * \brief Destructor
   */
  ~Eagle();
  /**
   * \brief Copy Constructor
   * \details copy constructor, menjamin tidak bitwise copy
   * 
   * \param e Eagle yang ingin dikopi
   */
  Eagle(const Eagle& e);
  /**
   * \brief Operator =
   * \details operator=, menjamin tidak bitwise copy
   * 
   * \param e Eagle yang ingin dikopi
   * \return Eagle yang sama dengan e
   */
  Eagle& operator=(const Eagle& e);
  /**
   * \brief Act
   * \details Eagle's behaviour
   */
  void Act() const;
  /**
   * \brief Interact
   * \details mengoutput hasil interaksi dengan Eagle
   */
  void Interact() const;
private:
  static int eagle_nb;
  const float food = 0.7;
};

#endif
