#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

using namespace std;
/** @class Animal
  * Kelas Animal
  */
class Animal {
	public:
		/** @brief Constructor.
		  * Menciptakan Animal
		  */
		Animal(string ID, int weight, char type);

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

		/** @brief SetType
		  * Mengatur type dari suatu animal
		  * @param _type nilai type yang ingin ditetapkan untuk suatu Animal
		  */
		void SetType(char _type);

		/** @brief SetID
		  * Mengatur ID dari suatu Animal
		  * @param _id nilai id yang ingin ditetapkan untuk suatu animal
		  */
		void SetID(string _id);

		/**
		 * \brief Print
		 * \details mengoutput data data animal
		 */
		void Print();

	private:
		string ID;
		int weight;
		char type;

};


#endif