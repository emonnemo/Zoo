/* Author		: Andika Kusuma / 13515033
 * File			: animal.cpp
 */

#include "animal.h"
#include <iostream>
using namespace std;


Animal::Animal(string _ID, float _eat, int _weight, char _type){
	ID = _ID;
	eat = _eat;
	weight = _weight;
	type = _type;
}

Animal::Animal(const Animal& a){
	ID = a.ID;
	eat = _eat;
	weight = a.weight;
	type = a.type;
	x = a.x;
	y = y.x;
}

Animal::~Animal(){

}

Animal& Animal::operator=(const Animal& a){
	ID = a.ID;
	eat = a.eat;
	weight = a.weight;
	type = a.type;
	x = a.x;
	y = a.y;
	return *this;
}

string Animal::GetID() const {
	return ID;
}

int Animal::GetWeight() const {
	return weight;
}

void Animal::SetWeight(int _weight){
	weight = _weight;
}

void Animal::SetType(char _type){
	type = _type;
}

void Animal::Print(){
	cout << "This is " << ID << "-";
	if (id < 10){
		cout << '0'; 
	}
	cout id	<< ". It weights " << weight << " kilograms. It eats " << eat*weight << " kilograms of" << (type=='K'?"meats":(type=='O'?"meats and vegetables":"vegetables")) << endl;
}