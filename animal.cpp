/* Author		: Andika Kusuma / 13515033
 * File			: animal.cpp
 */

#include "animal.h"
#include <iostream>
using namespace std;


Animal::Animal(string _ID, int _weight, char _type){
	ID = _ID;
	weight = _weight;
	type = _type;
}

Animal::Animal(const Animal& a){
	ID = a.ID;
	weight = a.weight;
	type = a.type;
}

Animal::~Animal(){

}

Animal& Animal::operator=(const Animal& a){
	ID = a.ID;
	weight = a.weight;
	type = a.type;
	return *this;
}

string Animal::GetID() const {
	return ID;
}

int Animal::GetWeight() const {
	return weight;
}

char Animal::GetType() const {
	return type;
}

void Animal::SetID(string _ID){
	ID = _ID;
}

void Animal::SetWeight(int _weight){
	weight = _weight;
}

void Animal::SetType(char _type){
	type = _type;
}

void Animal::Print(){
	cout << "This is " << "tiger " << ID << ". It is " << weight << " kilograms. It eats " << (type=='K'?"meats":(type=='O'?"meats and vegetables":"vegetables"))
	<< ".\n";
}