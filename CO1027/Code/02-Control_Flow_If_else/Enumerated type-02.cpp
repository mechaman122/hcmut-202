#include<iostream>
using namespace std;

enum suit {club = 0, diamond = 10, hearts = 20, spades = 3} card;

int main() {
	card = club;
	cout << "Size of enum available " << sizeof(card) << " bytes.\n";
	return 0;
}
