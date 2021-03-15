#include <iostream>
using namespace std;

int main() {
	int number;
	cout << "Enter an integer: ";
	cin >> number;
	
	if (number > 0) 
		cout <<"You entered a possitive integer: " << number << endl;
	
	cout << "This statement is always executed.";
	return 0;
}
