// File 	: zoo.cpp

#include "zoo.h"
#include "../cells/cell/cell.h"
#include "../cells/facilities/road/road.h"
#include "../cells/facilities/facility/facility.h"
#include "../cells/habitat/habitat.h"
#include "../cells/facilities/park/park.h"
#include "../cells//facilities/restaurant/restaurant.h"
#include "utility.h"
#include <time.h>
#include <list>
#include <set>
#include <stack>
#include <fstream>
#include <iostream>

using namespace std;


Zoo::Zoo(bool Auto, int w, int l): width(w), length(l) {
  cells = new Cell** [width];
  for (int i = 0; i < width; ++i) {
    cells[i] = new Cell* [length];
  }
  string line, dummy;
  if (Auto) { // automatis ctor dari file eksternal
    ifstream ifile("asset/map.txt");
    if (ifile.is_open()) {
      int i = 0;
      while (getline(ifile, line)) {
        for (int j = 0; j < length; ++j) {
          MakroNewCell(line[j]);
        }
        ++i;
      }
    }
    ifile.close();
  }
  else { // membaca input dari user
    for (int i = 0; i < width; ++i) {
      for (int j = 0; j < length; ++j) {
      	cin >> line[j];
        MakroNewCell(line[j]);
      }
    }
  }
  // caging
  cage_map = new int* [w];
  for (int i = 0; i < w; i++) {
    cage_map[i] = new int[l];
    for (int j = 0; j < l; j++) {
      cage_map[i][j] = -99;
    }
  } // alokasi memori cage_map
  int counter = 1; // counter cage ke-i
  for (int i = 0; i < w; i++) {
    for (int j = 0; j < l; j++) {
      if (cage_map[i][j] == -99) { // jika belum terisi
        char c = cells[i][j]->GetSymbol();
        if (c != 'W' && c != 'A' && c != 'L') {
        // jika bukan merupakan habitat akan diisi  0
          cage_map[i][j] = 0;
        }
        else { // habitat
          int array_i[4], array_j[4]; // array menyimpan posisi yang akan dirubah
          for (int k = 0; k < 4; k++) {
            array_i[k] = i, array_j[k] = j; // inisialisasi
          }
          bool cek = true; // boolean apakah bisa membentuk cage atau tidak
          cage_map[i][j] = counter; // dimasukkan ke cage counter
          srand(time(NULL));
          pair<int,int> movable[12]; // array pair jalan yang mungkin
          int ii, jj, i_temp = i, j_temp = j, count = 0;
          for (int times = 0; times < 3; times++) {
          // cukup 3x karena akan dibuat cage dengan
          // jumlah cell 4 terlebih dahulu
            for (int k = 0; k < 4; k++) { // ada 4 sel bersebelahan
              bool dummy = false;
              // atas
              if (k == 0 && i_temp != 0) {
                ii = i_temp - 1, jj = j_temp, dummy = true;
              }
              // kiri
              else if (k == 1 && j_temp != 0) {
                ii = i_temp, jj = j_temp - 1, dummy = true;
              }
              // bawah
              else if (k == 2 && i_temp != w - 1) {
                ii = i_temp + 1, jj = j_temp, dummy = true;
              }
              // kanan
              else if (k == 3 && j_temp != l - 1) {
                ii = i_temp, jj = j_temp + 1, dummy = true;
              }
              if (dummy) { // jika ada sel disebelahnya
                if (cells[ii][jj]->GetSymbol() == c &&
                    cage_map[ii][jj] == -99) {
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
            i_temp = movable[move].first;
            j_temp = movable[move].second;
            array_i[times] = i_temp; // pengisian posisi yang sudah diubah
            array_j[times] = j_temp;
            movable[move] = make_pair(movable[count-1].first,
                                      movable[count-1].second);
            cage_map[i_temp][j_temp] = counter;
            count--;
            if (times == 2) counter++; 
            // jika sudah selesai dengan cage dengan 4 cell counter ditambah
          }
          if (!cek) { 
          // jumlah cell tidak sampai 4, semua yang sudah diisi dikembalikan ke-99
            for (int k = 0; k < 4; k++) {
              cage_map[array_i[k]][array_j[k]] = -99;
            }
          }
        }
      }
    }
  }
  cage_nb = counter-1;
  // mengurus habitat yang belum masuk ke cage
  int change = -1; // banyak perubahan yang dilakukan
  while (change != 0) { // jika sudah tidak ada perubahan berhenti
    change = 0; // inisialisasi
    for (int i = 0; i < w; i++) {
      for (int j = 0; j < l; j++) {
        if (cage_map[i][j] == -99) { // masih belum terisi
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
              ii = i, jj = j + 1, dum = true;
            }
            if (dum) { // jika jalan mungkin
              if (cells[ii][jj]->GetSymbol() == cells[i][j]->GetSymbol() &&
                  cage_map[ii][jj] != -99) {
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
            cage_map[i][j] = cage_map[ii][jj];
            change++;
          }
        }
      }
    }
  }
  if (Auto) {
    // membaca animals dari animals.txt
    ifstream in("asset/animals.txt");
    if (in.is_open()) {
      while (getline(in, line)) {
        string id = "";
        int px = 0;
        int py = 0;
        int j = 0;
        int weight = 0;
        int decimal_weight = 0;
        // membaca id
        while (line[j] != '|') {
          id += line[j];
          j++;
        }
        j++;
        // membaca px
        while (line[j] != '|') {
          px = 10*px + line[j] - '0';
          j++;
        }
        j++;
        //membaca py
        while (j < (int)line.length() && line[j] != '|') {
          py = 10*py + line[j] - '0';
          j++;
        }
        if (line[j] == '|') {
          j++;
          while (line[j] != '.' && j < (int)line.length()) {
            weight = 10*weight + line[j] - '0';
            j++;
          }
          if (line[j] == '.') {
            int multiplier = 1;
            while (j < (int)line.length()) {
              multiplier *= 0.1;
              decimal_weight += multiplier*line[j];
              j++;
            }
          }
          weight += decimal_weight;
        }
        MakroNewAnimal(id,weight);
      }
    }
    in.close();
  }
  else{
    char option;
    do {
      cout << "Ingin menambah hewan lagi? (y/n)";
      cin >> option;
      if (option == 'Y' || option == 'y') {
        string id;
        char def_weight;
        int px;
        int py;
        int weight = 0;
        cout << "Input id hewan :";
        cin >> id;
        cout << "Input posisi x : (kolom ke-)";
        cin >> px;
        cout << "Input posisi y : (baris ke-)";
        cin >> py;
        cout << "Apakah ingin menggunakan berat default? (y/n)";
        cin >> def_weight;
        if (def_weight == 'N' || def_weight == 'N') {
          do{
            cout << "Input berat : (>0)";
            cin >> weight;
          } while (weight <= 0);
        }
        MakroNewAnimal(id,weight);
      }
    }while (option == 'Y' || option == 'y');
  }
}

Zoo::Zoo(const Zoo& z): width(z.width), length(z.length) {
  cells = new Cell** [width];
  for (int i = 0; i < width; i++) cells[i] = new Cell* [length];
  for (int i = 0; i < width; i++) {
    for (int j = 0; j < length; j++) {
      MakroNewCell((z.cells[i][j])->GetInitSymbol());
    }
  }
  for (int i = 0; i < width; i++) {
    for (int j = 0; j < length; j++) {
      cage_map[i][j] = z.cage_map[i][j];
    }
  }
  cage_nb = z.cage_nb;
  for (list<Animal*>::const_iterator it = z.animals.begin();
       it != z.animals.end(); ++it){
    int py = (*it)->GetPos().first, px = (*it)->GetPos().second;
    MakroNewAnimal((*it)->GetId(),(*it)->GetWeight());
  }
}

Zoo::~Zoo() {
  for (int i = 0; i < width; i++) delete [] cage_map[i];
  delete [] cage_map;
  for (int i = 0; i < width; i++) {
    for (int j = 0; j < length; j++) {
      delete cells[i][j];
    }
    delete [] cells[i];
  }
  delete [] cells;
}
  
Zoo& Zoo::operator=(const Zoo& z) {
  cout << "test 0";
  for (int i = 0; i < width; i++) {
    for (int j = 0; j < length; j++) {
      MakroNewCell((z.cells[i][j])->GetInitSymbol());
    }
  }
  cout << "test 1";
  for (int i = 0; i < width; i++) {
    for (int j = 0; j < length; j++) {
      cage_map[i][j] = z.cage_map[i][j];
    }
  }
  cage_nb = z.cage_nb;
  cout << "test 2";
  for (list<Animal*>::const_iterator it = z.animals.begin();
       it != z.animals.end(); ++it){
    int py = (*it)->GetPos().first, px = (*it)->GetPos().second;
    MakroNewAnimal((*it)->GetId(),(*it)->GetWeight());
  }
  cout << "test 3";
  return *this;
}

void Zoo::Display(int x1, int y1, int x2, int y2) {
  for (int i = x1; i <= x2; ++i) {
    for (int j = y1; j <= y2; ++j) {
      cells[i][j]->Render();
    }
    cout << endl;
  }
}

list<Animal*>::iterator Zoo::FindAnimal(pair<int,int> pos) {
  list<Animal*>::iterator it = animals.begin();
  list<Animal*>::iterator e = animals.end();
  --e;
  if (it != animals.end()) {
    while ((*it)->GetPos() != pos && it != e) {
    ++it;
    }
    if ((*it)->GetPos() == pos) {
      return it;
    } else {
      return animals.end();
    }
  } else {
    return it;
  }
  
}

void Zoo::AddAnimal(Animal* a) {
  int posx = a->GetPos().first;
  int posy = a->GetPos().second;
  if (posx >= 0 && posx < width && posy >= 0 && posy < length) {
    int cage = cage_map[posx][posy];
    // cek if habitat dlu
    set<char> hab = a->GetHabitat();
    set<string> compability = a->GetCompatible();
    if (FindAnimal(make_pair(posx,posy)) == animals.end()) {
      if (hab.find(cells[posx][posy]->GetSymbol()) != hab.end()) {
        bool compatible = true; 
        // cek apakah ada hewan yang tidak kompatible dengan hewan a
        int count = 0; // count animal yang ada di cage yang sama
        for (list<Animal*>::const_iterator it = animals.begin();
             it != animals.end(); ++it) {
          if (cage == cage_map[(*it)->GetPos().first][(*it)->GetPos().second]) {
            count++;
            if (compability.find(a->GetId()) == compability.end()) {
              compatible = false;
            }
          }
        }
        int max = 0;
        for (int i = 0; i < width; i++) {
          for (int j = 0; j < length; j++) {
            if (cage_map[i][j] == cage) {
              max++;
            }
          }
        }
        if (0.3*max >= (count+1) && compatible) { // masih muat cagenya
          animals.push_back(a);
          cells[posx][posy]->SetSymbol(a->GetLegend());
        }
      }
    }
  }
}

void Zoo::DelAnimal(string _id, int _number) {
  list<Animal*>::iterator it = animals.begin();
  list<Animal*>::iterator e = animals.end();
  --e;
  while ((*it)->GetId() != _id && (*it)->GetNumber() != _number && it != e) {
    ++it;
  }
  if ((*it)->GetId() == _id && (*it)->GetNumber() == _number) {
    delete (*it);
    animals.erase(it);
  }
  int posx = (*it)->GetPos().first;
  int posy = (*it)->GetPos().second;
  cells[posx][posy]->SetSymbol(cells[posx][posy]->GetInitSymbol());
}

void Zoo::DelAnimal(int x, int y) {
  if (FindAnimal(make_pair(x,y)) != animals.end()) {
    DelAnimal((*FindAnimal(make_pair(x,y)))->GetId(),
              (*FindAnimal(make_pair(x,y)))->GetNumber());
  }
}

float Zoo::GetTotalMeat() const {
  float sum = 0;
  for (list<Animal*>::const_iterator it = animals.begin();
       it != animals.end();
       ++it) {
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
  for (list<Animal*>::const_iterator it = animals.begin();
       it != animals.end();
       ++it) {
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
  if (it != animals.end()) {
    if (cells[pos.first][pos.second]->GetSekat(direction)) {
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
        if (FindAnimal(make_pair(i,j)) == animals.end()) {
          (*it)->Move(direction);
          cells[pos.first][pos.second]->
            SetSymbol(cells[pos.first][pos.second]->GetInitSymbol());
          cells[(*it)->GetPos().first][(*it)->GetPos().second]->
            SetSymbol((*it)->GetLegend());
        }
      }
    }
  }
}

void Zoo::MoveAnimal(string _id, int _number, int direction) {
  list<Animal*>::iterator it = animals.begin();
  list<Animal*>::iterator e = animals.end();
  --e;
  while ((*it)->GetId() != _id && (*it)->GetNumber() != _number && it != e) {
    ++it;
  }
  if ((*it)->GetId() == _id && (*it)->GetNumber() == _number) {
    MoveAnimal((*it)->GetPos(), direction);
  }
}

void Zoo::MoveAllAnimal() {
  srand(time(NULL));
  for (list<Animal*>::iterator it = animals.begin();
       it != animals.end();
       ++it) {
    MoveAnimal((*it)->GetPos(), (rand()%4));
  }
}

void Zoo::ToggleSekat(int i, int j, int direction) {
  if (i >= 0 && i < width && j >= 0 && j < length) {
    char c = cells[i][j]->GetInitSymbol();
    if (c == 'W' || c == 'L' || c == 'A') {
      switch (direction) {
        case 0:
          if (i-1 >= 0) {
            if (cage_map[i-1][j] == cage_map[i][j]) {
              cells[i][j]->ToggleSekat(0);
              cells[i-1][j]->ToggleSekat(3);
            }
          }
          break;
        case 1:
          if (j-1 >= 0) {
            if (cage_map[i][j-1] == cage_map[i][j]) {
              cells[i][j]->ToggleSekat(1);
              cells[i][j-1]->ToggleSekat(2);
            }
          }
          break;
        case 2:
          if (j+1 < length) {
            if (cage_map[i][j+1] == cage_map[i][j]) {
              cells[i][j]->ToggleSekat(2);
              cells[i][j+1]->ToggleSekat(1);
            }
          }
          break;
        case 3:
          if (i+1 < width) {
            if (cage_map[i+1][j] == cage_map[i][j]) {
              cells[i][j]->ToggleSekat(3);
              cells[i+1][j]->ToggleSekat(0);
            }
          }
          break;
      }
    }
  }
}

void Zoo::ToggleAllSekat() {
  for (int i = 0; i < width; ++i) {
    for (int j = 0; j < length; ++j) {
      for (int k = 0; k < 2; ++k) {
        ToggleSekat(i, j, k);
      }
    }
  }
}

void Zoo::Tour() {
  set<pair<int,int>> entrance;
  bool vis[width][length];
  for (int i = 0; i < width; ++i) {
    for (int j = 0; j < length; ++j) {
      if (cells[i][j]->GetSymbol() == 'N') {
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
  while (!found) {
    int i = dstack.top().first, j = dstack.top().second;
    vis[i][j] = true;
    if (cells[i][j]->GetSymbol() == 'X') {
      found = true;
      route.push_back(4);
    } else {
      char c;
      set<int> choice;
      if (i-1 >= 0) {
        c = cells[i-1][j]->GetSymbol();
        if (c == 'r' || c == 'X') {
          if (!vis[i-1][j]) {
            choice.insert(0);
          }
        }
      }
      if (j - 1 >= 0) {
        c = cells[i][j-1]->GetSymbol();
        if (c == 'r' || c == 'X') {
          if (!vis[i][j-1]) {
            choice.insert(1);
          }
        }
      }
      if (j + 1 < length) {
        c = cells[i][j+1]->GetSymbol();
        if (c == 'r' || c == 'X') {
          if (!vis[i][j+1]) {
            choice.insert(2);
          }
        }
      }
      if (i+1 < width) {
        c = cells[i+1][j]->GetSymbol();
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
  bool VisCage[cage_nb];
  for (int i = 0; i < cage_nb; ++i) {
    VisCage[i] = false;
  }
  while (!route.empty()) {
    if (i - 1 >= 0) {
      char c = cells[i-1][j]->GetInitSymbol();
      if (c == 'P' || c == 'R') {
        cells[i-1][j]->Interact();
      } else if (c == 'W' || c == 'L' || c == 'A') {
        if (!VisCage[cage_map[i-1][j]]) {
          InteractCage(make_pair(i - 1,j), cage_map[i-1][j]);
          VisCage[cage_map[i-1][j]] = true;
        }
      }
    }
    if (j - 1 >= 0) {
      char c = cells[i][j-1]->GetInitSymbol();
      if (c == 'P' || c == 'R') {
        cells[i][j-1]->Interact();
      } else if (c == 'W' || c == 'L' || c == 'A') {
        if (!VisCage[cage_map[i][j-1]]) {
          InteractCage(make_pair(i,j - 1), cage_map[i][j-1]);
          VisCage[cage_map[i][j-1]] = true;
        }
      }
    }
    if (j + 1 < length) {
      char c = cells[i][j+1]->GetInitSymbol();
      if (c == 'P' || c == 'R') {
        cells[i][j+1]->Interact();
      } else if (c == 'W' || c == 'L' || c == 'A') {
        if (!VisCage[cage_map[i][j+1]]) {
          InteractCage(make_pair(i,j + 1), cage_map[i][j+1]);
          VisCage[cage_map[i][j+1]] = true;
        }
      }
    }
    if (i + 1 < width) {
      char c = cells[i+1][j]->GetInitSymbol();
      if (c == 'P' || c == 'R') {
        cells[i+1][j]->Interact();
      } else if (c == 'W' || c == 'L' || c == 'A') {
        if (!VisCage[cage_map[i+1][j]]) {
          InteractCage(make_pair(i + 1,j), cage_map[i+1][j]);
          VisCage[cage_map[i+1][j]] = true;
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

void Zoo::InteractCage(pair<int,int> pos, int cage_number) {
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
    if (FindAnimal(make_pair(i,j)) != animals.end()) {
      (*FindAnimal(make_pair(i,j)))->Interact();
    }  
    if (i-1 >= 0) {
      if (cage_map[i-1][j] == cage_number) {
        if (!Vis[i-1][j]) {
          bqueue.push(make_pair(i - 1, j));
          Vis[i-1][j] = true;
        }
      }
    }
    if (j - 1 >= 0) {
      if (cage_map[i][j-1] == cage_number) {
        if (!Vis[i][j-1]) {
          bqueue.push(make_pair(i,j - 1));
          Vis[i][j-1] = true;
        }
      }
    }
    if (j+1 < length) {
      if (cage_map[i][j+1] == cage_number) {
        if (!Vis[i][j+1]) {
          bqueue.push(make_pair(i,j + 1));
          Vis[i][j+1] = true;
        }
      }
    }
    if (i+1 < width) {
      if (cage_map[i+1][j] == cage_number) {
        if (!Vis[i+1][j]) {
          bqueue.push(make_pair(i + 1,j));
          Vis[i+1][j] = true;
        }
      }
    }  
  }
}
