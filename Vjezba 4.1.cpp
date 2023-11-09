#include <iostream>
#include <string>
using namespace std;

int funkcija_broj_ponavljanja(string str, string podstr) {
	int count = 0;
	int i = 0;
	while ((i = str.find(podstr, i)) != str.npos) {
		count++;
		i += podstr.length();
	}
	return count;
}

int main() {
	string str = "String abc string abc abc";
	string podstr = "string";
	std::cout << "Broj ponavljanja: " << funkcija_broj_ponavljanja(str, podstr) << endl;
	return 0;
}