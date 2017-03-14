//File cockatoo.h

#ifndef COCKATOO_H
#define COCKATOO_H

#include "../animal.h"
#include <iostream>
#include <set>
using namespace std;

/**
 * \class Cockatoo
 * \details real class dari animal, yaitu burung kakak tua
 */
class Cockatoo: public Animal {
public:
  /**
   * \brief Constructor default weight
   * \details Menciptakan objek burung kakak tua dengan default weight untuk burung kakak tua 
   * 
   * \param _weight berat badan
   * \param _position posisi burung kakak tua
   */
  Cockatoo(pair<int,int> _position);
  /**
   * \brief Constructor dengan weight
   * \details Menciptakan objek burung kakak tua dengan weight sebagai parameter
   * 
   * \param _weight berat badan
   * \param _position posisi burung kakak tua
   */
  Cockatoo(float _weight, pair<int,int> _position);
  /**
   * \brief Destructor
   */
  ~Cockatoo();
  /**
   * \brief Copy Constructor
   * \details copy constructor, menjamin tidak bitwise copy
   * 
   * \param c Cockatoo yang ingin dikopi
   */
  Cockatoo(const Cockatoo& c);
  /**
   * \brief Operator =
   * \details operator=, menjamin tidak bitwise copy
   * 
   * \param c Cockatoo yang ingin dikopi
   * \return Cockatoo yang sama dengan c
   */
  Cockatoo& operator= (const Cockatoo& c);
  /**
   * \brief Act
   * \details Cockatoo's behaviour
   */
  void Act() const;
  /**
   * \brief Interact
   * \details mengoutput hasil interaksi dengan Cockatoo
   */
  void Interact() const;
private:
  static int cockatoo_nb;
  const float food = 0.3;
};

#endif
