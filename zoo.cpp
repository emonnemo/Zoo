/* Author    : Andika Kusuma / 13515033
 * File      : zoo.cpp
 */

#include "zoo.h"
#include "cell.h"
#include "road.h"
#include "facility.h"
#include "habitat.h"
#include "park.h"
#include "restaurant.h"
#include <time.h>
#include <list>
#include <set>
#include <stack>
#include <fstream>
#include <iostream>

using namespace std;


Zoo::Zoo(bool Auto, int w , int l) : width(w), length(l) {
  Cells = new Cell**[width];
  for (int i = 0; i < width; ++i) Cells[i] = new Cell* [length];
  string line;
  if (Auto) { // automatis ctor dari file eksternal
    ifstream ifile("map.txt");
    if (ifile.is_open()) {
      int i = 0;
      while(getline(ifile, line)) {
        for (int j = 0; j < length; ++j) {
          switch (line[j]) {
            case 'W':
              Cells[i][j] = new Habitat('W');
              break;
            case 'A':
              Cells[i][j] = new Habitat('A');
              break;
            case 'L':
              Cells[i][j] = new Habitat('L');
              break;
            case 'X':
              Cells[i][j] = new Road('X');
              break;
            case 'N':
              Cells[i][j] = new Road('N');
              break;
            case 'r':
              Cells[i][j] = new Road('r');
              break;
            case 'R':
              Cells[i][j] = new Restaurant();
              break;
            case 'P':
              Cells[i][j] = new Park();
              break;
          }
        }
        ++i;
      }
    }
    ifile.close();
  }
  else { // membaca input dari user
    for (int i = 0; i < width; ++i) {
      getline(cin, line);
      for (int j = 0; j < length; ++j) {
        switch (line[j]) {
          case 'W':
            Cells[i][j] = new Habitat('W');
            break;
          case 'A':
            Cells[i][j] = new Habitat('A');
            break;
          case 'L':
            Cells[i][j] = new Habitat('L');
            break;
          case 'X':
            Cells[i][j] = new Road('X');
            break;
          case 'N':
            Cells[i][j] = new Road('N');
            break;
          case 'r':
            Cells[i][j] = new Road('r');
            break;
          case 'R':
            Cells[i][j] = new Restaurant();
            break;
          case 'P':
            Cells[i][j] = new Park();
            break;
        }
      }
    }
  }
  // caging
  CageM = new int*[w];
  for(int i = 0; i < w; i++) {
    CageM[i] = new int[l];
    for(int j = 0; j < l; j++) {
      CageM[i][j] = -99;
    }
  } // alokasi memori CageM
  int counter = 1; // counter cage ke - i
  for (int i = 0; i < w; i++) {
    for (int j = 0; j < l; j++) {
      if (CageM[i][j] == -99) { // jika belum terisi
        char c = Cells[i][j]->GetSymbol();
        if (c != 'W' && c != 'A' && c != 'L') {
        // jika bukan merupakan habitat akan diisi  0
          CageM[i][j] = 0;
        }
        else { // habitat
          int ai[4], aj[4]; // array menyimpan posisi yang akan dirubah
          for (int kk = 0; kk < 4; kk++) {
            ai[kk] = i, aj[kk] = j; // inisialisasi
          }
          bool cek = true; // boolean apakah bisa membentuk cage atau tidak
          CageM[i][j] = counter; // dimasukkan ke cage counter
          srand(time(NULL));
          pair<int,int> movable[12]; // array pair jalan yang mungkin
          int ii, jj, icek = i, jcek = j, count = 0;
          for (int times = 0; times < 3; times++) {
          // cukup 3x karena akan dibuat cage dengan
          // jumlah cell 4 terlebih dahulu
            for (int k = 0; k < 4; k++) { // ada 4 sel bersebelahan
              bool dum = false;
              // atas
              if (k == 0 && icek != 0) {
                ii = icek - 1, jj = jcek, dum = true;
              }
              // kiri
              else if(k == 1 && jcek != 0) {
                ii = icek, jj = jcek - 1, dum = true;
              }
              // bawah
              else if (k == 2 && icek != w - 1) {
                ii = icek + 1, jj = jcek, dum = true;
              }
              // kanan
              else if (k == 3 && jcek != l - 1) {
                ii = icek , jj = jcek + 1, dum = true;
              }
              if (dum) { // jika ada sel disebelahnya
                if (Cells[ii][jj]->GetSymbol() == c && CageM[ii][jj] == -99) {
                // jika sama habitatnya dan belum masuk ke cage
                  movable[count] = make_pair(ii,jj);
                  // menjadi salah satu pilihan
                  count++; // jumlah pilihan
                }
              }
            }
            if (count == 0) { // gaada pilihan, maka akan direturn salah
              cek = false;
              break;
            }
            int move = rand() % count; // random jalan
            icek = movable[move].first;
            jcek = movable[move].second;
            ai[times] = icek; // pengisian posisi yang sudah dirubah
            aj[times] = jcek;
            movable[move] = make_pair(movable[count-1].first,
                                      movable[count-1].second);
            CageM[icek][jcek] = counter;
            count--;
            if (times == 2) counter++; 
            // jika sudah selesai dengan cage dengan 4 cell counter ditambah
          }
          if (!cek) { 
          // jumlah cell tidak sampai 4, semua yang sudah diisi dikembalikan ke -99
            for (int k = 0; k < 4; k++) {
              CageM[ai[k]][aj[k]] = -99;
            }
          }
        }
      }
    }
  }
  NBCage = counter-1;
  // mengurus habitat yang belum masuk ke cage
  int change = -1; // banyak perubahan yang dilakukan
  while (change != 0) { // jika sudah tidak ada perubahan berhenti
    change = 0; // inisialisasi
    for (int i = 0; i < w; i++) {
      for (int j = 0; j < l; j++) {
        if (CageM[i][j] == -99) { // masih belum terisi
          pair<int,int> movable[4]; // array jalan yang mungkin
          int count = 0, ii, jj;
          for (int k = 0; k < 4; k++) { 
          // ada 4 kemungkinan, atas, bawah, kiri, kanan
            bool dum = false; // boolean mungkin atau tidak
            if (k == 0 && i != 0) { // atas mungkin
              ii = i - 1, jj = j, dum = true;
            }
            else if (k == 1 && j != 0) { // kiri mungkin
              ii = i, jj = j - 1, dum = true;
            }
            else if (k == 2 && i != w - 1) { // bawah mungkin
              ii = i + 1, jj = j, dum = true;
            }
            else if (k == 3 && j != l - 1) { // kanan mungkin
              ii = i , jj = j + 1, dum = true;
            }
            if (dum) { // jika jalan mungkin
              if (Cells[ii][jj]->GetSymbol() == Cells[i][j]->GetSymbol() &&
                  CageM[ii][jj] != -99) {
              // jika habitatnya sama, dan sudah masuk ke cage
                movable[count] = make_pair(ii,jj);
                count++;
              }
            }
          }
          if (count > 0) { // jika ada pilihan
            int move = rand() % count; // random
            ii = movable[move].first;
            jj = movable[move].second;
            CageM[i][j] = CageM[ii][jj];
            change++;
          }
        }
      }
    }
  }
  if(Auto){
    // membaca animals dari animals.txt
    ifstream in("animals.txt");
    if (in.is_open()) {
      while(getline(in, line)) {
        string id = "";
        int px = 0;
        int py = 0;
        int j = 0;
        // membaca id
        while(line[j] != '|'){
          id += line[j];
          j++;
        }
        j++;
        // membaca px
        while(line[j] != '|'){
          px = 10*px + line[j] - '0';
          j++;
        }
        j++;
        //membaca py
        while(j < (int)line.length()){
          py = 10*py + line[j] - '0';
          j++;
        }
        if(id == "WF"){
          Wolf* pa;
          pa = new Wolf(make_pair(py,px));
          AddAnimal(pa);
        }
        else if(id == "LI"){
          Lion* pa;
          pa = new Lion(make_pair(py,px));
          AddAnimal(pa);
        }
        else if(id == "ZBR"){
          Zebra* pa;
          pa = new Zebra(make_pair(py,px));
          AddAnimal(pa);
        }
        else if(id == "ELP"){
          Elephant* pa;
          pa = new Elephant(make_pair(py,px));
          AddAnimal(pa);
        }
        else if(id == "MCQ"){
          Macaque* pa;
          pa = new Macaque(make_pair(py,px));
          AddAnimal(pa);
        }
        else if(id == "HG"){
          Hog* pa;
          pa = new Hog(make_pair(py,px));
          AddAnimal(pa);
        }
        else if(id == "EGL"){
          Eagle* pa;
          pa = new Eagle(make_pair(py,px));
          AddAnimal(pa);
        }
        else if(id == "OW"){
          Owl* pa;
          pa = new Owl(make_pair(py,px));
          AddAnimal(pa);
        }
        else if(id == "HMB"){
          Hummingbird* pa;
          pa = new Hummingbird(make_pair(py,px));
          AddAnimal(pa);
        }
        else if(id == "CKT"){
          Cockatoo* pa;
          pa = new Cockatoo(make_pair(py,px));
          AddAnimal(pa);
        }
        else if(id == "RBN"){
          Robin* pa;
          pa = new Robin(make_pair(py,px));
          AddAnimal(pa);
        }
        else if(id == "BT"){
          Bat* pa;
          pa = new Bat(make_pair(py,px));
          AddAnimal(pa);
        }
        else if(id == "SHK"){
          Shark* pa;
          pa = new Shark(make_pair(py,px));
          AddAnimal(pa);
        }
        else if(id == "MRE"){
          Moray_Eel* pa;
          pa = new Moray_Eel(make_pair(py,px));
          AddAnimal(pa);
        }
        else if(id == "DGG"){
          Dugong* pa;
          pa = new Dugong(make_pair(py,px));
          AddAnimal(pa);
        }
        else if(id == "TRL"){
          Turtle* pa;
          pa = new Turtle(make_pair(py,px));
          AddAnimal(pa);
        }
        else if(id == "DLP"){
          Dolphin* pa;
          pa = new Dolphin(make_pair(py,px));
          AddAnimal(pa);
        }
        else if(id == "WHL"){
          Whale* pa;
          pa = new Whale(make_pair(py,px));
          AddAnimal(pa);
        }
        else if(id == "PNG"){
          Penguin* pa;
          pa = new Penguin(make_pair(py,px));
          AddAnimal(pa);
        }
        else if(id == "HPP"){
          Hippopotamus* pa;
          pa = new Hippopotamus(make_pair(py,px));
          AddAnimal(pa);
        }
        else if(id == "PLC"){
          Pelican* pa;
          pa = new Pelican(make_pair(py,px));
          AddAnimal(pa);
        }
        else if(id == "GSE"){
          Goose* pa;
          pa = new Goose(make_pair(py,px));
          AddAnimal(pa);
        }
        else if(id == "CRN"){
          Crane* pa;
          pa = new Crane(make_pair(py,px));
          AddAnimal(pa);
        }
        else if(id == "DRL"){
          Draco_Lizard* pa;
          pa = new Draco_Lizard(make_pair(py,px));
          AddAnimal(pa);
        }
        else if(id == "CLG"){
          Colugo* pa;
          pa = new Colugo(make_pair(py,px));
          AddAnimal(pa);
        }
        else if(id == "SGL"){
          Sugar_Glider* pa;
          pa = new Sugar_Glider(make_pair(py,px));
          AddAnimal(pa);
        }
      }
    }
    in.close();
  }
  else{
    char option;
    do {
      cout << "Ingin menambah hewan lagi? (y/n)";
      cin >> option;
      if(option == 'Y' || option == 'y'){
        string id;
        char def_weight;
        int px;
        int py;
        int weight = -1;
        cout << "Input id hewan :";
        cin >> id;
        cout << "Input posisi x : (kolom ke-)";
        cin >> px;
        cout << "Input posisi y : (baris ke-)";
        cin >> py;
        cout << "Apakah ingin menggunakan berat default? (y/n)";
        cin >> def_weight;
        if(def_weight == 'Y' || def_weight == 'y'){
          do{
            cout << "Input berat : (>0)";
            cin >> weight;
          } while(weight <= 0);
        }
        if(id == "WF"){
          Wolf* pa;
          if(weight != -1) pa = new Wolf(weight,make_pair(py,px));
          else pa = new Wolf(make_pair(py,px));
          AddAnimal(pa);
        }
        else if(id == "LI"){
          Lion* pa;
          if(weight != -1) pa = new Lion(weight,make_pair(py,px));
          else pa = new Lion(make_pair(py,px));
          AddAnimal(pa);
        }
        else if(id == "ZBR"){
          Zebra* pa;
          if(weight != -1) pa = new Zebra(weight,make_pair(py,px));
          else pa = new Zebra(make_pair(py,px));
          AddAnimal(pa);
        }
        else if(id == "ELP"){
          Elephant* pa;
          if(weight != -1) pa = new Elephant(weight,make_pair(py,px));
          else pa = new Elephant(make_pair(py,px));
          AddAnimal(pa);
        }
        else if(id == "MCQ"){
          Macaque* pa;
          if(weight != -1) pa = new Macaque(weight,make_pair(py,px));
          else pa = new Macaque(make_pair(py,px));
          AddAnimal(pa);
        }
        else if(id == "HG"){
          Hog* pa;
          if(weight != -1) pa = new Hog(weight,make_pair(py,px));
          else pa = new Hog(make_pair(py,px));
          AddAnimal(pa);
        }
        else if(id == "EGL"){
          Eagle* pa;
          if(weight != -1) pa = new Eagle(weight,make_pair(py,px));
          else pa = new Eagle(make_pair(py,px));
          AddAnimal(pa);
        }
        else if(id == "OW"){
          Owl* pa;
          if(weight != -1) pa = new Owl(weight,make_pair(py,px));
          else pa = new Owl(make_pair(py,px));
          AddAnimal(pa);
        }
        else if(id == "HMB"){
          Hummingbird* pa;
          if(weight != -1) pa = new Hummingbird(weight,make_pair(py,px));
          else pa = new Hummingbird(make_pair(py,px));
          AddAnimal(pa);
        }
        else if(id == "CKT"){
          Cockatoo* pa;
          if(weight != -1) pa = new Cockatoo(weight,make_pair(py,px));
          else pa = new Cockatoo(make_pair(py,px));
          AddAnimal(pa);
        }
        else if(id == "RBN"){
          Robin* pa;
          if(weight != -1) pa = new Robin(weight,make_pair(py,px));
          else pa = new Robin(make_pair(py,px));
          AddAnimal(pa);
        }
        else if(id == "BT"){
          Bat* pa;
          if(weight != -1) pa = new Bat(weight,make_pair(py,px));
          else pa = new Bat(make_pair(py,px));
          AddAnimal(pa);
        }
        else if(id == "SHK"){
          Shark* pa;
          if(weight != -1) pa = new Shark(weight,make_pair(py,px));
          else pa = new Shark(make_pair(py,px));
          AddAnimal(pa);
        }
        else if(id == "MRE"){
          Moray_Eel* pa;
          if(weight != -1) pa = new Moray_Eel(weight,make_pair(py,px));
          else pa = new Moray_Eel(make_pair(py,px));
          AddAnimal(pa);
        }
        else if(id == "DGG"){
          Dugong* pa;
          if(weight != -1) pa = new Dugong(weight,make_pair(py,px));
          else pa = new Dugong(make_pair(py,px));
          AddAnimal(pa);
        }
        else if(id == "TRL"){
          Turtle* pa;
          if(weight != -1) pa = new Turtle(weight,make_pair(py,px));
          else pa = new Turtle(make_pair(py,px));
          AddAnimal(pa);
        }
        else if(id == "DLP"){
          Dolphin* pa;
          if(weight != -1) pa = new Dolphin(weight,make_pair(py,px));
          else pa = new Dolphin(make_pair(py,px));
          AddAnimal(pa);
        }
        else if(id == "WHL"){
          Whale* pa;
          if(weight != -1) pa = new Whale(weight,make_pair(py,px));
          else pa = new Whale(make_pair(py,px));
          AddAnimal(pa);
        }
        else if(id == "PNG"){
          Penguin* pa;
          if(weight != -1) pa = new Penguin(weight,make_pair(py,px));
          else pa = new Penguin(make_pair(py,px));
          AddAnimal(pa);
        }
        else if(id == "HPP"){
          Hippopotamus* pa;
          if(weight != -1) pa = new Hippopotamus(weight,make_pair(py,px));
          else pa = new Hippopotamus(make_pair(py,px));
          AddAnimal(pa);
        }
        else if(id == "PLC"){
          Pelican* pa;
          if(weight != -1) pa = new Pelican(weight,make_pair(py,px));
          else pa = new Pelican(make_pair(py,px));
          AddAnimal(pa);
        }
        else if(id == "GSE"){
          Goose* pa;
          if(weight != -1) pa = new Goose(weight,make_pair(py,px));
          else pa = new Goose(make_pair(py,px));
          AddAnimal(pa);
        }
        else if(id == "CRN"){
          Crane* pa;
          if(weight != -1) pa = new Crane(weight,make_pair(py,px));
          else pa = new Crane(make_pair(py,px));
          AddAnimal(pa);
        }
        else if(id == "DRL"){
          Draco_Lizard* pa;
          if(weight != -1) pa = new Draco_Lizard(weight,make_pair(py,px));
          else pa = new Draco_Lizard(make_pair(py,px));
          AddAnimal(pa);
        }
        else if(id == "CLG"){
          Colugo* pa;
          if(weight != -1) pa = new Colugo(weight,make_pair(py,px));
          else pa = new Colugo(make_pair(py,px));
          AddAnimal(pa);
        }
        else if(id == "SGL"){
          Sugar_Glider* pa;
          if(weight != -1) pa = new Sugar_Glider(weight,make_pair(py,px));
          else pa = new Sugar_Glider(make_pair(py,px));
          AddAnimal(pa);
        }
      }
    }while (option == 'Y' || option == 'y');
  }
}

