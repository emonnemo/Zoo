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
		  * \param Auto, jika true maka kebun binatang akan 1digenerate secara otomatis, jika false maka kebun binatang didesain oleh pengguna
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

		void DelAnimal(int x, int y);

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

		/**
		 * \brief MoveAnimal dengan ID
		 * \details Menggerakkan animal dengan ID=_ID dan id=_id ke arah sesuai direction sebanyak 1 langkah jika memungkinkan (tidak melewati sekat)
		 * \param _ID jenis hewan 
		 * \param id no id pada jenis hewan
		 * \param direction 0 untuk ke atas, 1 untuk ke kiri, 2 untuk ke kanan, 3 untuk ke bawah
		 */
		void MoveAnimal(string _ID, int _id, int direction);

		/**
		 * \brief MoveAnimal dengan posisi
		 * \details Menggerakkan animal dengan ID=_ID dan id=_id
		 * \param i posisi hewan pada width
		 * \param j posisi hewan pada length
		 * \param direction 0 untuk ke atas, 1 untuk ke kiri, 2 untuk ke kanan, 3 untuk ke bawah
		 */
		void MoveAnimal(pair<int,int> pos, int direction);

		/**
		 * \brief ToggleSekat
		 * \details Membuka/menutup sekat pada posisi i,j ke arah direction jika memungkinkan (tidak membuka ke luar cage)
		 * \param i posisi pada width
		 * \param j posisi pada length
		 * \param direction 0 untuk ke atas, 1 untuk ke kiri, 2 untuk ke kanan, 3 untuk ke bawah
		 */
		void ToggleSekat(int i, int j, int direction);

	private:
		const int width;
		const int length;
		Cell*** Cells;
		list<Animal> Animals;
		int** CageM;
};

#endif