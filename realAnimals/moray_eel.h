//File moray_eel.h

#ifndef Moray_EEL_H
#define Moray_EEL_H

#include "../animal.h"
#include <iostream>
#include <set>
using namespace std;

/**
 * \class Moray_Eel
 * \details real class dari animal, yaitu belut
 */
class Moray_Eel: public Animal {
public:
  /**
   * \brief Constructor default weight
   * \details Menciptakan objek belut dengan default weight untuk belut 
   * 
   * \param _weight berat badan
   * \param _position posisi belut
   */
  Moray_Eel(pair<int,int> _position);
  /**
   * \brief Constructor dengan weight
   * \details Menciptakan objek belut dengan weight sebagai parameter
   * 
   * \param _weight berat badan
   * \param _position posisi belut
   */
  Moray_Eel(float _weight, pair<int,int> _position);
  /**
   * \brief Destructor
   */
  ~Moray_Eel();
  /**
   * \brief Copy Constructor
   * \details copy constructor, menjamin tidak bitwise copy
   * 
   * \param w Moray_Eel yang ingin dikopi
   */
  Moray_Eel(const Moray_Eel& w);
  /**
   * \brief Operator =
   * \details operator=, menjamin tidak bitwise copy
   * 
   * \param w Moray_Eel yang ingin dikopi
   * \return Moray_Eel yang sama dengan w
   */
  Moray_Eel& operator= (const Moray_Eel& w);
  /**
   * \brief Act
   * \details Moray_Eel's behaviour
   */
  void Act() const;
  /**
   * \brief Interact
   * \details mengoutput hasil interaksi dengan Moray_Eel
   */
  void Interact() const;
private:
  static int morayEelNB;
  const float food = 0.2;
};

#endif
