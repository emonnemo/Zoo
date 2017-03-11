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
		Animal(string _ID, int _id, int _weight, float _eat, char _type, pair<int,int> _position);

		/** @brief Destructor.
		  */
		~Animal();

		/** @brief Copy Constructor
		  * copy constructor menjamin tidak bitwise copy.
		  * @param a Animal yang ingin di-copy
		  */
		Animal(const Animal& a);

		/** @brief Operator =
		  * operator sama dengan, menjamin tidak bitwise copy
		  * @param a Animal yang ingin di-copy
		  */
		Animal& operator= (const Animal& a); 

		string GetID() const;

		/** @brief GetWeight
		  * mengembalikan nilai weight dari suatu Animal
		  */
		int GetWeight() const;

		/** @brief GetType
		  * mengembalikan type dari suatu Animal
		  */
		char GetType() const;

		/** @brief SetWeight
		  * mengatur berat badan suatu Animal
		  * @param _weight nilai berat badan yang ingin  di tetapkan untuk suatu Animal
		  */
		void SetWeight(int _weight);

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
		 * \brief Move
		 * \details Berpindah sejauh 1 langkah ke arah sesuai direction
		 * \param direction 0 ke atas, 1 ke kiri, 2 ke kanan, 3 ke bawah
		 */
		void Move(int direction);

	private:
		string ID;
		int id;
		int weight;
		float eat;
		char type;
		pair<int,int> position;
};


#endif