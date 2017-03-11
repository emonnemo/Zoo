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
		Animal(string _ID, float _eat, int _weight, char _type);

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
		void Print() const;

		virtual void Interact() const = 0;

	private:
		string ID;
		int id;
		int weight;
		float eat;
		char type;
		int x;
		int y;
};


#endif