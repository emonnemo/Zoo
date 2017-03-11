#ifndef WATERANIMAL_H
#define WATERANIMAL_H

using namespace std;
/** @class WaterAnimal
  * Kelas WaterAnimal adalah kelas turunan dari Animal, yaitu Animal yang tinggal di habitat Water
  */
class WaterAnimal: public Animal {
	/** @brief Constructor.
	  */
	WaterAnimal();
	/** @brief Destructor.
	  */
	~WaterAnimal();

	/** @brief Copy Constructor
	  * details copy constructor menjamin tidak bitwise copy.
	  * @param a Water Animal yang ingin di-copy
	  */
	WaterAnimal(const WaterAnimal& a);

	/** @brief Operator =
	  * operator sama dengan
	  * @param a Water Animal yang ingin gunakan oleh operator
	  */
	WaterAnimal& operator= (const WaterAnimal& a);
};

#endif