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
	if (Auto){
		ifstream ifile("map.txt");
		if (ifile.is_open()){
			string line;
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
		for(int i = 0; i < w; i++){
			for(int j = 0; j < l; j++){
				Cells[i][j] = new Road();
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
					CageM[i][j] = counter;
					srand(time(NULL));
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
}
Zoo::~Zoo(){
	for(int i = 0; i < width; i++) delete [] Cells[i];
	delete [] Cells;
	cout << "zoo.dtor\n";
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
	Animals.push_back(a);
}
void Zoo::DelAnimal(int id){

}

int Zoo::GetWidth() const{
	return width;
}
int Zoo::GetLength() const{
	return length;
}