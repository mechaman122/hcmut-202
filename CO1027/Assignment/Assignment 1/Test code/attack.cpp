#include<iostream>
#include<string>
#include<math.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	string input6[n];
	for(int i = 0; i < n; i++) cin >> input6[i];
	
	int temp[n]; //mang luu tru so cac so 0 trong phan tu
	for(int i = 0; i < n; i++) temp[i] = 0;
	for(int i = 0; i < n; i++){ //xet hang, xet phan tu
		string a = input6[i];
		for(int j = 0; j < a.length(); j++){
			if(a[j] == '0') temp[i]++;
		}
	}
	for(int i = 0; i < n; i++) cout << temp[i] << " "; //co the bo hang nay
	cout << endl;
	
	for(int i = 0; i < n; i++){ //xet hang, xet phan tu
		string a = input6[i];
		for(int j = 0; j < a.length(); j++){
			if(a[j] == '2') temp[i] = 0; //loai bo cac hang co chua so 2
		}
	}
	
	for(int i = 0; i < n; i++) cout << temp[i] << " "; //co the bo hang nay
	cout << endl;
	
	bool found = false;
	for(int i = 0; i < n; i++){
		if(temp[i] != 0){
			found = true;
			break;
		}
	}
	
	if(found == false) cout << "-1";
	else {
		int max = 0;
		int place = 0;
		for(int i = 0; i < n; i++){
			if(max <= temp[i]){
				max = temp[i];
				place = i;
			}
		}
		cout << place;
	}
	
	return 0;
}
