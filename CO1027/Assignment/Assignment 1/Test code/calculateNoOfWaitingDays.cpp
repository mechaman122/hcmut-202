#include<iostream>
#include<string>
#include<math.h>

using namespace std;

int main(){
	int N7;
	int k;
	cout << "Nhap N7: ";
	cin >> N7;
	cout << "Nhap k: ";
	cin >> k;
	
	string input7Matrix[k];
	cin.ignore();
	for(int i = 0; i < k; i++){
		getline(cin, input7Matrix[i]);
	} 
	for(int i = 0; i < k; i++){
		cout << input7Matrix[i] << endl;
	}
	
	string arr[N7][N7];
	return 0;
}