Zoo::Zoo(const Zoo& z) : width(z.width), length(z.length) {
  Cells = new Cell**[width];
  for (int i = 0; i < width; i++) Cells[i] = new Cell*[length];
  for (int i = 0; i < width; i++) {
    for (int j = 0; j < length; j++) {
      switch ((z.Cells[i][j])->GetInitSymbol()) {
        case 'W':
          Cells[i][j] = new Habitat('W');
          break;
        case 'A':
          Cells[i][j] = new Habitat('A');
          break;
        case 'L':
          Cells[i][j] = new Habitat('L');
          break;
        case 'X':
          Cells[i][j] = new Road('X');
          break;
        case 'N':
          Cells[i][j] = new Road('N');
          break;
        case 'r':
          Cells[i][j] = new Road('r');
          break;
        case 'R':
          Cells[i][j] = new Restaurant();
          break;
        case 'P':
          Cells[i][j] = new Park();
          break;
      }
    }
  }
  for (int i = 0; i < width; i++) {
    for (int j = 0; j < length; j++) {
      CageM[i][j] = z.CageM[i][j];
    }
  }
  NBCage = z.NBCage;
}
Zoo::~Zoo() {
  for(int i = 0; i < width; i++) delete [] CageM[i];
  delete [] CageM;
  for (int i = 0; i < width; i++) {
    for (int j = 0; j < length; j++) {
      delete Cells[i][j];
    }
    delete [] Cells[i];
  }
  delete [] Cells;
}
Zoo& Zoo::operator=(const Zoo& z) {
  for (int i = 0; i < width; i++) {
    for (int j = 0; j < length; j++) {
      switch ((z.Cells[i][j])->GetInitSymbol()) {
        case 'W':
          Cells[i][j] = new Habitat('W');
          break;
        case 'A':
          Cells[i][j] = new Habitat('A');
          break;
        case 'L':
          Cells[i][j] = new Habitat('L');
          break;
        case 'X':
          Cells[i][j] = new Road('X');
          break;
        case 'N':
          Cells[i][j] = new Road('N');
          break;
        case 'r':
          Cells[i][j] = new Road('r');
          break;
        case 'R':
          Cells[i][j] = new Restaurant();
          break;
        case 'P':
          Cells[i][j] = new Park();
          break;
      }
    }
  }
  for (int i = 0; i < width; i++) {
    for (int j = 0; j < length; j++) {
      CageM[i][j] = z.CageM[i][j];
    }
  }
  NBCage = z.NBCage;
  return *this;
}

