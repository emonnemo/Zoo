//File sgrGlider.h

#ifndef SGRGLIDER_H
#define SGRGLIDER_H

#include "../animal.h"
#include <iostream>
#include <set>
using namespace std;

/**
 * \class SgrGlider
 * \details real class dari animal, yaitu sugar glider
 */
class SgrGlider: public Animal {
public:
	/**
	 * \brief Constructor default weight
	 * \details Menciptakan objek sugar glider dengan default weight untuk sugar glider 
	 * 
	 * \param _weight berat badan
	 * \param _position posisi sugar glider
	 */
	SgrGlider(pair<int,int> _position);
	/**
	 * \brief Constructor dengan weight
	 * \details Menciptakan objek sugar glider dengan weight sebagai parameter
	 * 
	 * \param _weight berat badan
	 * \param _position posisi sugar glider
	 */
	SgrGlider(float _weight, pair<int,int> _position);
	/**
	 * \brief Destructor
	 */
	~SgrGlider();
	/**
	 * \brief Copy Constructor
	 * \details copy constructor, menjamin tidak bitwise copy
	 * 
	 * \param s SgrGlider yang ingin dikopi
	 */
	SgrGlider(const SgrGlider& s);
	/**
	 * \brief Operator =
	 * \details operator=, menjamin tidak bitwise copy
	 * 
	 * \param s SgrGlider yang ingin dikopi
	 * \return SgrGlider yang sama dengan s
	 */
	SgrGlider& operator= (const SgrGlider& s);
	/**
	 * \brief Act
	 * \details SgrGlider's behaviour
	 */
	void Act() const;
	/**
	 * \brief Interact
	 * \details mengoutput hasil interaksi dengan SgrGlider
	 */
	void Interact() const;
private:
	static int sgrGliderNB;
	const float food = 0.5;
};

#endif