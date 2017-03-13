//File sugar_glider.h

#ifndef SUGAR_GLIDER_H
#define SUGAR_GLIDER_H

#include "../animal.h"
#include <iostream>
#include <set>
using namespace std;

/**
 * \class Sugar_Glider
 * \details real class dari animal, yaitu sugar glider
 */
class Sugar_Glider: public Animal {
public:
	/**
	 * \brief Constructor default weight
	 * \details Menciptakan objek sugar glider dengan default weight untuk sugar glider 
	 * 
	 * \param _weight berat badan
	 * \param _position posisi sugar glider
	 */
	Sugar_Glider(pair<int,int> _position);
	/**
	 * \brief Constructor dengan weight
	 * \details Menciptakan objek sugar glider dengan weight sebagai parameter
	 * 
	 * \param _weight berat badan
	 * \param _position posisi sugar glider
	 */
	Sugar_Glider(float _weight, pair<int,int> _position);
	/**
	 * \brief Destructor
	 */
	~Sugar_Glider();
	/**
	 * \brief Copy Constructor
	 * \details copy constructor, menjamin tidak bitwise copy
	 * 
	 * \param s Sugar_Glider yang ingin dikopi
	 */
	Sugar_Glider(const Sugar_Glider& s);
	/**
	 * \brief Operator =
	 * \details operator=, menjamin tidak bitwise copy
	 * 
	 * \param s Sugar_Glider yang ingin dikopi
	 * \return Sugar_Glider yang sama dengan s
	 */
	Sugar_Glider& operator= (const Sugar_Glider& s);
	/**
	 * \brief Act
	 * \details Sugar_Glider's behaviour
	 */
	void Act() const;
	/**
	 * \brief Interact
	 * \details mengoutput hasil interaksi dengan Sugar_Glider
	 */
	void Interact() const;
private:
	static int sugarGliderNB;
	const float food = 0.5;
};

#endif