void Zoo::Display(int x1, int y1, int x2, int y2) {
  for (int i = x1; i <= x2; ++i) {
    for (int j = y1; j <= y2; ++j) {
      Cells[i][j]->Render();
    }
    cout << endl;
  }
}

list<Animal*>::iterator Zoo::FindAnimal(pair<int,int> pos) {
  list<Animal*>::iterator it = Animals.begin();
  list<Animal*>::iterator e = Animals.end();
  --e;
  if (it != Animals.end()) {
    while ((*it)->GetPos() != pos && it != e) {
    ++it;
    }
    if ((*it)->GetPos() == pos) {
      return it;
    } else {
      return Animals.end();
    }
  } else {
    return it;
  }
  
}

void Zoo::AddAnimal(Animal* a) {
  int posx = a->GetPos().first;
  int posy = a->GetPos().second;
  if(posx < width && posy << length){
    int cage = CageM[posx][posy];
    // cek if habitat dlu
    set<char> hab = a->GetHabitat();
    set<string> compability = a->GetCompatible();
    if (FindAnimal(make_pair(posx,posy)) == Animals.end()) {
      if (hab.find(Cells[posx][posy]->GetSymbol()) != hab.end()) {
        bool compatible = true; 
        // cek apakah ada hewan yang tidak kompatible dengan hewan a
        int count = 0; // count animal yang ada di cage yang sama
        for (list<Animal*>::const_iterator it = Animals.begin();
             it != Animals.end(); ++it) {
          if (cage == CageM[(*it)->GetPos().first][(*it)->GetPos().second]) {
            count++;
            if (compability.find(a->GetID()) == compability.end()) {
              compatible = false;
            }
          }
        }
        int max = 0;
        for (int i = 0; i < width; i++) {
          for (int j = 0; j < length; j++) {
            if (CageM[i][j] == cage) {
              max++;
            }
          }
        }
        if(0.3*max>=(count+1) && compatible){ // masih muat cagenya
          Animals.push_back(a);
          Cells[posx][posy]->SetSymbol(a->GetLegend());
        }
      }
    }
  }
}

