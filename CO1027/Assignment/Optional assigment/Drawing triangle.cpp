#include<iostream>

using namespace std;

int main() {
	int N, i, j, o;
	cout << "Enter a number N: ";
	cin >> N;
	for (int i = 1; i < N; i++) {
		for (int j = 1; j <= i; ++j) 
			cout << "*";
		for (int o = 1; o <= (2 * (N -i) - 1); ++o)
			cout << " ";
		for (int n = 1; n <= i; n++) 
			cout << "*";
		cout << endl;
	}
	for (int m = 1; m <= 2 * N - 1; m++) 
		cout << "*";
}

