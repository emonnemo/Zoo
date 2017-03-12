/* Author		: Andika Kusuma / 13515033
 * File			: zoo.cpp
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
#include <fstream>
#include <iostream>

using namespace std;


Zoo::Zoo(bool Auto, int w , int l) : width(w), length(l) {
	Cells = new Cell**[width];
	for(int i = 0; i<width; ++i) Cells[i] = new Cell* [length];
	string line;
	if (Auto){
		ifstream ifile("map.txt");
		if (ifile.is_open()){
			int i = 0;
			while(getline(ifile, line)){
				for (int j=0; j<length; ++j){
					switch (line[j]){
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
	else{
		for (int i = 0; i < width; ++i){
			getline(cin, line);
			for(int j = 0; j < length; ++j){
				switch (line[j]){
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
	for(int i = 0; i < w; i++){
		CageM[i] = new int[l];
		for(int j = 0; j < l; j++){
			CageM[i][j] = -99;
		}
	}
	int counter = 1;
	for(int i = 0; i < w; i++){
		for(int j = 0; j < l; j++){
			if(CageM[i][j] == -99){
				char c = Cells[i][j]->GetSymbol();
				if(c != 'W' && c != 'A' && c != 'L'){
					CageM[i][j] = 0;
				}
				else{
					int ai[4], aj[4];
					for(int kk = 0; kk < 4; kk++){
						ai[kk] = i, aj[kk] = j;
					}
					bool cek = true;
					CageM[i][j] = counter;
					srand(time(NULL));
					pair<int,int> movable[12];
					int ii, jj, icek = i, jcek = j, count = 0;
					for(int times = 0; times < 3; times++){
						for(int k = 0; k < 4; k++){
							bool dum = false;
							if(k == 0 && icek != 0) ii = icek - 1, jj = jcek, dum = true;
							else if(k == 1 && jcek != 0) ii = icek, jj = jcek - 1, dum = true;
							else if(k == 2 && icek != w - 1) ii = icek + 1, jj = jcek, dum = true;
							else if(k == 3 && jcek != l - 1) ii = icek , jj = jcek + 1, dum = true;
							if(dum){
								if(Cells[ii][jj]->GetSymbol() == c && CageM[ii][jj] == -99){
									movable[count] = make_pair(ii,jj);
									count++;
								}
							}
						}
						if(count == 0){
							cek = false;
							break;
						}
						int move = rand() % count;
						icek = movable[move].first;
						jcek = movable[move].second;
						ai[times] = icek;
						aj[times] = jcek;
						movable[move] = make_pair(movable[count-1].first, movable[count-1].second);
						CageM[icek][jcek] = counter;
						count--;
						if(times == 2) counter++;
					}
					if(!cek){
						for(int k = 0; k < 4; k++){
							CageM[ai[k]][aj[k]] = -99;
						}
					}
				}
			}
		}
	}
	int change = -1;
	while (change != 0){
		change = 0;
		for(int i = 0; i < w; i++){
			for(int j = 0; j < l; j++){
				if(CageM[i][j] == -99){
					pair<int,int> movable[4];
					int count = 0, ii, jj;
					for(int k = 0; k < 4; k++){
						bool dum = false;
						if(k == 0 && i != 0) ii = i - 1, jj = j, dum = true;
						else if(k == 1 && j != 0) ii = i, jj = j - 1, dum = true;
						else if(k == 2 && i != w - 1) ii = i + 1, jj = j, dum = true;
						else if(k == 3 && j != l - 1) ii = i , jj = j + 1, dum = true;
						if(dum){
							if(Cells[ii][jj]->GetSymbol() == Cells[i][j]->GetSymbol() && CageM[ii][jj] != -99){
								movable[count] = make_pair(ii,jj);
								count++;
							}
						}
					}
					if(count > 0){
						int move = rand() % count;
						ii = movable[move].first;
						jj = movable[move].second;
						CageM[i][j] = CageM[ii][jj];
						change++;
					}
				}
			}
		}
	}
}

Zoo::Zoo(const Zoo& z) : width(z.width), length(z.length){
	Cells = new Cell**[width];
	for(int i = 0; i < width; i++) Cells[i] = new Cell*[length];
	for(int i = 0; i < width; i++){
		for(int j = 0; j < length; j++){
			switch ((z.Cells[i][j])->GetInitSymbol()){
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
	for(int i = 0; i < width; i++){
		for(int j = 0; j < length; j++){
			CageM[i][j] = z.CageM[i][j];
		}
	}
}
Zoo::~Zoo(){
	for(int i = 0; i < width; i++) delete [] CageM[i];
	delete [] CageM;
	for(int i = 0; i < width; i++){
		for(int j = 0; j < length; j++){
			delete Cells[i][j];
		}
		delete [] Cells[i];
	}
	delete [] Cells;
}
Zoo& Zoo::operator=(const Zoo& z){
	for(int i = 0; i < width; i++){
		for(int j = 0; j < length; j++){
			switch ((z.Cells[i][j])->GetInitSymbol()){
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
	return *this;
}

void Zoo::Display(int x1, int y1, int x2, int y2){
	for (int i=x1; i<=x2; ++i){
		for (int j=y1; j<=y2; ++j){
			cout << Cells[i][j]->GetSymbol();
		}
		cout << endl;
	}
}
void Zoo::AddAnimal(Animal& a){
	int posx = a.GetPos().first;
	int posy = a.GetPos().second;
	int cage = CageM[posx][posy];
	// cek if habitat dlu
	set<char> hab = a.GetHabitat();
	if(hab.find(Cells[posx][posy]->GetSymbol()) != hab.end()){
		int count = 0; // count animal yang ada di cage yang sama
		for(list<Animal>::const_iterator it = Animals.begin(); it != Animals.end(); ++it){
			if(cage == CageM[it->GetPos().first][it->GetPos().second]){
				count++;
			}
		}
		int max = 0;
		for(int i = 0; i < width; i++){
			for(int j = 0; j < length; j++){
				if(CageM[i][j] == cage){
					max++;
				}
			}
		}
		if(0.3*max>=(count+1)){ // masih muat cagenya
			Animals.push_back(a);
			Cells[posx][posy]->SetSymbol(a.GetLegend());
		}
	}
}

void Zoo::DelAnimal(string _ID, int _id){
	list<Animal>::iterator it = Animals.begin();
	list<Animal>::iterator e = Animals.end();
	--e;
	while (it->GetID() != _ID && it->Getid() != _id && it != e){
		++it;
	}
	if (it->GetID() == _ID && it->Getid() == _id){
		Animals.erase(it);
	}
}

int Zoo::GetWidth() const{
	return width;
}
int Zoo::GetLength() const{
	return length;
}

float Zoo::GetTotalMeat() const{
	float sum = 0;
	for(list<Animal>::const_iterator it = Animals.begin(); it != Animals.end(); ++it){
		if(it->GetType() == 'K'){
			sum += it->GetWeight() * it->GetEat();
		}
		else if(it->GetType() == 'O'){
			sum += 0.5 * it->GetWeight() * it->GetEat();
		}
	}
	return sum;
}

float Zoo::GetTotalVegetables() const{
	float sum = 0;
	for(list<Animal>::const_iterator it = Animals.begin(); it != Animals.end(); ++it){
		if(it->GetType() == 'H'){
			sum += it->GetWeight() * it->GetEat();
		}
		else if(it->GetType() == 'O'){
			sum += 0.5 * it->GetWeight() * it->GetEat();
		}
	}
	return sum;
}	