void Zoo::DelAnimal(string _ID, int _id) {
  list<Animal*>::iterator it = Animals.begin();
  list<Animal*>::iterator e = Animals.end();
  --e;
  while ((*it)->GetID() != _ID && (*it)->Getid() != _id && it != e) {
    ++it;
  }
  if ((*it)->GetID() == _ID && (*it)->Getid() == _id) {
    delete (*it);
    Animals.erase(it);
  }
  int posx = (*it)->GetPos().first;
  int posy = (*it)->GetPos().second;
  Cells[posx][posy]->SetSymbol(Cells[posx][posy]->GetInitSymbol());
}

void Zoo::DelAnimal(int x, int y) {
  if (FindAnimal(make_pair(x,y)) != Animals.end()) {
    DelAnimal((*FindAnimal(make_pair(x,y)))->GetID(),
              (*FindAnimal(make_pair(x,y)))->Getid());
  }
}

int Zoo::GetWidth() const {
  return width;
}
int Zoo::GetLength() const {
  return length;
}

float Zoo::GetTotalMeat() const {
  float sum = 0;
  for (list<Animal*>::const_iterator it = Animals.begin(); it != Animals.end(); ++it) {
    if ((*it)->GetType() == 'K') {
      sum += (*it)->GetWeight() * (*it)->GetEat();
    }
    else if ((*it)->GetType() == 'O') {
      sum += 0.5 * (*it)->GetWeight() * (*it)->GetEat();
    }
  }
  return sum;
}

