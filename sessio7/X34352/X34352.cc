#include <iostream>
#include <string>
#include <map>
using namespace std;


void funcion(map<string, int>& M, const char& c)
{
	string s;
	cin >> s;
	
	if (c == 'a') M[s]++;
	
	else if (c == 'f') {	//print
		
		map<string, int>::iterator it = M.find(s);
		
		if (it == M.end()) cout <<0 <<endl;
		else cout << it->second << endl;
		
	}
	
}

int main()
{
	map<string, int> M;
	char c;
	
	while(cin >>c) funcion(M, c);
}
