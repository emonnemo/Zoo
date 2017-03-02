//file: zoo.h

#ifndef ZOO_H
#define ZOO_H

#include "animal.h"

using namespace std;

/** @class Zoo
  * Kelas Zoo yang berisi kebun binatang itu sendiri beserta hewan-hewannya
  */
class Zoo{
	public:
		/** @brief Constructor
		  * Mengenerate kebun binatang denangan list hewan kosong
		  * @param boolean Auto, jika true maka kebun binatang akan digenerate secara otomatis, jika false maka kebun binatang didesain oleh pengguna
		  */
		Zoo(bool Auto);

		/** @brief cctor
		  */
		Zoo(const Zoo z);

		/** @brief Destructor
		  */
		~Zoo();

		/** @brief Operator =
		  * Menjamin bukan bitwise copy
		  */
		Zoo operator=(const Zoo z);

		/** @brief Render
		  * Menampilkan kebun binatang ke layar
		  */
		void Render();

		/** @brief AddAnimal
		  * Menambahkan hewan pada kebun binatang
		  * @param Animal a, hewan yang akan ditambahkan
		  */
		void AddAnimal(Animal a);

		/** @brief DelAnimal
		  * Menghapus hewan dengan ID = i, jika tidak ada maka tidak ad hewan yang dihapus
		  */
		void DelAnimal(int i);

	private:
		const Cell** Cells;
		Animal* Animals;

}