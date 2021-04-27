#include<iostream>
#include<string>
#include<math.h>

using namespace std;

int main(){
	string input3;
	getline(cin, input3);
	
	string N = "", B = "", S = "";
	for(int i = 0; i < input3.length(); i++){
		if(input3[i] != ' '){
			N += input3[i];
		} else break;
	}
	int lenN = N.length();
	
	for(int i = lenN+1; i < input3.length(); i++){
		if(input3[i] != ' '){
			B += input3[i];
		} else break;
	}
	int lenB = B.length();
	
	for(int i = lenN+lenB+2; i < input3.length(); i++){
		if(input3[i] != ' '){
			S += input3[i];
		}
	}
	cout << N << endl << B << endl << S << endl; //delete me please
	
	string S2 = "";
	int numB = stoi(B);
	if(numB > 0){
		while(numB >= S.length()){
			numB -= S.length();
		}	
	} else {
		while(abs(numB) >= S.length()){
			numB += S.length();
		}
	}
	
	if(numB > 0){
		for(int i = 0; i < S.length(); i++){
			if(i+ numB + 1 > S.length()){
				S2 += S[i];
			}
		}
		int temp = S2.length();
		for(int i = 0; i < S.length() - temp; i++){
			S2 += S[i];
		}
	} else if(numB < 0){
		for(int i = 0; i < S.length(); i++){
			if(i + numB >= 0){
				S2 += S[i];
			}
		}
		int temp = S2.length();
		for(int i = 0; i < S.length() - temp; i++){
			S2 += S[i];
		}
	} else S2 = S;
	
	
	cout << S2 << endl; //delete me please
	
	int numN = stoi(N);
	for(int i = 0; i < S.length(); i++){
		int change = abs(numN - 2 * i);
		while(change >= 4){
			change -= 4;
		}
		switch(S2[i]){
			case 'U':{
				if(change == 0) S2[i] = 'U';
				else if(change == 1) S2[i] = 'D';
				else if(change == 2) S2[i] = 'L';
				else S2[i] = 'R'; 
				break;
			}
			case 'D':{
				if(change == 0) S2[i] = 'D';
				else if(change == 1) S2[i] = 'L';
				else if(change == 2) S2[i] = 'R';
				else S2[i] = 'U'; 
				break;
			}
			case 'L':{
				if(change == 0) S2[i] = 'L';
				else if(change == 1) S2[i] = 'R';
				else if(change == 2) S2[i] = 'U';
				else S2[i] = 'D'; 
				break;
			}
			case 'R':{
				if(change == 0) S2[i] = 'R';
				else if(change == 1) S2[i] = 'U';
				else if(change == 2) S2[i] = 'D';
				else S2[i] = 'L'; 
				break;
			}
		}
	}
	cout << S2 << endl; //delete me please
	int x = 0, y = 0;
	for(int i = 0; i < S.length(); i++){
		switch(S2[i]){
			case 'U':{
				y += 1;
				break;
			}
			case 'D':{
				y -= 1;
				break;
			}
			case 'L':{
				x -= 1;
				break;
			}
			case 'R':{
				x += 1;
				break;
			}
		}
	}
	cout << x << endl << y << endl; //delete me please
	string cor;
	cor = cor + "(" + to_string(x) + "," + to_string(y) + ")";
	cout << cor; //delete me please
	
	return 0;
}
