//File moray_eel.h

#ifndef MORAY_EEL_H
#define MORAY_EEL_H

#include "../animal.h"
#include <iostream>
#include <set>
using namespace std;

/**
 * \class MorayEel
 * \details real class dari animal, yaitu belut
 */
class MorayEel: public Animal {
public:
  /**
   * \brief Constructor default weight
   * \details Menciptakan objek belut dengan default weight untuk belut 
   * 
   * \param _weight berat badan
   * \param _position posisi belut
   */
  MorayEel(pair<int,int> _position);
  /**
   * \brief Constructor dengan weight
   * \details Menciptakan objek belut dengan weight sebagai parameter
   * 
   * \param _weight berat badan
   * \param _position posisi belut
   */
  MorayEel(float _weight, pair<int,int> _position);
  /**
   * \brief Destructor
   */
  ~MorayEel();
  /**
   * \brief Copy Constructor
   * \details copy constructor, menjamin tidak bitwise copy
   * 
   * \param m MorayEel yang ingin dikopi
   */
  MorayEel(const MorayEel& m);
  /**
   * \brief Operator =
   * \details operator=, menjamin tidak bitwise copy
   * 
   * \param m MorayEel yang ingin dikopi
   * \return MorayEel yang sama dengan m
   */
  MorayEel& operator=(const MorayEel& m);
  /**
   * \brief Act
   * \details MorayEel's behaviour
   */
  void Act() const;
  /**
   * \brief Interact
   * \details mengoutput hasil interaksi dengan MorayEel
   */
  void Interact() const;
private:
  static int moray_eel_nb;
  const float food = 0.2;
};

#endif
