//File colugo.h

#ifndef COLUGO_H
#define COLUGO_H

#include "../animal.h"
#include <iostream>
#include <set>
using namespace std;

/**
 * \class Colugo
 * \details real class dari animal, yaitu lemur terbang Sunda
 */
class Colugo: public Animal {
public:
  /**
   * \brief Constructor default weight
   * \details Menciptakan objek lemur terbang Sunda dengan default weight untuk lemur terbang Sunda 
   * 
   * \param _weight berat badan
   * \param _position posisi lemur terbang Sunda
   */
  Colugo(pair<int,int> _position);
  /**
   * \brief Constructor dengan weight
   * \details Menciptakan objek lemur terbang Sunda dengan weight sebagai parameter
   * 
   * \param _weight berat badan
   * \param _position posisi lemur terbang Sunda
   */
  Colugo(float _weight, pair<int,int> _position);
  /**
   * \brief Destructor
   */
  ~Colugo();
  /**
   * \brief Copy Constructor
   * \details copy constructor, menjamin tidak bitwise copy
   * 
   * \param c Colugo yang ingin dikopi
   */
  Colugo(const Colugo& c);
  /**
   * \brief Operator =
   * \details operator=, menjamin tidak bitwise copy
   * 
   * \param c Colugo yang ingin dikopi
   * \return Colugo yang sama dengan c
   */
  Colugo& operator= (const Colugo& c);
  /**
   * \brief Act
   * \details Colugo's behaviour
   */
  void Act() const;
  /**
   * \brief Interact
   * \details mengoutput hasil interaksi dengan Colugo
   */
  void Interact() const;
private:
  static int colugo_nb;
  const float food = 0.25;
};

#endif
