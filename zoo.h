//file: zoo.h

#ifndef ZOO_H
#define ZOO_H

#include "animal.h"
#include "cell.h"
#include <list>
using namespace std;

/** @class Zoo
  * Kelas Zoo yang berisi kebun binatang itu sendiri beserta hewan-hewannya
  */
class Zoo{
	public:
		/**
		  * \brief Constructor
		  * \details Mengenerate kebun binatang denangan list hewan kosong
		  * 
		  * \param Auto, jika true maka kebun binatang akan digenerate secara otomatis, jika false maka kebun binatang didesain oleh pengguna
		  * \param w width lebar kebun binatang
		  * \param l length panjang kebun binatang
		  */
		Zoo(bool , int , int );

		/** @brief cctor
		  */
		Zoo(const Zoo& z);

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

		/**
		 * \brief GetWidth
		 * \details mengembalikan width
		 * \return int
		 */
		int GetWidth() const;

		/**
		 * \brief GetLength
		 * \details mengembalikan length
		 * \return int
		 */
		int GetLength() const;
	private:
		const int width;
		const int length;
		Cell** Cells;
		list<Animal> Animals;

};

#endif