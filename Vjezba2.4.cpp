#include<iostream>
#include"Vjezba2.4.h"


int main() {

	Matrica mat, mat1;

	std::cout << "Unost matrice: " << std::endl;
	mat.Unos();
	mat.Print();
	std::cout << "Generiranje matrice: " << std::endl;
	mat1.Generiraj(2, 2, 1, 2);
	mat1.Print();
	std::cout << "Transponiranje matrice: " << std::endl;
	mat.Transponiraj();
	mat.Print();
	std::cout << "Mnozenje matrice: " << std::endl;
	mat.Pomnozi(mat);
	mat.Print();
	std::cout << "Zbrajanje matrice: " << std::endl;
	mat.Zbroji(mat1);
	mat.Print();
	std::cout << "Oduzimanje matrice: " << std::endl;
	mat.Oduzmi(mat1);
	mat.Print();

	return 0;
}