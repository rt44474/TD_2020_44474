// ConsoleApplication33.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include "liczby.cpp"
#define M_PI           3.14159265358979323846 
using namespace std;
Zespolona* dft(double tab[], int N, Zespolona dane[]) {
	float sr, si;
	for (int k = 0; k < N; k++)
	{
		dane[k].re = 0;
		dane[k].im = 0;
	}
	for (int i = 0; i < N;i++) {
		for (int j = 0; j < N;j++) {
			sr = cos(2 * M_PI * j * i / N);
			si = -sin(2 * M_PI * j * i / N);
			dane[i].re += tab[j] * sr;
			dane[i].im += tab[j] * si;
		}
	}
	return dane;
}


double zad_1(double a, double b, double c) {

	double funkcja;
	double l;
	double t = 0.0;
	double t1 = 0.0;
	int i = 0;
	int j = 0;
	double t3;
	double krok = 0.1;
	double f = b;
	double fi = (c * M_PI);
	double A = 1.0;
	double w = (2 * M_PI * b);
	double fs = (1 / krok);
	fstream plik;
	plik.open("dane.txt", ios::out | ios::trunc);
	while (t <= 474) {
		t1 = 0.0;
		t3 = 0.0;
		double t2 = t;
		while (t1 <= fs) {
			if (t3 > krok) {
				break;
			}
			funkcja = (A * sin(((2 * w * t2) + fi)));
			t1 += krok;
			l = t2;
			t2 += 0.002;
			t3 += 0.002;
			plik << t2 << " " << funkcja << endl;
			j++;
		}
		t += krok;
		i++;
	}
	plik.close();
	return 0;

}
double zad_2() {
	fstream plik;
	plik.open("dane.txt", ios::in);
	fstream plik1;
	plik.open("dane1.txt", ios::out | ios::trunc);
	double tab;
	double tab1;
	for (int i = 0; i < 237000; i++){
		plik >> tab1 >> tab;
		plik1 << tab;
	}
	return 0;
}

int main()
{
	//complex c1;
	Zespolona dane[10];
	double tab[] = { 1,2,3,4,5,6,7,8,9,10 };
	int rozmiar = 10;
	dft(tab, rozmiar, dane);
	for (int i = 0; i < rozmiar;i++) {
		cout << "wartosc:" << i + 1 << " (" << dane[i].re << ")" << "  " << "(" << dane[i].im << ")" << endl;
	}
	
	double a, b, c;
	a = 4.0;
	b = 7.0;
	c = 4.0;
	//4 7 4
	zad_1(a, b, c);
	zad_2();

}

