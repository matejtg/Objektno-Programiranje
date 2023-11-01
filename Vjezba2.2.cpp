#include <iostream>
using namespace std;

int& funkcija_referenca(int* niz, int& index, int duljina) {
	if (index < duljina) {
		return niz[index];
	}
	else {
		cout << "Pogresan unos indexa";
	}
}

int main() {
	int duljina, index;
	cout << "Unesite duljinu niza";
	cin >> duljina;
	int* niz = new int[duljina];
	for (int i = 0; i < duljina; i++) {
		cout << "Unesite clanove niza";
		cin >> niz[i];
	}
	cout << "Unesite index";
	cin >> index;

	int& element_sa_indexa = funkcija_referenca(niz, index, duljina);
	element_sa_indexa++;

	cout << "Uvecani element: " << niz[index] << endl;
	return 0;
}