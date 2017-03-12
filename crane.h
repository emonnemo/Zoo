//File crane.h

#ifndef Crane_H
#define Crane_H

#include "../animal.h"
#include <iostream>
#include <set>
using namespace std;

/**
 * \class Crane
 * \details real class dari animal, yaitu Crane
 */
class Crane: public Animal {
public:
	/**
	 * \brief Constructor default weight
	 * \details Menciptakan objek Crane dengan default weight untuk Crane 
	 * 
	 * \param _weight berat badan
	 * \param _position posisi Crane
	 */
	Crane(pair<int,int> _position);
	/**
	 * \brief Constructor dengan weight
	 * \details Menciptakan objek Crane dengan weight sebagai parameter
	 * 
	 * \param _weight berat badan
	 * \param _position posisi Crane
	 */
	Crane(float _weight, pair<int,int> _position);
	/**
	 * \brief Destructor
	 */
	~Crane();
	/**
	 * \brief Copy Constructor
	 * \details copy constructor, menjamin tidak bitwise copy
	 * 
	 * \param z Crane yang ingin dikopi
	 */
	Crane(const Crane& c);
	/**
	 * \brief Operator =
	 * \details operator=, menjamin tidak bitwise copy
	 * 
	 * \param z Crane yang ingin dikopi
	 * \return Crane yang sama dengan z
	 */
	Crane& operator= (const Crane& c);
	/**
	 * \brief Act
	 * \details Crane's behaviour
	 */
	void Act() const;
	/**
	 * \brief Interact
	 * \details mengoutput hasil interaksi dengan Crane
	 */
	void Interact() const;
private:
	static int CraneNB;
	const float food = 0.3;
};

#endif