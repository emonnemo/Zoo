/* Author		: Andika Kusuma / 13515033
 * File			: animal.cpp
 */

#include "animal.h"
#include <iostream>
using namespace std;


Animal::Animal(string _ID, int _id, char _legend, float _weight, float _eat, char _type, pair<int,int> _position){
	ID = _ID;
	id = _id;
	legend = _legend;
	weight = _weight;
	eat = _eat;
	type = _type;
	position.first = _position.first;
	position.second = _position.second;
}

Animal::Animal(const Animal& a){
	ID = a.ID;
	id = a.id;
	legend = a.legend;
	weight = a.weight;
	eat = a.eat;
	type = a.type;
	position = a.position;
	compatible = a.compatible;
	habitat = a.habitat;
}

Animal::~Animal(){

}

Animal& Animal::operator=(const Animal& a){
	ID = a.ID;
	id = a.id;
	legend = a.legend;
	weight = a.weight;
	eat = a.eat;
	type = a.type;
	position = a.position;
	compatible = a.compatible;
	habitat = a.habitat;
	return *this;
}

string Animal::GetID() const {
	return ID;
}

int Animal::Getid() const {
	return id;
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

char Animal::GetLegend() const {
	return legend;
}

set<char> Animal::GetHabitat() const{
	return habitat;
}

void Animal::SetPos(pair<int,int> _position){
	position.first=_position.first;
	position.second = _position.second;
}

void Animal::SetWeight(float _weight){
	weight = _weight;
}

void Animal::AddCompatible(string ID){
	compatible.insert(ID);
}

void Animal::DelCompatible(string ID){
	compatible.erase(ID);
}

set<string> Animal::GetCompatible() const {
	return compatible;
}

void Animal::Act() const{

}

void Animal::Interact() const {
	cout << "interact" << endl;
}

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
			position.first--;
			break;
		case 1:
			position.second--;
			break;
		case 2:
			position.second++;
			break;
		case 3:
			position.first++;
			break;
	}
}