#ifndef LANDANIMAL_H
#define LANDANIMAL_H

using namespace std;
/** @class LandAnimal
  * Kelas LandAnimal adalah kelas turunan dari Animal, yaitu Animal yang tinggal di habitat Land
  */
class LandAnimal: public Animal {
	/** @brief Constructor.
	  */
	LandAnimal();
	/** @brief Destructor.
	  */
	~LandAnimal();

	/** @brief Copy Constructor
	  * details copy constructor menjamin tidak bitwise copy.
	  * @param a Land Animal yang ingin di-copy
	  */
	LandAnimal(const LandAnimal& a);

	/** @brief Operator =
	  * operator sama dengan
	  * @param a Land Animal yang ingin gunakan oleh operator
	  */
	LandAnimal& operator= (const LandAnimal& a);
};

#endif