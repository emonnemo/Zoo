#ifndef MENU_H
#define MENU_H

using namespace std;

class Menu{
	public:
		/**
		 * \brief Constructor
		 * \details Menampilkan pilihan pada layar dan menerima input option dari keyboard
		 */
		Menu();

		/**
		 * \brief Destuctor
		 */
		~Menu();

		/**
		 * \brief GetOption
		 * \details Mengembalikan option pada menu
		 * \return char
		 */
		char GetOption();

	private:
		char option;
};

#endif