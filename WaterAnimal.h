#ifndef WATERANIMAL_H
#define WATERANIMAL_H

using namespace std;
/** @class WaterAnimal
  * Kelas WaterAnimal adalah kelas turunan dari Animal, yaitu Animal yang tinggal di habitat Water
  */
class WaterAnimal: public Animal {
	/** @brief Constructor.
	  */
	WaterAnimal(int x, int y);
	/** @brief Destructor.
	  */
	~WaterAnimal();
};

#endif