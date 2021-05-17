#include<iostream>
#include<string>
#include<math.h>

using namespace std;

int main(){
	//Khoi tao mang dau vao
	int n;
	cin >> n;
	string input6[n];
	for (int l = 0; l < n; l++){
		cin >> input6[l];
	} 
	
	cout << endl;
	// tao mang temp luu tru gia tri cua tung nguoi
	int temp[26];
	for(int l = 0; l < 26; l++) temp[l] = 0;
	// xet tung chuoi, xet tung phan tu
	for(int i = 0; i < n; i++){
		string a = input6[i];
		for(int j = 0; j < 6; j++){
			for(int m = 65; m <= 90; m++){
				if(m == (int)a[j]) temp[m - 65] += (6 - j);
			}
		}
	}
	
	for(int l = 0; l < 26; l++) cout << temp[l] << " ";
	cout << endl;
	
	string result = "";
	for(int i = 0; i < 3; i++){
		int max = 0;
		for(int j = 0; j < 26; j++){
			if(max < temp[j]) max = temp[j];
		}
		for(int i = 0; i < 26; i++){
			if(temp[i] == max){
				result += (char)(i + 65);
				break;
			} 
		}
		for(int i = 0; i < 26; i++){
			if(temp[i] == max){
				temp[i] = 0;
				break;
			}
		}
	}
	cout << result << endl;
	return 0;
}
