#ifndef RENDERABLE_H
#define RENDERABLE_H

using namespace std;

/**
 * \brief Class Renderable
 * \details Sebuah ABC yang berfungsi untuk menampilkan representasi objek ke layar
 */
class Renderable{
	public:
		/**
		 * \brief Render
		 * \details Menampilkan representasi objek pada layar
		 */
		virtual void Render() = 0;
};

#endif