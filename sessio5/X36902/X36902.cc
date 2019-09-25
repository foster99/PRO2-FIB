#include <iostream>
#include <stack>
using namespace std;

bool abierto(char c) {
	
	if (c == '(') return true;
	return (c == '[');
} 

char opuesto(char c) {
	
	if (c == ')') return '(';
	return '[';	
}

int main() {
	
	stack<char> s;
	char x;
	bool control = true;
	
	cin >> x;
	
	while (x != '.') {
		
		if (abierto(x)) s.push(x);
		else if (s.empty()) control = false;
		else if (control and s.top() == opuesto(x)) s.pop();
		cin >> x;
	}
	
	if (s.empty() and control) cout << "Correcte" << endl;
	else cout << "Incorrecte" << endl;
}
