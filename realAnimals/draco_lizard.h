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
<<<<<<< HEAD:realAnimals/dLizard.h
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
=======
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
>>>>>>> cb17fe74f29bee37f98ee210c4c55ed3edd81339:realAnimals/draco_lizard.h
};

#endif
