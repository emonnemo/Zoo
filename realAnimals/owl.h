//File owl.h

#ifndef OWL_H
#define OWL_H

#include "../animal.h"
#include <iostream>
#include <set>
using namespace std;

/**
 * \class Owl
 * \details real class dari animal, yaitu burung hantu
 */
class Owl: public Animal {
public:
  /**
   * \brief Constructor default weight
   * \details Menciptakan objek burung hantu dengan default weight untuk burung hantu 
   * 
   * \param _weight berat badan
   * \param _position posisi burung hantu
   */
  Owl(pair<int,int> _position);
  /**
   * \brief Constructor dengan weight
   * \details Menciptakan objek burung hantu dengan weight sebagai parameter
   * 
   * \param _weight berat badan
   * \param _position posisi burung hantu
   */
  Owl(float _weight, pair<int,int> _position);
  /**
   * \brief Destructor
   */
  ~Owl();
  /**
   * \brief Copy Constructor
   * \details copy constructor, menjamin tidak bitwise copy
   * 
   * \param o Owl yang ingin dikopi
   */
  Owl(const Owl& o);
  /**
   * \brief Operator =
   * \details operator=, menjamin tidak bitwise copy
   * 
   * \param o Owl yang ingin dikopi
   * \return Owl yang sama dengan o
   */
  Owl& operator= (const Owl& o);
  /**
   * \brief Act
   * \details Owl's behaviour
   */
  void Act() const;
  /**
   * \brief Interact
   * \details mengoutput hasil interaksi dengan Owl
   */
  void Interact() const;
private:
  static int owl_nb;
  const float food = 0.3;
};

#endif