float Zoo::GetTotalVegetables() const {
  float sum = 0;
  for (list<Animal*>::const_iterator it = Animals.begin(); it != Animals.end(); ++it) {
    if ((*it)->GetType() == 'H') {
      sum += (*it)->GetWeight() * (*it)->GetEat();
    }
    else if ((*it)->GetType() == 'O') {
      sum += 0.5 * (*it)->GetWeight() * (*it)->GetEat();
    }
  }
  return sum;
}

void Zoo::MoveAnimal(pair<int, int> pos, int direction) {
  list<Animal*>::iterator it = FindAnimal(pos);
  if (it != Animals.end()) {
    if (Cells[pos.first][pos.second]->GetSekat(direction)) {
      bool valid = false;
      int i = pos.first, j = pos.second;
      switch(direction) {
        case 0:
          if (i-1 >= 0) {
            valid = true;
            --i;
          }
          break;
        case 1:
          if (j-1 >= 0) {
            valid = true;
            --j;
          }
          break;
        case 2:
          if (j+1 < length) {
            valid = true;
            ++j;
          }
          break;
        case 3:
          if (i+1 < width) {
            valid = true;
            ++i;
          }
          break;
      }
      if (valid) {
        if (FindAnimal(make_pair(i,j)) == Animals.end()) {
          (*it)->Move(direction);
          Cells[pos.first][pos.second]->SetSymbol(Cells[pos.first][pos.second]->GetInitSymbol());
          Cells[(*it)->GetPos().first][(*it)->GetPos().second]->SetSymbol((*it)->GetLegend());
        }
      }
    }
  }
}

