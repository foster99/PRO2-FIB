#include <iostream>
#include <queue>
using namespace std;

void max_min(const queue<int>& c, int& max, int& min) {
	
	
}


int main() {
	
	int n;
	cin >> n;
	
	queue<int> c;
	int min = -1002, max = 1001, media = 0;
	
	while (-1001 <= n and n <= 1000 ) {
		
		if (not c.empty() and n == -1001) {
			c.pop();
		}
		else {
			c.push(n);
			suma += n;
		}
		
		cin >> n;
	}
	
	
}
