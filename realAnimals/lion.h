//File lion.h

#ifndef LION_H
#define LION_H

#include "../animal.h"
#include <iostream>
#include <set>
using namespace std;

/**
 * \class Lion
 * \details real class dari animal, yaitu singa
 */
class Lion: public Animal {
public:
  /**
   * \brief Constructor default weight
   * \details Menciptakan objek singa dengan default weight untuk singa 
   * 
   * \param _weight berat badan
   * \param _position posisi singa
   */
  Lion(pair<int,int> _position);
  /**
   * \brief Constructor dengan weight
   * \details Menciptakan objek singa dengan weight sebagai parameter
   * 
   * \param _weight berat badan
   * \param _position posisi singa
   */
  Lion(float _weight, pair<int,int> _position);
  /**
   * \brief Destructor
   */
  ~Lion();
  /**
   * \brief Copy Constructor
   * \details copy constructor, menjamin tidak bitwise copy
   * 
   * \param l Lion yang ingin dikopi
   */
  Lion(const Lion& l);
  /**
   * \brief Operator =
   * \details operator=, menjamin tidak bitwise copy
   * 
   * \param l Lion yang ingin dikopi
   * \return Lion yang sama dengan l
   */
  Lion& operator= (const Lion& l);
  /**
   * \brief Act
   * \details Lion's behaviour
   */
  void Act() const;
  /**
   * \brief Interact
   * \details mengoutput hasil interaksi dengan Lion
   */
  void Interact() const;
private:
  static int lion_nb;
  const float food = 0.5;
};

#endif
