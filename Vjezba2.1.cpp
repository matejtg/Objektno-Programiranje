#include <iostream>
using namespace std;

void funkcija_min_max(int duljina, int& najmanji, int& najveci, int* niz) {
	najmanji = niz[0];
	najveci = niz[0];

	for (int i = 0; i < duljina; i++) {
		if (niz[i] < najmanji) {
			najmanji = niz[i];
		}
		if (niz[i] > najveci) {
			najveci = niz[i];
		}
	}
}


int main() {
	int najveci, najmanji, duljina;
	cout << "Unesite duljinu niza";
	cin >> duljina;
	int* niz = new int[duljina];
	for (int i = 0; i < duljina; i++) {
		cout << "Unesite clanove niza";
		cin >> niz[i];
	}

	funkcija_min_max(duljina, najmanji, najveci, niz);
	cout << "Najveci je"<< najveci << "najmanji je " << najmanji;
	return 0;
}