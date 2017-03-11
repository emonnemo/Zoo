#include <iostream>
using namespace std;

class A{
public:
	friend class C;
	void terbang(){
		cout << "terbang\n";
	}
private:
	int x;
	int y;
};

class B{
public:
	friend class C;
	void jalan(){
		cout << "jalan\n";
	}
private:
	int x;
	int y;
};

class C{
public:
	void cc(){
		A a;
		cout << a.x;
	}
};

int main(){
	C c;
	c.cc();
	return 0;
}