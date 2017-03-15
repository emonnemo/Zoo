#include "driver.h"
#include <iostream>
using namespace std;

Driver::Driver() {
  char option;
  int width = 33, length = 32;
  Zoo* z;
  do {
    cout << "Auto generate zoo? (y/n) ";
    cin >> option;  
  } while (option != 'Y' && option != 'y' && option != 'N' && option != 'n');

  if (option == 'N' || option == 'n') {
    do{
      cout << "Input lebar dan panjang zoo: ";
      cin >> width >> length;
    } while (width <= 0 || length <= 0);
    z = new Zoo (0, width, length);
  } else{
    z = new Zoo;
  }
  do {
    cout << "Apa yang ingin anda lakukan?" << endl
    << "1. Tampilkan zoo" << endl
    << "2. Tampilkan total konsumsi makanan semua hewan di zoo" << endl
    << "3. Tour zoo" << endl
    << "4. Buka/tutup semua sekat" << endl
    << "5. Tutup zoo" << endl;
    cin >> option;
    switch (option) {
      case '1':
        z->Display(0, 0, width-1, length-1);
        break;
      case '2':
        cout << "Daging: " << z->GetTotalMeat() << " kg" << endl
        << "Tumbuhan: " << z->GetTotalVegetables() << "kg" << endl;
        break;
      case '3':
        z->Tour();
        break;
      case '4':
        z->ToggleAllSekat();
        break;
    }
    z->MoveAllAnimal();
  } while (option != '5');
}

Driver::~Driver() {}
