//File turtle.h

#ifndef TURTLE_H
#define TURTLE_H

#include "../animal.h"
#include <iostream>
#include <set>
using namespace std;

/**
 * \class Turtle
 * \details real class dari animal, yaitu kura-kura
 */
class Turtle: public Animal {
public:
  /**
   * \brief Constructor default weight
   * \details Menciptakan objek kura-kura dengan default weight untuk kura-kura 
   * 
   * \param _weight berat badan
   * \param _position posisi kura-kura
   */
  Turtle(pair<int,int> _position);
  /**
   * \brief Constructor dengan weight
   * \details Menciptakan objek kura-kura dengan weight sebagai parameter
   * 
   * \param _weight berat badan
   * \param _position posisi kura-kura
   */
  Turtle(float _weight, pair<int,int> _position);
  /**
   * \brief Destructor
   */
  ~Turtle();
  /**
   * \brief Copy Constructor
   * \details copy constructor, menjamin tidak bitwise copy
   * 
   * \param t Turtle yang ingin dikopi
   */
  Turtle(const Turtle& t);
  /**
   * \brief Operator =
   * \details operator=, menjamin tidak bitwise copy
   * 
   * \param t Turtle yang ingin dikopi
   * \return Turtle yang sama dengan t
   */
  Turtle& operator=(const Turtle& t);
  /**
   * \brief Act
   * \details Turtle's behaviour
   */
  void Act() const;
  /**
   * \brief Interact
   * \details mengoutput hasil interaksi dengan Turtle
   */
  void Interact() const;
private:
  static int turtle_nb;
  const float food = 0.05;
};

#endif
