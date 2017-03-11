#ifndef AIRANIMAL_H
#define AIRANIMAL_H

using namespace std;
/** @class AirAnimal
  * Kelas AirAnimal adalah kelas turunan dari Animal, yaitu Animal yang tinggal di habitat Air
  */
class AirAnimal: public Animal {
	/** @brief Constructor.
	  */
	AirAnimal();
	
	/** @brief Destructor.
	  */
	~AirAnimal();

	/** @brief Copy Constructor
	  * details copy constructor menjamin tidak bitwise copy.
	  * @param a Air Animal yang ingin di-copy
	  */
	AirAnimal(const AirAnimal& a) {
		
	}

	/** @brief Operator =
	  * operator sama dengan
	  * @param a Air Animal yang ingin gunakan oleh operator
	  */
	AirAnimal& operator= (const AirAnimal& a);
};

#endif