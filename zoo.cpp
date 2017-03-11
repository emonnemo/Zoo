/* Author		: Andika Kusuma / 13515033
 * File			: zoo.cpp
 */

#include "zoo.h"
#include <list>
#include <iostream>

using namespace std;

Zoo::Zoo(bool Auto, int w = 20, int l = 20) : width(w), length(l){
	Cells = new Cell**[w];
	for(int i = 0; i < w; i++) Cells[i] = new Cell*[l];
	cout << "zoo.ctor\n";
}
Zoo::Zoo(const Zoo& z) : width(z.width), length(z.length){
	Cells = new Cell**[width];
	for(int i = 0; i < width; i++) Cells[i] = new Cell*[length];
	cout << "zoo.cctor\n";
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
			cout << Cells[i][j]->GetSymbol();
		}
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