/* Author		: Andika Kusuma / 13515033
 * File			: zoo.cpp
 */

#include "zoo.h"
#include <iostream>

using namespace std;

Zoo::Zoo(bool Auto = 1, int w = 16, int l = 6):{
	width = w;
	length = l;
	Cells = new Cell**[width];
	for(int i = 0; i<width; ++i) Cells[i] = new Cell* [length];
	if (Auto){
		ifstream ifile ("map.txt");
		if (ifile.is_open()){
			string line;
			while(getline(ifile, line)){
				for (int j=0; i<length; ++j){
					switch (line[i]){
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
							Cells[i][j] = new Exit;
							break;
						case 'N':
							Cells[i][j] = new Entrance;
							break;
						case 'r':
							Cells[i][j] = new Road;
							break;
						case 'R':
							Cells[i][j] = new Restaurant;
							break;
						case 'P':
							Cells[i][j] = new Park;
							break;
					}
				}
			}
		}
	}
}

Zoo::Zoo(const Zoo& z) : width(z.width), length(z.length){
	Cells = new Cell**[width];
	for(int i = 0; i < width; i++) Cells[i] = new Cell*[length];
}
Zoo::~Zoo(){
	for(int i = 0; i < width; i++) delete [] Cells[i];
	delete [] Cells;
	cout << "zoo.dtor\n";
}
Zoo Zoo::operator=(const Zoo z){
	for(int i = 0; i < width; i++){
		for(int j = 0; j < length; j++){
			Cells[i][j] = z.Cells[i][j];
		}
	}
	cout << "zoo.opr=\n";
	return *this;
}
void Zoo::Render(){
	for (int i=0; i<width; ++i){
		for (int j=0; j<length; ++j){
			cout << Cells.symbol;
		}
		cout << endl;
	}
}
void Zoo::AddAnimal(Animal a){
	Animals.push_back(a);
}
void Zoo::DelAnimal(int id){
	Animals.remove_if(ID = id);
}

int Zoo::GetWidth() const{
	return width;
}
int Zoo::GetLength() const{
	return length;
}