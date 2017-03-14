//File wolf.h

#ifndef WOLF_H
#define WOLF_H

#include "../animal.h"
#include <iostream>
#include <set>
using namespace std;

/**
 * \class Wolf
 * \details real class dari animal, yaitu serigala
 */
class Wolf: public Animal {
public:
  /**
   * \brief Constructor default weight
   * \details Menciptakan objek serigala dengan default weight untuk serigala 
   * 
   * \param _weight berat badan
   * \param _position posisi serigala
   */
  Wolf(pair<int,int> _position);
  /**
   * \brief Constructor dengan weight
   * \details Menciptakan objek serigala dengan weight sebagai parameter
   * 
   * \param _weight berat badan
   * \param _position posisi serigala
   */
  Wolf(float _weight, pair<int,int> _position);
  /**
   * \brief Destructor
   */
  ~Wolf();
  /**
   * \brief Copy Constructor
   * \details copy constructor, menjamin tidak bitwise copy
   * 
   * \param w Wolf yang ingin dikopi
   */
  Wolf(const Wolf& w);
  /**
   * \brief Operator =
   * \details operator=, menjamin tidak bitwise copy
   * 
   * \param w Wolf yang ingin dikopi
   * \return Wolf yang sama dengan w
   */
  Wolf& operator=(const Wolf& w);
  /**
   * \brief Act
   * \details Wolf's behaviour
   */
  void Act() const;
  /**
   * \brief Interact
   * \details mengoutput hasil interaksi dengan Wolf
   */
  void Interact() const;
private:
  static int wolf_nb;
  const float food = 0.2;
};

#endif
