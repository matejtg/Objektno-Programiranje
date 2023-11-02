#pragma once

struct Matrica {

	int m, n;
	float a, b;
	float** mat;

	void Unos();
	void Generiraj(int, int, float, float);
	void Zbroji(Matrica mat);
	void Oduzmi(Matrica mat);
	void Pomnozi(Matrica mat);
	void Transponiraj();
	void Print();
};