void Zoo::MoveAnimal(string _ID, int _id, int direction) {
  list<Animal*>::iterator it = Animals.begin();
  list<Animal*>::iterator e = Animals.end();
  --e;
  while ((*it)->GetID() != _ID && (*it)->Getid() != _id && it != e) {
    ++it;
  }
  if ((*it)->GetID() == _ID && (*it)->Getid() == _id) {
    MoveAnimal((*it)->GetPos(), direction);
  }
}

void Zoo::MoveAllAnimal(){
  srand(time(NULL));
  for (list<Animal*>::iterator it = Animals.begin(); it != Animals.end(); ++it){
    MoveAnimal((*it)->GetPos(), (rand()%4));
  }
}

void Zoo::ToggleSekat(int i, int j, int direction){
  if (i >=0 && i < width && j >= 0 && j < length){
    char c = Cells[i][j]->GetInitSymbol();
    if (c == 'W' || c == 'L' || c == 'A') {
      switch (direction) {
        case 0:
          if (i-1 >= 0) {
            if (CageM[i-1][j] == CageM[i][j]) {
              Cells[i][j]->ToggleSekat(0);
              Cells[i-1][j]->ToggleSekat(3);
            }
          }
          break;
        case 1:
          if (j-1 >= 0) {
            if (CageM[i][j-1] == CageM[i][j]) {
              Cells[i][j]->ToggleSekat(1);
              Cells[i][j-1]->ToggleSekat(2);
            }
          }
          break;
        case 2:
          if (j+1 < length) {
            if (CageM[i][j+1] == CageM[i][j]) {
              Cells[i][j]->ToggleSekat(2);
              Cells[i][j+1]->ToggleSekat(1);
            }
          }
          break;
        case 3:
          if (i+1 < width) {
            if (CageM[i+1][j] == CageM[i][j]) {
              Cells[i][j]->ToggleSekat(3);
              Cells[i+1][j]->ToggleSekat(0);
            }
          }
          break;
      }
    }
  }
}

