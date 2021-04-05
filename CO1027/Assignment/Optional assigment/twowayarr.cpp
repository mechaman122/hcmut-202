#include <iostream>
#include <string>

using namespace std;

int main(){
	int a[4][4];
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < 4; i++){
		int max = a[i][0];
		for (int j = 0; j < 4; j++){
			cout << a[i][j] << " ";
			if (max < a[i][j]) max = a[i][j];
		}
		cout << "Max:" << max;
		cout << endl;
	}
}
