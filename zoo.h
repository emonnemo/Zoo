//file: zoo.h

#ifndef ZOO_H
#define ZOO_H

#include "renderable.h"
#include "animal.h"
#include "realAnimals/wolf.h"
#include "realAnimals/lion.h"
#include "realAnimals/zebra.h"
#include "realAnimals/elephant.h"
#include "realAnimals/macaque.h"
#include "realAnimals/hog.h"
#include "realAnimals/shark.h"
#include "realAnimals/moray_eel.h"
#include "realAnimals/dugong.h"
#include "realAnimals/turtle.h"
#include "realAnimals/dolphin.h"
#include "realAnimals/whale.h"
#include "realAnimals/eagle.h"
#include "realAnimals/owl.h"
#include "realAnimals/hummingbird.h"
#include "realAnimals/cockatoo.h"
#include "realAnimals/robin.h"
#include "realAnimals/bat.h"
#include "realAnimals/penguin.h"
#include "realAnimals/hippopotamus.h"
#include "realAnimals/pelican.h"
#include "realAnimals/goose.h"
#include "realAnimals/crane.h"
#include "realAnimals/draco_lizard.h"
#include "realAnimals/colugo.h"
#include "realAnimals/sugar_glider.h"
#include "cell.h"
#include <list>
#include <queue>
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
		Zoo(bool = 1, int = 33, int = 32);

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

		list<Animal*>::iterator FindAnimal(pair<int,int> pos);

		void AddAnimal(Animal* animal);

		/**
		 * \brief DelAnimal dengan ID
		 * \details Menghapus hewan denagn ID=_ID dan id=_id
		 * \param _ID ID jenis hewan
		 * \param id no pada jenis hewan tersebut
		 */
		void DelAnimal(string _id, int _number);

		/**
		 * \brief DelAnimal
		 * \details Menghapus hewan pada posisi x y
		 * \param x posisi pada width
		 * \param y posisi pada length
		 */
		void DelAnimal(int x, int y);

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
		 * \brief MoveAnimal dengan posisi
		 * \details Menggerakkan animal dengan ID=_ID dan id=_id
		 * \param i posisi hewan pada width
		 * \param j posisi hewan pada length
		 * \param direction 0 untuk ke atas, 1 untuk ke kiri, 2 untuk ke kanan, 3 untuk ke bawah
		 */
		void MoveAnimal(pair<int,int> pos, int direction);

		/**
		 * \brief MoveAnimal dengan ID
		 * \details Menggerakkan animal dengan ID=_ID dan id=_id ke arah sesuai direction sebanyak 1 langkah jika memungkinkan (tidak melewati sekat)
		 * \param _ID jenis hewan 
		 * \param id no id pada jenis hewan
		 * \param direction 0 untuk ke atas, 1 untuk ke kiri, 2 untuk ke kanan, 3 untuk ke bawah
		 */
		void MoveAnimal(string _id, int _number, int direction);

		/**
		 * \brief MoveAllAnimal
		 * \details Menggerakkan semua hewan secara acak
		 */
		void MoveAllAnimal();

		/**
		 * \brief ToggleSekat
		 * \details Membuka/menutup sekat pada posisi i,j ke arah direction jika memungkinkan (tidak membuka ke luar cage)
		 * \param i posisi pada width
		 * \param j posisi pada length
		 * \param direction 0 untuk ke atas, 1 untuk ke kiri, 2 untuk ke kanan, 3 untuk ke bawah
		 */
		void ToggleSekat(int i, int j, int direction);

		/**
		 * \brief ToggleAllSekat
		 * \details Membuka/menutup semua sekat
		 */
		void ToggleAllSekat();

		/**
		 * \brief Melakukan tour pada kebun binatang
		 * \details Jalur tour akan dipilih secara acak
		 * \details Settiap cell yang ada di samping road yang dilalui akan diinteract. Suatu cell adalah bagian dari suatu cage, maka semua binatang pada cage tersebut akan diinteract
		 */
		void Tour();

		/**
		 * \brief InteractCage
		 * \details Melakukan interaksi dengan semua hewan yang ada di cage yang sama. Cage memiliki posisi pos dan nomor cage_number
		 * \param pos posisi cage
		 * \param cage_number nomor cage
		 */
		void InteractCage(pair<int, int> pos, int cage_number);

	private:
		const int width;
		const int length;
		Cell*** cells;
		list<Animal*> animals;
		int** cage_map;
		int NBCage;
};

#endif
