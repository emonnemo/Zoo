#include <fstream>
#include <iostream>
#include <string>
using namespace std;
int main(){
	char **b;
	b = new char * [100];
	b[0] = (char *)"animal.h";
	b[1] = (char *)"animal.cpp";
	b[2] = (char *)"cell.h";
	b[3] = (char *)"cell.cpp";
	b[4] = (char *)"facility.h";
	b[5] = (char *)"facility.cpp";
	b[6] = (char *)"habitat.h";
	b[7] = (char *)"habitat.cpp";
	b[8] = (char *)"park.h";
	b[9] = (char *)"park.cpp";
	b[10] = (char *)"restaurant.h";
	b[11] = (char *)"restaurant.cpp";
	b[12] = (char *)"road.h";
	b[13] = (char *)"road.cpp";
	b[14] = (char *)"zoo.h";
	b[15] = (char *)"zoo.cpp";
	b[16] = (char *)"realAnimals/bat.h";
	b[17] = (char *)"realAnimals/bat.cpp";
	b[18] = (char *)"realAnimals/cockatoo.h";
	b[19] = (char *)"realAnimals/cockatoo.cpp";
	b[20] = (char *)"realAnimals/colugo.h";
	b[21] = (char *)"realAnimals/colugo.cpp";
	b[22] = (char *)"realAnimals/crane.h";
	b[23] = (char *)"realAnimals/crane.cpp";
	b[24] = (char *)"realAnimals/draco_lizard.h";
	b[25] = (char *)"realAnimals/draco_lizard.cpp";
	b[26] = (char *)"realAnimals/dolphin.h";
	b[27] = (char *)"realAnimals/dolphin.cpp";
	b[28] = (char *)"realAnimals/dugong.h";
	b[29] = (char *)"realAnimals/dugong.cpp";
	b[30] = (char *)"realAnimals/eagle.h";
	b[31] = (char *)"realAnimals/eagle.cpp";
	b[32] = (char *)"realAnimals/elephant.h";
	b[33] = (char *)"realAnimals/elephant.cpp";
	b[34] = (char *)"realAnimals/goose.h";
	b[35] = (char *)"realAnimals/goose.cpp";
	b[36] = (char *)"realAnimals/hippopotamus.h";
	b[37] = (char *)"realAnimals/hippopotamus.cpp";
	b[38] = (char *)"realAnimals/hog.h";
	b[39] = (char *)"realAnimals/hog.cpp";
	b[40] = (char *)"realAnimals/hummingbird.h";
	b[41] = (char *)"realAnimals/hummingbird.cpp";
	b[42] = (char *)"realAnimals/lion.h";
	b[43] = (char *)"realAnimals/lion.cpp";
	b[44] = (char *)"realAnimals/macaque.h";
	b[45] = (char *)"realAnimals/macaque.cpp";
	b[46] = (char *)"realAnimals/moray_eel.h";
	b[47] = (char *)"realAnimals/moray_eel.cpp";
	b[48] = (char *)"realAnimals/owl.h";
	b[49] = (char *)"realAnimals/owl.cpp";
	b[50] = (char *)"realAnimals/pelican.h";
	b[51] = (char *)"realAnimals/pelican.cpp";
	b[52] = (char *)"realAnimals/penguin.h";
	b[53] = (char *)"realAnimals/penguin.cpp";
	b[54] = (char *)"realAnimals/robin.h";
	b[55] = (char *)"realAnimals/robin.cpp";
	b[56] = (char *)"realAnimals/sugar_glider.h";
	b[57] = (char *)"realAnimals/sugar_glider.cpp";
	b[58] = (char *)"realAnimals/shark.h";
	b[59] = (char *)"realAnimals/shark.cpp";
	b[60] = (char *)"realAnimals/turtle.h";
	b[61] = (char *)"realAnimals/turtle.cpp";
	b[62] = (char *)"realAnimals/whale.h";
	b[63] = (char *)"realAnimals/whale.cpp";
	b[64] = (char *)"realAnimals/wolf.h";
	b[65] = (char *)"realAnimals/wolf.cpp";
	b[66] = (char *)"realAnimals/zebra.h";
	b[67] = (char *)"realAnimals/zebra.cpp";
	b[68] = (char *)"main.cpp";
	b[69] = (char *)"renderable.h";
	b[70] = (char *)"renderable.cpp";

	for(int j = 0; j <= 67; j++){

		char* a;
		a = new char[30];
		a = b[j];
		ifstream ifile(a);
		ofstream o("tes.txt");
		string line;
		while (getline(ifile,line)){
			int i = 0;
			while(line[i] != '\0'){
				if(line[i] == '\t'){
					o << "  ";
				}
				else o << line[i];
				i++;
			}
			o << '\n';
		}
		ifile.close();
		o.close();


		ofstream o2(a);
		ifstream i2("tes.txt");
		while (getline(i2,line)){
			int i = 0;
			while(line[i] != '\0'){
				o2 << line[i];
				i++;
			}
			o2 << '\n';
		}
		i2.close();
		o2.close();

	}
	return 0;
}