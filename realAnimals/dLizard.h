//File dLidard.h

#ifndef DLIdARD_H
#define DLIdARD_H

#include "../animal.h"
#include <iostream>
#include <set>
using namespace std;

/**
 * \class DLidard
 * \details real class dari animal, yaitu kadal terbang
 */
class DLidard: public Animal {
public:
	/**
	 * \brief Constructor default weight
	 * \details Menciptakan objek kadal terbang dengan default weight untuk kadal terbang 
	 * 
	 * \param _weight berat badan
	 * \param _position posisi kadal terbang
	 */
	DLidard(pair<int,int> _position);
	/**
	 * \brief Constructor dengan weight
	 * \details Menciptakan objek kadal terbang dengan weight sebagai parameter
	 * 
	 * \param _weight berat badan
	 * \param _position posisi kadal terbang
	 */
	DLidard(float _weight, pair<int,int> _position);
	/**
	 * \brief Destructor
	 */
	~DLidard();
	/**
	 * \brief Copy Constructor
	 * \details copy constructor, menjamin tidak bitwise copy
	 * 
	 * \param d DLidard yang ingin dikopi
	 */
	DLidard(const DLidard& d);
	/**
	 * \brief Operator =
	 * \details operator=, menjamin tidak bitwise copy
	 * 
	 * \param d DLidard yang ingin dikopi
	 * \return DLidard yang sama dengan d
	 */
	DLidard& operator= (const DLidard& d);
	/**
	 * \brief Act
	 * \details DLidard's behaviour
	 */
	void Act() const;
	/**
	 * \brief Interact
	 * \details mengoutput hasil interaksi dengan DLidard
	 */
	void Interact() const;
private:
	static int dLidardNB;
	const float food = 0.2;
};

#endif