void Zoo::ToggleAllSekat(){
  for (int i = 0; i < width; ++i){
    for (int j = 0; j < length; ++j){
      for (int k = 0; k < 2; ++k){
        ToggleSekat(i, j, k);
      }
    }
  }
}

void Zoo::Tour(){
  set<pair<int,int>> entrance;
  bool vis[width][length];
  for (int i = 0; i < width; ++i) {
    for (int j = 0; j < length; ++j) {
      if (Cells[i][j]->GetSymbol() == 'N') {
        entrance.insert(make_pair(i, j));
      }
      vis[i][j] = false;
    }
  }
  srand(time(NULL));
  int selection = rand() % entrance.size();
  set<pair<int,int>>::iterator it = entrance.begin();
  for (int i = 0; i < selection; ++i) {
    ++it;
  }
  stack<pair<int,int>> dstack;
  list<int> route;
  dstack.push(*it);
  bool found = false;
  while (!found){
    int i = dstack.top().first, j = dstack.top().second;
    vis[i][j] = true;
    if (Cells[i][j]->GetSymbol() == 'X') {
      found = true;
      route.push_back(4);
    } else {
      char c;
      set<int> choice;
      if (i-1 >= 0) {
        c = Cells[i-1][j]->GetSymbol();
        if (c == 'r' || c == 'X') {
          if (!vis[i-1][j]) {
            choice.insert(0);
          }
        }
      }
      if (j - 1 >= 0) {
        c = Cells[i][j-1]->GetSymbol();
        if (c == 'r' || c == 'X') {
          if (!vis[i][j-1]) {
            choice.insert(1);
          }
        }
      }
      if (j + 1 < length) {
        c = Cells[i][j+1]->GetSymbol();
        if (c == 'r' || c == 'X') {
          if (!vis[i][j+1]) {
            choice.insert(2);
          }
        }
      }
      if (i+1 < width) {
        c = Cells[i+1][j]->GetSymbol();
        if (c == 'r' || c == 'X') {
          if (!vis[i+1][j]) {
            choice.insert(3);
          }
        }
      }
      if (choice.size() > 0) {
        selection = rand() % choice.size();
        set<int>::iterator st = choice.begin();
        for (int k = 0; k < selection; ++k) {
          ++st;
        }
        route.push_back(*st);
        switch(*st) {
          case 0:
            dstack.push(make_pair(i - 1, j));
            break;
          case 1:
            dstack.push(make_pair(i, j - 1));
            break;
          case 2:
            dstack.push(make_pair(i, j + 1));
            break;
          case 3:
            dstack.push(make_pair(i + 1, j));
            break;
        }
      } else {
        dstack.pop();
        route.pop_back();
      }
    }
  }
  int i = it->first, j = it->second;
  bool VisCage[NBCage];
  for (int i = 0; i < NBCage; ++i) {
    VisCage[i] = false;
  }
  while (!route.empty()) {
    if (i - 1 >= 0) {
      char c = Cells[i-1][j]->GetInitSymbol();
      if (c == 'P' || c == 'R') {
        Cells[i-1][j]->Interact();
      } else if (c == 'W' || c == 'L' || c == 'A') {
        if (!VisCage[CageM[i-1][j]]) {
          InteractCage(make_pair(i - 1,j), CageM[i-1][j]);
          VisCage[CageM[i-1][j]] = true;
        }
      }
    }
    if (j - 1 >= 0) {
      char c = Cells[i][j-1]->GetInitSymbol();
      if (c == 'P' || c == 'R') {
        Cells[i][j-1]->Interact();
      } else if (c == 'W' || c == 'L' || c == 'A') {
        if (!VisCage[CageM[i][j-1]]) {
          InteractCage(make_pair(i,j - 1), CageM[i][j-1]);
          VisCage[CageM[i][j-1]] = true;
        }
      }
    }
    if (j + 1 < length) {
      char c = Cells[i][j+1]->GetInitSymbol();
      if (c == 'P' || c == 'R') {
        Cells[i][j+1]->Interact();
      } else if (c == 'W' || c == 'L' || c == 'A') {
        if (!VisCage[CageM[i][j+1]]) {
          InteractCage(make_pair(i,j + 1), CageM[i][j+1]);
          VisCage[CageM[i][j+1]] = true;
        }
      }
    }
    if (i + 1 < width) {
      char c = Cells[i+1][j]->GetInitSymbol();
      if (c == 'P' || c == 'R') {
        Cells[i+1][j]->Interact();
      } else if (c == 'W' || c == 'L' || c == 'A') {
        if (!VisCage[CageM[i+1][j]]) {
          InteractCage(make_pair(i + 1,j), CageM[i+1][j]);
          VisCage[CageM[i+1][j]] = true;
        }
      }
    }
    switch (route.front()) {
      case 0:
        --i;
        break;
      case 1:
        --j;
        break;
      case 2:
        ++j;
        break;
      case 3:
        ++i;
        break;
    }
    route.pop_front();
  }
}

