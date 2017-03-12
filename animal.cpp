/* Author		: Andika Kusuma / 13515033
 * File			: animal.cpp
 */

#include "animal.h"
#include <iostream>
using namespace std;


Animal::Animal(string _ID, int _id, float _weight, float _eat, char _type, pair<int,int> _position){
	ID = _ID;
	id = _id;
	weight = _weight;
	eat = _eat;
	type = _type;
	position.first = _position.first;
	position.second = _position.second;
}

Animal::Animal(const Animal& a){
	ID = a.ID;
	id = a.id;
	weight = a.weight;
	eat = a.eat;
	type = a.type;
	position = a.position;
}

Animal::~Animal(){

}

Animal& Animal::operator=(const Animal& a){
	ID = a.ID;
	id = a.id;
	weight = a.weight;
	eat = a.eat;
	type = a.type;
	position = a.position;
	return *this;
}

string Animal::GetID() const {
	return ID;
}

int Animal::GetWeight() const {
	return weight;
}

float Animal::GetEat() const {
	return eat;
}

pair<int,int> Animal::GetPos() const {
	return position;
}

char Animal::GetType() const {
	return type;
}

void Animal::SetPos(pair<int,int> _position){
	position.first=_position.first;
	position.second = _position.second;
}

void Animal::SetWeight(float _weight){
	weight = _weight;
}

void Animal::Act() const{

}

void Animal::Interact() const {}

void Animal::Description(string a) const{
	cout << "This is a(n) " << a << " called " << ID << "-";
	if (id < 10){
		cout << "0"; 
	}
	cout << id	<< ". It weights " << weight << " kilograms. It eats " << eat*weight << " kilograms of " << (type=='K'?"meats":(type=='O'?"meats and vegetables":"vegetables")) << endl;
}

void Animal::Move(int direction){
	switch(direction){
		case 0:
			position.second--;
			break;
		case 1:
			position.first--;
			break;
		case 2:
			position.first++;
			break;
		case 3:
			position.second++;
			break;
	}
}