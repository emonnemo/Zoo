//File dLizard.h

#ifndef DLIZARD_H
#define DLIZARD_H

#include "../animal.h"
#include <iostream>
#include <set>
using namespace std;

/**
 * \class DLizard
 * \details real class dari animal, yaitu kadal terbang
 */
class DLizard: public Animal {
public:
	/**
	 * \brief Constructor default weight
	 * \details Menciptakan objek kadal terbang dengan default weight untuk kadal terbang 
	 * 
	 * \param _weight berat badan
	 * \param _position posisi kadal terbang
	 */
	DLizard(pair<int,int> _position);
	/**
	 * \brief Constructor dengan weight
	 * \details Menciptakan objek kadal terbang dengan weight sebagai parameter
	 * 
	 * \param _weight berat badan
	 * \param _position posisi kadal terbang
	 */
	DLizard(float _weight, pair<int,int> _position);
	/**
	 * \brief Destructor
	 */
	~DLizard();
	/**
	 * \brief Copy Constructor
	 * \details copy constructor, menjamin tidak bitwise copy
	 * 
	 * \param d DLizard yang ingin dikopi
	 */
	DLizard(const DLizard& d);
	/**
	 * \brief Operator =
	 * \details operator=, menjamin tidak bitwise copy
	 * 
	 * \param d DLizard yang ingin dikopi
	 * \return DLizard yang sama dengan d
	 */
	DLizard& operator= (const DLizard& d);
	/**
	 * \brief Act
	 * \details DLizard's behaviour
	 */
	void Act() const;
	/**
	 * \brief Interact
	 * \details mengoutput hasil interaksi dengan DLizard
	 */
	void Interact() const;
private:
	static int dLizardNB;
	const float food = 0.2;
};

#endif