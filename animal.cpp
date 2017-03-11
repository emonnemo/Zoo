/* Author		: Andika Kusuma / 13515033
 * File			: animal.cpp
 */

#include "animal.h"

Animal::Animal(){

}

Animal::Animal(const Animal& a){

}

Animal& Animal::operator=(const Animal& a){
	ID = a.ID;
	weight = a.weight;
	type = a.type;
	return *this;
}

int Animal::GetID() const {
	return ID;
}

int Animal::GetWeight() const {
	return weight;
}

char Animal::GetType() const {
	return type;
}

void Animal::SetID(int _ID){
	ID = _ID;
}

void Animal::SetWeight(int _weight){
	weight = _weight;
}

void Animal::SetType(char _type){
	type = _type;
}

