#ifndef AIRANIMAL_H
#define AIRANIMAL_H

using namespace std;
/** @class AirAnimal
  * Kelas AirAnimal adalah kelas turunan dari Animal, yaitu Animal yang tinggal di habitat Air
  */
class AirAnimal: public Animal {
	/** @brief Constructor.
	  */
	AirAnimal(int x, int y);
	/** @brief Destructor.
	  */
	~AirAnimal();
};

#endif