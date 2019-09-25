#include <list>
#include <iostream>
using namespace std;


int control_max(const list<int>& l) {
	
	list<int>::const_iterator it = l.begin();
	int max = *it;
	
	for (it=l.begin(); it != l.end(); ++it) if (max < (*it)) max = *it;
	
	return max;
}

int control_min(const list<int>& l) {
	
	list<int>::const_iterator it = l.begin();
	int min = *it;
	
	for (it=l.begin(); it != l.end(); ++it) if (min > *it) min = *it;
	
	return min;
}

bool esta(const list<int>& l, int n) {
	
	list<int>::const_iterator it;
	for (it=l.begin(); it != l.end(); ++it) if (*it == n) return true;
	
	return false;
}

int main() {
	
	list<int> l;
	list<int>::iterator it;
	
	int inst, n, max = 0, min = 0;
	double mitj = 0.0;
	cin >>inst >>n;
	
	while (inst != 0 and n != 0) {
		
		if (inst == -1) {	//numero valido
			
			if (not l.empty()) {
					
				mitj = ((double(mitj)*l.size()) + n)/(l.size()+1);
					
				if (n > max) max = n;
				else if (n < min) min = n;
				
			}	
			
			if (l.empty()) {	
				max = n;
				min = n;
				mitj = n;
			}
			
			it = l.end();
			l.insert(it, n);

		}
		
		else if (inst == -2) {	//elminar numero valido
			if (esta(l, n)) {
				
				list<int>::iterator it2 = l.begin(); 
				
				int count = 0;
				while (it2 != l.end() and count == 0) {
					if (*it2 == n) {
						it2 = l.erase(it2);
						++count;
					}
					else ++it2;
				}
			
				if (not l.empty()) {
					
					mitj = (mitj*(l.size()+1) - (n))/l.size();
					
					if (not esta(l, n)) {
						if (n == max) max = control_max(l);
						if (n == min) min = control_min(l);
					}
				}
			}
		}
		
		if (l.empty()) cout <<0 <<endl;
		else cout <<min <<' ' <<max <<' ' <<mitj <<endl;
		
		cin >>inst >>n;
	}
}
