//File pelican.h

#ifndef PELICAN_H
#define PELICAN_H

#include "../animal/animal.h"
#include <iostream>
#include <set>
using namespace std;

/**
 * \brief class Pelican
 * \details real class dari animal, yaitu Pelican
 */
class Pelican: public Animal {
public:
  /**
   * \brief Constructor default weight
   * \details Menciptakan objek Pelican dengan default weight untuk Pelican 
   * 
   * \param _position posisi Pelican
   */
  Pelican(pair<int,int> _position);
  /**
   * \brief Constructor dengan weight
   * \details Menciptakan objek Pelican dengan weight sebagai parameter
   * 
   * \param _weight berat badan
   * \param _position posisi Pelican
   */
  Pelican(float _weight, pair<int,int> _position);
  /**
   * \brief Destructor
   */
  ~Pelican();
  /**
   * \brief Copy Constructor
   * \details copy constructor, menjamin tidak bitwise copy
   * 
   * \param p Pelican yang ingin dikopi
   */
  Pelican(const Pelican& p);
  /**
   * \brief Operator =
   * \details operator=, menjamin tidak bitwise copy
   * 
   * \param p Pelican yang ingin dikopi
   * \return Pelican yang sama dengan p
   */
  Pelican& operator=(const Pelican& p);
  /**
   * \brief Act
   * \details Pelican's behaviour
   */
  void Act() const;
  /**
   * \brief Interact
   * \details mengoutput hasil interaksi dengan Pelican
   */
  void Interact() const;
private:
  static int pelican_nb; /**< jumlah Pelican yang sudah pernah terbentuk*/
  const float food = 0.3; /**< persentase makanan yang dimakan Pelican*/
};

#endif
