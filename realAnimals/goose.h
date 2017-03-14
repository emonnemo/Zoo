//File goose.h

#ifndef GOOSE_H
#define GOOSE_H

#include "../animal.h"
#include <iostream>
#include <set>
using namespace std;

/**
 * \class Goose
 * \details real class dari animal, yaitu Goose
 */
class Goose: public Animal {
public:
  /**
   * \brief Constructor default weight
   * \details Menciptakan objek Goose dengan default weight untuk Goose 
   * 
   * \param _weight berat badan
   * \param _position posisi Goose
   */
  Goose(pair<int,int> _position);
  /**
   * \brief Constructor dengan weight
   * \details Menciptakan objek Goose dengan weight sebagai parameter
   * 
   * \param _weight berat badan
   * \param _position posisi Goose
   */
  Goose(float _weight, pair<int,int> _position);
  /**
   * \brief Destructor
   */
  ~Goose();
  /**
   * \brief Copy Constructor
   * \details copy constructor, menjamin tidak bitwise copy
   * 
   * \param g Goose yang ingin dikopi
   */
  Goose(const Goose& g);
  /**
   * \brief Operator =
   * \details operator=, menjamin tidak bitwise copy
   * 
   * \param g Goose yang ingin dikopi
   * \return Goose yang sama dengan g
   */
  Goose& operator=(const Goose& g);
  /**
   * \brief Act
   * \details Goose's behaviour
   */
  void Act() const;
  /**
   * \brief Interact
   * \details mengoutput hasil interaksi dengan Goose
   */
  void Interact() const;
private:
  static int goose_nb;
  const float food = 0.3;
};

#endif
