#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string preok_str(string& str) {
	reverse(str.begin(), str.end());
	return str;
}

void vektor_str() {
	vector<string>vec;
	int numstr = 0;
	cout << "Unesite broj stringova: ";
	cin >> numstr;
	for (int i = 0; i < numstr; i++) {
		string str;
		cout << "string" << i + 1 << ": ";
		cin >> str;
		vec.push_back(str);
	}
	string str;
	for (int i = 0; i < numstr; i++) {
		preok_str(vec[i]);
	}
	sort(vec.begin(), vec.end());
	cout << "Sortirani vektori i preokrenuti stringovi: " << endl;
	for (int i = 0; i < numstr; i++) {
		cout << vec[i];
	}
}

int main() {
	vektor_str();
	return 0;
}