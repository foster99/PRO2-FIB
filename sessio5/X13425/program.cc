#include "CuaIOParInt.hh"

int main() {
	
	queue<ParInt> c;
	llegirCuaParInt(c);
	
	queue<ParInt> a, b;
	int countA = 0, countB = 0;
	
	while (not c.empty()) {
		
		if (countA <= countB) {
			a.push(c.front());
			countA += c.front().segon();
		}
		
		else {
			b.push(c.front());
			countB += c.front().segon();
		}
		
		c.pop();
	}
	
	escriureCuaParInt(a);
	cout << endl;
	escriureCuaParInt(b);
}