void Zoo::InteractCage(pair<int,int> pos, int cnumber) {
  bool Vis[width][length];
  for (int i = 0; i < width; ++i) {
    for (int j = 0; j < length; ++j) {
      Vis[i][j] = false;
    }
  }
  queue<pair<int, int>> bqueue;
  bqueue.push(pos);
  Vis[pos.first][pos.second] = true;
  while (!bqueue.empty()) {
    int i = bqueue.front().first, j = bqueue.front().second;
    bqueue.pop();
    if (FindAnimal(make_pair(i,j)) != Animals.end()) {
      (*FindAnimal(make_pair(i,j)))->Interact();
    }  
    if (i-1 >= 0) {
      if (CageM[i-1][j] == cnumber) {
        if (!Vis[i-1][j]) {
          bqueue.push(make_pair(i - 1, j));
          Vis[i-1][j] = true;
        }
      }
    }
    if (j - 1 >= 0) {
      if (CageM[i][j-1] == cnumber) {
        if (!Vis[i][j-1]) {
          bqueue.push(make_pair(i,j - 1));
          Vis[i][j-1] = true;
        }
      }
    }
    if (j+1 < length) {
      if (CageM[i][j+1] == cnumber) {
        if (!Vis[i][j+1]) {
          bqueue.push(make_pair(i,j + 1));
          Vis[i][j+1] = true;
        }
      }
    }
    if (i+1 < width) {
      if (CageM[i+1][j] == cnumber) {
        if (!Vis[i+1][j]) {
          bqueue.push(make_pair(i + 1,j));
          Vis[i+1][j] = true;
        }
      }
    }  
  }
}
