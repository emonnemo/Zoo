#include <iostream>
#include <algorithm> //algorithm/string.hpp>
#include <string>
#include <string.h>
#include <fstream>

using namespace std;

int main(){
	ofstream file("hog.h");
	int legend, weight;
	char hab, type;
	string hewan, kode, act;
	cin >> legend;
	cin >> hab;
	cin >> type;
	cin >> hewan;
	cin >> kode;
	cin >> weight;
	cin >> act;
	locale loc;
	file << "//File " << hewan << ".h\n\n";
	file << "#ifndef " << hewan << "_H" << endl;
	file << "#define " << hewan << "_H" << endl;
	return 0;
}