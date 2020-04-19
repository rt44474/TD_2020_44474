// LAB05.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <fstream>
#define M_PI           3.14159265358979323846 
#include <math.h>
#include <iomanip>
#include <complex>
#define fn  800
//fn = od 800 do 2000

using namespace std;
struct Zespolona {
	double re;
	double im;
};
Zespolona* dft(double tab[], int N, Zespolona dane[]) {

	float sr, si;

	for (int k = 0; k < N; k++)
	{
		dane[k].re = 0;
		dane[k].im = 0;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			sr = cos(2 * M_PI * i * j / N);
			si = -sin(2 * M_PI * i * j / N);
			dane[i].re += tab[j] * sr;
			dane[i].im += tab[j] * si;
		}
	}



	return dane;
}

double zad_2_5(double a, double b, double c) {
	double t = 0;
	double k = 1;
	double l = 22050;
	double o[22050];
	double funkcja[22050];
	double funkcja1[22050];


	fstream plik;
	plik.open("dane7.txt", ios::out | ios::trunc);
	double m = 0.0001;
	int i = 0;

	while (t <= 1) {
		funkcja[i] = 0;
		int n = 1;
		for (int n = 1; n <= 2; n++) {

			funkcja1[i] = (cos(12 * t * pow(n, 2)) + cos(16 * t * n)) / (pow(n, 2));
			funkcja[i] += funkcja1[i];
		}
		t = t + m;
		o[i] = t;
		plik << o[i] << " " << funkcja[i] << endl;
		i++;
	}

	plik.close();
	return 1;
}
double zad_1a_1() {
	fstream plik;
	plik.open("dane7.txt", ios::in);
	fstream plik1;
	plik1.open("dane1.txt", ios::out | ios::trunc);
	fstream plik2;
	plik2.open("dane2.txt", ios::out | ios::trunc);
	fstream plik3;
	plik3.open("dane3.txt", ios::out | ios::trunc);
	fstream plik4;
	plik4.open("dane4.txt", ios::out | ios::trunc);
	double tab1;
	double tab[10000];
	double funkcja[10000];
	double funkcja1[10000];
	double widmo[10000];
	double widmo2[10000];
	double widmo11[10000];
	double widmo22[10000];
	double fk[10000];
	double rozmiar = 10000.0;
	double ka = 0.5;
	double kp = 0.5;
	double t = 0;
	double m = 0.0001;
	Zespolona dane[10000];
	Zespolona dane1[10000];
	for (int i = 0; i < rozmiar; i++) {
		plik >> tab1 >> tab[i];
		//plik1 << tab1 << " " << tab[i] << endl;
	}
	for (int i = 0; i < rozmiar; i++) {

		funkcja[i] = (ka * tab[i] + 1) * cos(2 * M_PI * fn * t);
		t = t + m;
		plik1 << t << " " << funkcja[i] << endl;
	}
	for (int i = 0; i < rozmiar;i++) {
		funkcja1[i] = cos(2* M_PI *fn*t + kp*tab[i]);
		t = t + m;
		plik2 << t << " " << funkcja1[i] << endl;
	}
	dft(funkcja, rozmiar, dane);
	dft(funkcja1, rozmiar, dane1);
	for (int i = 1; i < rozmiar; i++) {
		widmo[i] = ((sqrt(pow(dane[i].re, 2) + pow(dane[i].im, 2))));
		widmo2[i] = ((sqrt(pow(dane1[i].re, 2) + pow(dane1[i].im, 2))));
	}
	for (int i = 1; i < rozmiar; i++) {
		widmo11[i] = 10.0 * log10(widmo[i]);
		fk[i] = i * 27.0 / rozmiar;
		plik3 << fk[i] << " " << widmo11[i] << endl;
		widmo22[i] = 10.0 * log10(widmo2[i]);
		plik4 << fk[i] << " " << widmo22[i] << endl;
	}


	plik1.close();
	plik2.close();
	plik3.close();
	plik4.close();
	plik.close();
	return 0;
}
double zad_1b_1() {
	fstream plik;
	plik.open("dane7.txt", ios::in);
	fstream plik1;
	plik1.open("dane1.txt", ios::out | ios::trunc);
	fstream plik2;
	plik2.open("dane2.txt", ios::out | ios::trunc);
	fstream plik3;
	plik3.open("dane3.txt", ios::out | ios::trunc);
	fstream plik4;
	plik4.open("dane4.txt", ios::out | ios::trunc);
	double tab1;
	double tab[10000];
	double funkcja[10000];
	double funkcja1[10000];
	double widmo[10000];
	double widmo2[10000];
	double widmo11[10000];
	double widmo22[10000];
	double fk[10000];
	double rozmiar = 10000.0;
	double ka = 6;
	double kp = 1.5;
	double t = 0;
	double m = 0.0001;
	Zespolona dane[10000];
	Zespolona dane1[10000];
	for (int i = 0; i < rozmiar; i++) {
		plik >> tab1 >> tab[i];
		//plik1 << tab1 << " " << tab[i] << endl;
	}
	for (int i = 0; i < rozmiar; i++) {

		funkcja[i] = (ka * tab[i] + 1) * cos(2 * M_PI * fn * t);
		t = t + m;
		plik1 << t << " " << funkcja[i] << endl;
	}
	for (int i = 0; i < rozmiar; i++) {
		funkcja1[i] = cos(2 * M_PI * fn * t + kp * tab[i]);
		t = t + m;
		plik2 << t << " " << funkcja1[i] << endl;
	}
	dft(funkcja, rozmiar, dane);
	dft(funkcja1, rozmiar, dane1);
	for (int i = 1; i < rozmiar; i++) {
		widmo[i] = ((sqrt(pow(dane[i].re, 2) + pow(dane[i].im, 2))));
		widmo2[i] = ((sqrt(pow(dane1[i].re, 2) + pow(dane1[i].im, 2))));
	}
	for (int i = 1; i < rozmiar; i++) {
		widmo11[i] = 10.0 * log10(widmo[i]);
		fk[i] = i * 27.0 / rozmiar;
		plik3 << fk[i] << " " << widmo11[i] << endl;
		widmo22[i] = 10.0 * log10(widmo2[i]);
		plik4 << fk[i] << " " << widmo22[i] << endl;
	}


	plik1.close();
	plik2.close();
	plik3.close();
	plik4.close();
	plik.close();
	return 0;
}
double zad_1c_1() {
	fstream plik;
	plik.open("dane7.txt", ios::in);
	fstream plik1;
	plik1.open("dane1.txt", ios::out | ios::trunc);
	fstream plik2;
	plik2.open("dane2.txt", ios::out | ios::trunc);
	fstream plik3;
	plik3.open("dane3.txt", ios::out | ios::trunc);
	fstream plik4;
	plik4.open("dane4.txt", ios::out | ios::trunc);
	double tab1;
	double tab[10000];
	double funkcja[10000];
	double funkcja1[10000];
	double widmo[10000];
	double widmo2[10000];
	double widmo11[10000];
	double widmo22[10000];
	double fk[10000];
	double rozmiar = 10000.0;
	double ka = 30;
	double kp = 30;
	double t = 0;
	double m = 0.0001;
	Zespolona dane[10000];
	Zespolona dane1[10000];
	for (int i = 0; i < rozmiar; i++) {
		plik >> tab1 >> tab[i];
		//plik1 << tab1 << " " << tab[i] << endl;
	}
	for (int i = 0; i < rozmiar; i++) {

		funkcja[i] = (ka * tab[i] + 1) * cos(2 * M_PI * fn * t);
		t = t + m;
		plik1 << t << " " << funkcja[i] << endl;
	}
	for (int i = 0; i < rozmiar; i++) {
		funkcja1[i] = cos(2 * M_PI * fn * t + kp * tab[i]);
		t = t + m;
		plik2 << t << " " << funkcja1[i] << endl;
	}
	dft(funkcja, rozmiar, dane);
	dft(funkcja1, rozmiar, dane1);
	for (int i = 1; i < rozmiar; i++) {
		widmo[i] = ((sqrt(pow(dane[i].re, 2) + pow(dane[i].im, 2))));
		widmo2[i] = ((sqrt(pow(dane1[i].re, 2) + pow(dane1[i].im, 2))));
	}
	for (int i = 1; i < rozmiar; i++) {
		widmo11[i] = 10.0 * log10(widmo[i]);
		fk[i] = i * 27.0 / rozmiar;
		plik3 << fk[i] << " " << widmo11[i] << endl;
		widmo22[i] = 10.0 * log10(widmo2[i]);
		plik4 << fk[i] << " " << widmo22[i] << endl;
	}


	plik1.close();
	plik2.close();
	plik3.close();
	plik4.close();
	plik.close();
	return 0;
}

int main()
{

	zad_2_5(4.0, 7.0, 4.0);
	zad_1c_1();
}

