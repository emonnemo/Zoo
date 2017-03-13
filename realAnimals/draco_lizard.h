//File draco_lizard.h

#ifndef DRACO_LIZARD_H
#define DRACO_LIZARD_H

#include "../animal.h"
#include <iostream>
#include <set>
using namespace std;

/**
 * \class Draco_Lizard
 * \details real class dari animal, yaitu kadal terbang
 */
class Draco_Lizard: public Animal {
public:
	/**
	 * \brief Constructor default weight
	 * \details Menciptakan objek kadal terbang dengan default weight untuk kadal terbang 
	 * 
	 * \param _weight berat badan
	 * \param _position posisi kadal terbang
	 */
	Draco_Lizard(pair<int,int> _position);
	/**
	 * \brief Constructor dengan weight
	 * \details Menciptakan objek kadal terbang dengan weight sebagai parameter
	 * 
	 * \param _weight berat badan
	 * \param _position posisi kadal terbang
	 */
	Draco_Lizard(float _weight, pair<int,int> _position);
	/**
	 * \brief DestructorD
	 */
	~Draco_Lizard();
	/**
	 * \brief Copy Constructor
	 * \details copy constructor, menjamin tidak bitwise copy
	 * 
	 * \param d Draco_Lizard yang ingin dikopi
	 */
	Draco_Lizard(const Draco_Lizard& d);
	/**
	 * \brief Operator =
	 * \details operator=, menjamin tidak bitwise copy
	 * 
	 * \param d Draco_Lizard yang ingin dikopi
	 * \return Draco_Lizard yang sama dengan d
	 */
	Draco_Lizard& operator= (const Draco_Lizard& d);
	/**
	 * \brief Act
	 * \details Draco_Lizard's behaviour
	 */
	void Act() const;
	/**
	 * \brief Interact
	 * \details mengoutput hasil interaksi dengan Draco_Lizard
	 */
	void Interact() const;
private:
	static int dracoLizardNB;
	const float food = 0.2;
};

#endif
