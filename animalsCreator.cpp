#include <fstream>
#include <iostream>
using namespace std;

int main(){
	char ID[3];
	int n=1,x,y,w;
	fstream f("animals3.txt",fstream::out);
	do {
		cout << "n = ";
		cin >> n;
		if (n>0) {
			cout << "ID: ";
			cin >> ID;
			for (int i=1;i<=n;i++) {
				cout <<endl << i << endl;
				f << ID << "|";
				cout << "Posisi x: ";
				cin >> x;
				f << x << "|";
				cout << "Posisi y: ";
				cin >> y;
				f << y << endl;
			}
		}
		cout << endl;
	} while(n>0);
	f.close();
	cout << "Input done. You're the god of NiMitz Zoo!"<<endl;
	return 0;
}