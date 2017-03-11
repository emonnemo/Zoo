#ifndef ANIMAL_H
#define ANIMAL_H


using namespace std;
/** @class Animal
  * Kelas Animal
  */
class Animal {
	public:
		/** @brief Constructor.
		  * Menciptakan Animal dengan posisi x dan y
		  * @param x nilai posisi x yang diinginkan
		  * @param y nilai posisi y yang diinginkan
		  */
		Animal(int x, int y);

		/** @brief Destructor.
		  */
		~Animal();

	private:
		int ID;
		int weight;
		char type;

};


#endif