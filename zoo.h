//file: zoo.h

#ifndef ZOO_H
#define ZOO_H

#include "animal.h"
#include "realAnimals/wolf.h"
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
		  * \param Auto, jika true maka kebun binatang akan digenerate secara otomatis, jika false maka kebun binatang didesain oleh pengguna
		  * \param w width lebar kebun binatang, default 16
		  * \param l length panjang kebun binatang, default 6
		  */
		Zoo(bool = 1 , int = 16, int = 6);

		/** @brief cctor
		  */
		Zoo(const Zoo& z);

		/** @brief Destructor
		  */
		~Zoo();

		/** @brief Operator =
		  * Menjamin bukan bitwise copy
		  */
		Zoo& operator=(const Zoo& z);

		/** @brief Render
		  * Menampilkan kebun binatang ke layar
		  */
		void Display(int x1, int y1, int x2, int y2);

		/** @brief AddAnimal
		  * Menambahkan hewan pada kebun binatang
		  * @param Animal a, hewan yang akan ditambahkan
		  */

		pair<string,int> FindAnimal(pair<int,int> pos);

		void AddAnimal(Animal& a);

		/**
		 * \brief DelAnimal
		 * \details Menghapus hewan denagn ID=_ID dan id=_id
		 * \param _ID ID jenis hewan
		 * \param id no pada jenis hewan tersebut
		 */
		void DelAnimal(string _ID, int _id);

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

		/**
		 * \brief GetTotalMeat
		 * \details mengeluarkan total daging yang diperlukan di zoo dalam kilogram
		 * \return Total daging yang dibutuhkan zoo
		 */
		float GetTotalMeat() const;

		/**
		 * \brief GetTotalVegetables
		 * \details mengeluarkan total sayur yang diperlukan di zoo dalam kilogram
		 * \return Total sayur yang dibutuhkan zoo
		 */
		float GetTotalVegetables() const;

	private:
		const int width;
		const int length;
		Cell*** Cells;
		list<Animal> Animals;
		int** CageM;
};

#endif