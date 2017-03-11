#ifndef LANDANIMAL_H
#define LANDANIMAL_H

using namespace std;
/** @class LandAnimal
  * Kelas LandAnimal adalah kelas turunan dari Animal, yaitu Animal yang tinggal di habitat Land
  */
class LandAnimal: public Animal {
	/** @brief Constructor.
	  */
	LandAnimal(int x, int y);
	/** @brief Destructor.
	  */
	~LandAnimal();
};

#endif