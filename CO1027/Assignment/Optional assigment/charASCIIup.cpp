#include<iostream>
#include<string>
#include<iomanip>
#include<math.h>

using namespace std;

int main(){
	char a,b,c;
	while (true){
		cin >> a >> b >> c;
		if(b - a == 1 && c - b == 1){
			cout << "true" << endl;
		} else if(a == '*' && b == '*' && c == '*') break; 
		else cout << "false" << endl;
	} 
}
