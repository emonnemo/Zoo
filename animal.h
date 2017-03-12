#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

using namespace std;
/** @class Animal
  * Kelas Animal
  */
class Animal {
	public:
		/**
		 * \brief Constructor
		 * \details Menciptakan email
		 * 
		 * \param _ID ID jenis animal
		 * \param _id nomor pada jenisnya
		 * \param _weight berat badan
		 * \param _eat persentase makan 0-100%
		 * \param _type karnivor, herbivor, omnivor
		 * \param _position posisi hewan
		 */
		Animal(string _ID, int _id, float _weight, float _eat, char _type, pair<int,int> _position);

		/** @brief Destructor.
		  */
		~Animal();

		/** @brief Copy Constructor
		  * \details copy constructor menjamin tidak bitwise copy.
		  * @param a Animal yang ingin di-copy
		  */
		Animal(const Animal& a);

		/** @brief Operator =
		  * \details operator sama dengan, menjamin tidak bitwise copy
		  * @param a Animal yang ingin di-copy
		  */
		Animal& operator= (const Animal& a); 

		string GetID() const;

		/** @brief GetWeight
		  * mengembalikan nilai weight dari suatu Animal
		  */
		int GetWeight() const;

		/**
		 * \brief GetFood
		 * \details mengembalikan nilai persentase makanan animal
		 * \return eat
		 */
		float GetEat() const;

		/** @brief GetPos
		  * mengembalikan nilai posisi dari suatu Animal
		  */
		pair<int,int> GetPos() const;

		/** @brief GetType
		  * \ details mengembalikan type dari suatu Animal
		  */
		char GetType() const;

		/** @brief SetWeight
		  * \details mengatur berat badan suatu Animal
		  * @param _weight nilai berat badan yang ingin  di tetapkan untuk suatu Animal
		  */
		void SetWeight(float _weight);

		/** @brief SetPos
		  * \details mengatur posisi suatu Animal
		  * @param _position nilai posisi yang ingin  di tetapkan untuk suatu Animal
		  */
		void SetPos(pair<int,int> _position);

		/**
		 * \brief Print
		 * \details mengoutput data data animal
		 */

		virtual void Act() const;

		/**
		 * \brief Interact
		 * \details mengoutput hasil interaksi dengan Animal
		 */
		virtual void Interact() const;

		/**
		 * \brief Description
		 * \details mengoutput deskripsi Animal tersebut
		 * \param a jenis binatang
		 */
		void Description(string a) const;

		/**
		 * \brief Move
		 * \details Berpindah sejauh 1 langkah ke arah sesuai direction
		 * \I.S.: arah untuk direction sudah pasti masih dalam cage
		 * \param direction 0 ke atas, 1 ke kiri, 2 ke kanan, 3 ke bawah
		 */
		void Move(int direction);

	protected:
		string ID;
		int id;
		float weight;
		float eat;
		char type;
		pair<int,int> position;
};

#endif