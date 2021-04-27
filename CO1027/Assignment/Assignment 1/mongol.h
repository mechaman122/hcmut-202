//
// Created by Nhan Nguyen on 01/03/2021.
//
#ifndef MONGOL_H
#define MONGOL_H

// The library here is concretely set, students are not allowed to include any other libraries.

string readyForBattle(const string ID[], const int NID, const string input1[], const int N1);
int decode(const string A, const string B);
string findRoute(const string ID[], const int NID, const string input3[]);
string decodeVfunction(const string A, const string B);
string findBetrayals(const string input5[], const int N5);
int attack(const string input6[]);
int calculateNoOfWaitingDays(const string input7Str, const string input7Matrix, const int N7);

////////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER HERE
////////////////////////////////////////////////////////////////////////////

string readyForBattle(const string ID[], const int NID, const string input1[], const int N1)
{
    return "You can remove this return";
}
int decode(const string A, const string B)
{
    int count = 0;
    bool dif = false;
	for(int i = 0; i < (A.size()-B.size()+1); i++){
		if(A[i] == B[0]){
			dif = false;
			for(int j = 0; j < B.size(); j++){
				if(B[j] != A[i+j]){
					dif = true;
					break;
				}
			}
			if(dif == false) count ++;
		}
	}
    return count;
}
string findRoute(const string input3)
{
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
	string cor;
	cor = cor + "(" + to_string(x) + "," + to_string(y) + ")";
	return cor;
}
string decodeVfunction(const string A, const string B)
{
    int a1 = 0, b1 = 0;
	for(int i = 0; i < A.length(); i++){
		if(A[i] == 'V') a1++;
	}
	for(int i = 0; i < B.length(); i++){
		if(B[i] == 'V') b1++;
	}
	int total = a1 * b1;
	string C = "";
	for(int i = 0; i < total; i++){
		C += "V(";
	}
	C += "0";
	for(int i = 0; i < total; i++){
		C += ")";
	}
	return C;
}
string findBetrayals(const string input5[], const int N5)
{
    // tao mang temp luu tru gia tri cua tung nguoi
	int temp[26];
	for(int l = 0; l < 26; l++) temp[l] = 0;
	// xet tung chuoi, xet tung phan tu
	for(int i = 0; i < N5; i++){
		string a = input5[i];
		for(int j = 0; j < a.length(); j++){
			for(int m = 65; m <= 90; m++){
				if(m == (int)a[j]) temp[m - 65] += (6 - j);
			}
		}
	}
	string result = "";
	for(int i = 0; i < 3; i++){
		int max = 0;
		for(int j = 0; j < 26; j++){
			if(max < temp[j]) max = temp[j];
		}
		for(int l = 0; l < 26; l++){
			if(temp[l] == max){
				result += (char)(l + 65);
				break;
			} 
		}
		for(int x = 0; x < 26; x++){
			if(temp[x] == max){
				temp[x] = 0;
				break;
			}
		}
	}
	result += "\0";
	return result;
	
}
int attack(const string input6[])
{
    int temp[10]; //mang luu tru so cac so 0 trong phan tu
	for(int i = 0; i < 10; i++) temp[i] = 0;
	for(int i = 0; i < 10; i++){ //xet hang, xet phan tu
		string a = input6[i];
		for(int j = 0; j < a.length(); j++){
			if(a[j] == '0') temp[i]++;
		}
	}
	
	for(int i = 0; i < 10; i++){ //xet hang, xet phan tu
		string a = input6[i];
		for(int j = 0; j < a.length(); j++){
			if(a[j] == '2') temp[i] = 0; //loai bo cac hang co chua so 2
		}
	}
	
	bool found = false;
	for(int i = 0; i < 10; i++){
		if(temp[i] != 0){
			found = true;
			break;
		}
	}
	
	if(found == false) return -1;
	else {
		int max = 0;
		int place = 0;
		for(int i = 0; i < 10; i++){
			if(max <= temp[i]){
				max = temp[i];
				place = i;
			}
		}
		return place;
	}
}
int calculateNoOfWaitingDays(const string input7Str, const string input7Matrix[], const int k)
{
    return -1;
}

#endif /* MONGOL_H */
