#include <iostream>
#include <string>
using namespace std;
void poprec(string str) {
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == ',' || str[i] == '.' || str[i] == '!' || str[i] == '?') {
			if (str[i - 1] == ' ') {
				str.erase(str.begin() + i - 1);
				str.insert(str.begin() + i, ' ');
			}
		}
	}
	cout << str << endl;
}

int main() {
	string str = "Ja bih ,ako ikako mogu , ovu recenicu napisala ispravno.";
	cout << str << endl;
	poprec(str);
	return 0;
}