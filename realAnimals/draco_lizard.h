//File draco_lizard.h

#ifndef DRACO_LIZARD_H
#define DRACO_LIZARD_H

#include "../animal.h"
#include <iostream>
#include <set>
using namespace std;

/**
 * \class DracoLizard
 * \details real class dari animal, yaitu kadal terbang
 */
class DracoLizard: public Animal {
public:
	/**
	 * \brief Constructor default weight
	 * \details Menciptakan objek kadal terbang dengan default weight untuk kadal terbang 
	 * 
	 * \param _weight berat badan
	 * \param _position posisi kadal terbang
	 */
	DracoLizard(pair<int,int> _position);
	/**
	 * \brief Constructor dengan weight
	 * \details Menciptakan objek kadal terbang dengan weight sebagai parameter
	 * 
	 * \param _weight berat badan
	 * \param _position posisi kadal terbang
	 */
	DracoLizard(float _weight, pair<int,int> _position);
	/**
	 * \brief DestructorD
	 */
	~DracoLizard();
	/**
	 * \brief Copy Constructor
	 * \details copy constructor, menjamin tidak bitwise copy
	 * 
	 * \param d DracoLizard yang ingin dikopi
	 */
	DracoLizard(const DracoLizard& d);
	/**
	 * \brief Operator =
	 * \details operator=, menjamin tidak bitwise copy
	 * 
	 * \param d DracoLizard yang ingin dikopi
	 * \return DracoLizard yang sama dengan d
	 */
	DracoLizard& operator= (const DracoLizard& d);
	/**
	 * \brief Act
	 * \details DracoLizard's behaviour
	 */
	void Act() const;
	/**
	 * \brief Interact
	 * \details mengoutput hasil interaksi dengan DracoLizard
	 */
	void Interact() const;
private:
	static int draco_lizard_nb;
	const float food = 0.2;
};

#endif
