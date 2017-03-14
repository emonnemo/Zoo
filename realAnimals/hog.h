//File hog.h

#ifndef HOG_H
#define HOG_H

#include "../animal.h"
#include <iostream>
#include <set>
using namespace std;

/**
 * \class Hog
 * \details real class dari animal, yaitu babi hutan
 */
class Hog: public Animal {
public:
  /**
   * \brief Constructor default weight
   * \details Menciptakan objek babi hutan dengan default weight untuk babi hutan 
   * 
   * \param _weight berat badan
   * \param _position posisi babi hutan
   */
  Hog(pair<int,int> _position);
  /**
   * \brief Constructor dengan weight
   * \details Menciptakan objek babi hutan dengan weight sebagai parameter
   * 
   * \param _weight berat badan
   * \param _position posisi babi hutan
   */
  Hog(float _weight, pair<int,int> _position);
  /**
   * \brief Destructor
   */
  ~Hog();
  /**
   * \brief Copy Constructor
   * \details copy constructor, menjamin tidak bitwise copy
   * 
   * \param h Hog yang ingin dikopi
   */
  Hog(const Hog& h);
  /**
   * \brief Operator =
   * \details operator=, menjamin tidak bitwise copy
   * 
   * \param h Hog yang ingin dikopi
   * \return Hog yang sama dengan h
   */
  Hog& operator=(const Hog& h);
  /**
   * \brief Act
   * \details Hog's behaviour
   */
  void Act() const;
  /**
   * \brief Interact
   * \details mengoutput hasil interaksi dengan Hog
   */
  void Interact() const;
private:
  static int hog_nb;
  const float food = 0.2;
};

#endif
