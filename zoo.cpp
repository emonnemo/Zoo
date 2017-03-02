/* Author		: Andika Kusuma / 13515033
 * File			: zoo.cpp
 */

#include "zoo.h"
#include <iostream>

using namespace std;

Zoo::Zoo(bool Auto, int w = 20, int l = 20) : width(w), length(l){
	Cells = new Cell*[w];
	for(int i = 0; i < w; i++) Cells[i] = new Cell[l];
	Animals = new Animal[(int)0.3*w*l];
	cout << "zoo.ctor\n";
}
Zoo::Zoo(const Zoo& z) : width(z.width), length(z.length){
	Cells = new Cell*[width];
	for(int i = 0; i < width; i++) Cells[i] = new Cell[length];
	Animals = new Animal[(int)0.3*width*length];
	cout << "zoo.cctor\n";
}
Zoo::~Zoo(){
	delete [] Animals;
	for(int i = 0; i < width; i++) delete [] Cells[i];
	delete [] Cells;
	cout << "zoo.dtor\n";
}
Zoo Zoo::operator=(const Zoo z){
	cout << "zoo.opr=\n";
	return *this;
}
void Zoo::Render(){
	cout << "zoo.rnder\n";
}
void Zoo::AddAnimal(Animal a){
	cout << "zoo.add\n";
}
void Zoo::DelAnimal(int i){
	cout << "zoo.del\n";
}
int Zoo::GetWidth() const{
	return width;
}
int Zoo::GetLength() const{
	return length;
}