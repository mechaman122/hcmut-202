#include<iostream>
#include<string>
#include<iomanip>
#include<math.h>

using namespace std;

int main(){
	char a,b,c;
	while (true){
		cin >> a >> b >> c;
		if(a == '*' && b == '*' && c == '*') break;
		else if(b - a <= 1 && c - b <= 1 && b >= a && c >= b) cout << "true" << endl; 
		else cout << "false" << endl;
	} 
}
