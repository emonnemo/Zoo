#include "menu.h"
#include <iostream>
using namespace std;

Menu::Menu(){
	cout << "Apa yang ingin anda lakukan?" << endl
	<< "1. Tampilkan zoo" << endl
	<< "2. Tampilkan total konsumsi makanan semua hewan di zoo" << endl
	<< "3. Tour zoo" << endl
	<< "4. Buka/tutup semua sekat" << endl
	<< "5. Tutup zoo" << endl;
	cin >> option;
}

Menu::~Menu(){

}

char Menu::GetOption(){
	return option;
}