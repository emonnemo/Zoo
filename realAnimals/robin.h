//File robin.h

#ifndef ROBIN_H
#define ROBIN_H

#include "../animal.h"
#include <iostream>
#include <set>
using namespace std;

/**
 * \class Robin
 * \details real class dari animal, yaitu burung robin
 */
class Robin: public Animal {
public:
  /**
   * \brief Constructor default weight
   * \details Menciptakan objek burung robin dengan default weight untuk burung robin 
   * 
   * \param _weight berat badan
   * \param _position posisi burung robin
   */
  Robin(pair<int,int> _position);
  /**
   * \brief Constructor dengan weight
   * \details Menciptakan objek burung robin dengan weight sebagai parameter
   * 
   * \param _weight berat badan
   * \param _position posisi burung robin
   */
  Robin(float _weight, pair<int,int> _position);
  /**
   * \brief Destructor
   */
  ~Robin();
  /**
   * \brief Copy Constructor
   * \details copy constructor, menjamin tidak bitwise copy
   * 
   * \param r Robin yang ingin dikopi
   */
  Robin(const Robin& r);
  /**
   * \brief Operator =
   * \details operator=, menjamin tidak bitwise copy
   * 
   * \param r Robin yang ingin dikopi
   * \return Robin yang sama dengan r
   */
  Robin& operator= (const Robin& r);
  /**
   * \brief Act
   * \details Robin's behaviour
   */
  void Act() const;
  /**
   * \brief Interact
   * \details mengoutput hasil interaksi dengan Robin
   */
  void Interact() const;
private:
  static int robin_nb;
  const float food = 0.3;
};

#endif
