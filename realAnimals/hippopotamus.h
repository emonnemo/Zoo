//File hippopotamus.h

#ifndef HIPPOPOTAMUS_H
#define HIPPOPOTAMUS_H

#include "../animal.h"
#include <iostream>
#include <set>
using namespace std;

/**
 * \class Hippopotamus
 * \details real class dari animal, yaitu kuda nil
 */
class Hippopotamus: public Animal {
public:
  /**
   * \brief Constructor default weight
   * \details Menciptakan objek kuda nil dengan default weight untuk kuda nil 
   * 
   * \param _weight berat badan
   * \param _position posisi kuda nil
   */
  Hippopotamus(pair<int,int> _position);
  /**
   * \brief Constructor dengan weight
   * \details Menciptakan objek kuda nil dengan weight sebagai parameter
   * 
   * \param _weight berat badan
   * \param _position posisi kuda nil
   */
  Hippopotamus(float _weight, pair<int,int> _position);
  /**
   * \brief Destructor
   */
  ~Hippopotamus();
  /**
   * \brief Copy Constructor
   * \details copy constructor, menjamin tidak bitwise copy
   * 
   * \param h Hippopotamus yang ingin dikopi
   */
  Hippopotamus(const Hippopotamus& h);
  /**
   * \brief Operator =
   * \details operator=, menjamin tidak bitwise copy
   * 
   * \param h Hippopotamus yang ingin dikopi
   * \return Hippopotamus yang sama dengan h
   */
  Hippopotamus& operator= (const Hippopotamus& h);
  /**
   * \brief Act
   * \details Hippopotamus's behaviour
   */
  void Act() const;
  /**
   * \brief Interact
   * \details mengoutput hasil interaksi dengan Hippopotamus
   */
  void Interact() const;
private:
  static int hippopotamus_nb;
  const float food = 0.65;
};

#endif
