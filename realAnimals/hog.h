//File hog.h

#ifndef HOG_H
#define HOG_H

#include "../animal.h"
#include <iostream>
#include <set>
using namespace std;

/**
 * \class Hog
 * \details real class dari animal, yaitu Hog
 */
class Hog: public Animal {
public:
	/**
	 * \brief Constructor default weight
	 * \details Menciptakan objek Hog dengan default weight untuk Hog 
	 * 
	 * \param _weight berat badan
	 * \param _position posisi Hog
	 */
	Hog(pair<int,int> _position);
	/**
	 * \brief Constructor dengan weight
	 * \details Menciptakan objek Hog dengan weight sebagai parameter
	 * 
	 * \param _weight berat badan
	 * \param _position posisi Hog
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
	 * \param w Hog yang ingin dikopi
	 */
	Hog(const Hog& w);
	/**
	 * \brief Operator =
	 * \details operator=, menjamin tidak bitwise copy
	 * 
	 * \param w Hog yang ingin dikopi
	 * \return Hog yang sama dengan w
	 */
	Hog& operator= (const Hog& w);
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
	static int HogNB;
	const float food = 0.2;
};

#endif