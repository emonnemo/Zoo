//File elephant.h

#ifndef ELEPHANT_H
#define ELEPHANT_H

#include "../animal.h"
#include <iostream>
#include <set>
using namespace std;

/**
 * \class Elephant
 * \details real class dari animal, yaitu gajah
 */
class Elephant: public Animal {
public:
  /**
   * \brief Constructor default weight
   * \details Menciptakan objek gajah dengan default weight untuk gajah 
   * 
   * \param _weight berat badan
   * \param _position posisi gajah
   */
  Elephant(pair<int,int> _position);
  /**
   * \brief Constructor dengan weight
   * \details Menciptakan objek gajah dengan weight sebagai parameter
   * 
   * \param _weight berat badan
   * \param _position posisi gajah
   */
  Elephant(float _weight, pair<int,int> _position);
  /**
   * \brief Destructor
   */
  ~Elephant();
  /**
   * \brief Copy Constructor
   * \details copy constructor, menjamin tidak bitwise copy
   * 
   * \param e Elephant yang ingin dikopi
   */
  Elephant(const Elephant& e);
  /**
   * \brief Operator =
   * \details operator=, menjamin tidak bitwise copy
   * 
   * \param e Elephant yang ingin dikopi
   * \return Elephant yang sama dengan e
   */
  Elephant& operator= (const Elephant& e);
  /**
   * \brief Act
   * \details Elephant's behaviour
   */
  void Act() const;
  /**
   * \brief Interact
   * \details mengoutput hasil interaksi dengan Elephant
   */
  void Interact() const;
private:
  static int elephant_nb;
  const float food = 0.7;
};

#endif
