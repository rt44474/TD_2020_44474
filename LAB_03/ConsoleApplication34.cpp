// ConsoleApplication33.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <vector>
#include "liczby.cpp"
#include <complex>
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
			sr = cos(2 * M_PI * i * j / N);
			si = -sin(2 * M_PI * i * j / N);
			dane[i].re += tab[j] * sr;
			dane[i].im += tab[j] * si;
		}
	}



	return dane;
}

Zespolona* idft(Zespolona dane[],int N,double tab1[]) {
	fstream plik1;
	plik1.open("dane6.txt", ios::out | ios::trunc);
	double s1[473];
	double s2[473];
	double sum[473];
	for (int k = 0; k < 473; k++)
	{
		s1[k] = 0;
		s2[k] = 0;
	}
	for (int nr = 0; nr < 473; nr++) {
		for (int i = 0; i < 473; i++)
		{
			s1[nr] = s1[nr] + dane[i].re * cos((2 * M_PI * i * nr) / 473.0);
			s2[nr] = s2[nr] - dane[i].im * sin((2 * M_PI * i * nr) / 473.0);
			if (s1[nr] >= s2[nr])
				sum[nr] = sqrt(pow(s1[nr] - s2[nr], 2)) / 473.0;
			else
				sum[nr] = -sqrt(pow(s1[nr] - s2[nr], 2)) / 473.0;

		}


	}
	int j = 1;
	plik1 << tab1[0] << " " << sum[0] << endl;
	for (int i = 472; i > 0; i--) {
		plik1 << tab1[j] << " " << sum[i] << endl;
		j++;
	}
	plik1.close();

	return dane;

}


double zad_1(double a, double b, double c) {

	double funkcja;
	double l;
	double t = 0.0;
	double t1 = 0.0;
	int i = 0;
	int j = 0;
	int z = 0;
	double t3;
	double krok = 0.1;
	double f = b;
	double fi = (c * M_PI);
	double A = 1.0;
	double w = (2 * M_PI * b);
	double fs = (1 / krok);
	fstream plik;
	plik.open("dane.txt", ios::out | ios::trunc);
	//474 probek
	while (t <= 1) {
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
			// bylo 0.002
			t2 += 0.00233;
			t3 += 0.00233;
			plik << t2 << " " << funkcja << endl;
			j++;
			z++;
			//if (z >= 474) {
			//	break;
			//}
		}
		t += krok;
		i++;
	}
	//cout << "******************************       " << z << "       **************";
	plik.close();
	return 0;

}
double zad_2() {
	fstream plik;
	// dane = sygnal prosty
	// dane2 = dft
	// dane1 = widmo
	plik.open("dane.txt", ios::in);
	fstream plik1;
	plik1.open("dane1.txt", ios::out | ios::trunc);
	fstream plik2;
	plik2.open("dane2.txt", ios::out | ios::trunc);
	fstream plik3;
	plik3.open("dane3.txt", ios::out | ios::trunc);

	double tab[474];
	double tab2[474];
	double tab1;
	double fk[474];
	double widmo[474];
	double widmo1[474];
	Zespolona dane[474];
	double rozmiar = 473.0;
	//dft dla tonu prostego
	for (int i = 0; i < 474; i++) {
		plik >> tab1 >> tab[i];
		//plik1 << tab1 << " " << tab[i] << endl;

	}		
	//return 0;
	//dft(tab, rozmiar, dane);

	for (int i = 1; i < rozmiar; i++) {
		widmo[i] = ((sqrt(pow(dane[i].re, 2) + pow(dane[i].im, 2))));
		//plik2 << dane[i].re << " " << dane[i].im << endl;
		//plik2 << i << " " << abs(dane[i].re)<<endl;
		//plik2 << i << " " << (abs(dane[i].re)) /rozmiar << endl;
	}
	for (int i = 1; i < rozmiar; i++) {
		/*if (widmo[i] < (414.484 / 10000.0)) {
			widmo[i] = 0;
		}*/
		plik2 << i << " " << widmo[i] << endl;
	}

	//widmo
	for (int i = 1; i < rozmiar; i++) {
		//widmo[i] = sqrt(pow(dane[i].re,2)+ pow(dane[i].im,2));
		//plik3 <<widmo[i] << endl; 
		//plik3 >> tab2[i];
		widmo1[i] = 10.0 * log10(widmo[i]);
		fk[i] = i * 27.0 / rozmiar;
		plik1 << fk[i] << " " << widmo1[i] << endl;
		//plik1 << widmo1[i] << " " << fk[i] << endl;
	}
	//cout << widmo[1] << " 2. " << widmo[2];
	//idft(dane, rozmiar, tab);
	plik.close();
	plik1.close();
	plik2.close();
	plik3.close();
	return 0;
}

double zad_2_4(double a, double b, double c) {
	double t = 0;
	double k = 1;
	double l = 22050;
	double o[22050];
	double funkcja[22050];
	fstream plik;
	plik.open("dane4.txt", ios::out | ios::trunc);
	double m = (k / l)*20;
	int i = 0;
	while (t <= 1) {
		if (t < 0.22 && t >= 0) {
			funkcja[i] = (1 - 7 * t) * sin((2 * M_PI * t * 10) / (t + 0.04));
			t = t + m;
			o[i] = t;
			plik << o[i] << " " << funkcja[i] << endl;
			i++;
			continue;
		}
		else if (t >= 0.22 && t < 0.7) {
			funkcja[i] = 0.63 * t * sin(125 * t);
			t = t + m;
			o[i] = t;
			plik << o[i] << " " << funkcja[i] << endl;
			i++;
			continue;
		}
		else if (t <= 1.0 && t >= 0.7) {
			funkcja[i] = pow(t, -0.662) + 0.77 * sin(8 * t);
			t = t + m;
			o[i] = t;
			plik << o[i] << " " << funkcja[i] << endl;
			i++;
			continue;
		}
	}
	plik.close();
	return 1;
}
double zad_3() {
	fstream plik;
	// dane = sygnal prosty
	// dane2 = dft
	// dane1 = widmo
	/*
	dane 10 = 112.876 // 62251.1
	dane 11 = 128.62 // 70934
	dane 12 = 0.512171 // 4875.23
	dane 13 = 391.288 // 215795.0
	dane 14 = 0.751558 // 414.484
	dane 15 = 0.864884 // 476.984
	dane 16 = 0.865632 // 477.396
	dane 17 = 0.865528 // 477.339
	*/
	plik.open("dane.txt", ios::in);
	fstream plik1;
	plik1.open("dane1.txt", ios::out | ios::trunc);
	fstream plik2;
	plik2.open("dane2.txt", ios::out | ios::trunc);
	fstream plik3;
	plik3.open("dane3.txt", ios::out | ios::trunc);
	fstream plik4;
	plik4.open("dane5.txt", ios::out | ios::trunc);
	
	double tab[473];
	double tab2[473];
	double idft2[473];
	double idft3[473];
	double tab1[473];
	double fk[473];
	double widmo[473];
	double widmo2[473];
	double widmo1[473];
	Zespolona dane[473];
	int rozmiar = 473;
	/*double tab[22050];
	double tab2[22050];
	double tab1;
	double fk[22050];
	double widmo[22050];
	double widmo2[22050];
	double widmo1[22050];
	Zespolona dane[22050];
	int rozmiar = 22050;*/
	//dft dla tonu prostego
	for (int i = 0; i < rozmiar; i++) {
		plik >> tab1[i] >> tab[i];
		//plik1 << tab1 << " " << tab[i] << endl;

	}
	//return 0;
	dft(tab, rozmiar, dane);
	idft(dane, 473, tab1);
	for (int i = 1; i < rozmiar; i++) {
		plik4 << sqrt(pow(dane[i].re, 2) + pow(dane[i].im, 2)) << endl;
	}
	for (int i = 1; i < rozmiar; i++) {
		widmo[i] = ((sqrt(pow(dane[i].re, 2) + pow(dane[i].im, 2))));
		//plik2 << dane[i].re << " " << dane[i].im << endl;
		//plik2 << i << " " << abs(dane[i].re)<<endl;
		//plik2 << i << " " << (abs(dane[i].re)) /rozmiar << endl;
	}
	for (int i = 1; i < rozmiar; i++) {
		/*if (widmo[i] < (414.484 / 10000.0)) {
			widmo[i] = 0;
		}*/
		plik2 << i << " " << widmo[i] << endl;
	}

	//widmo
	for (int i = 1; i < rozmiar; i++) {
		//widmo[i] = sqrt(pow(dane[i].re,2)+ pow(dane[i].im,2));
		//plik3 <<widmo[i] << endl; 
		//plik3 >> tab2[i];
		widmo1[i] = 10.0 * log10(widmo[i]);
		fk[i] = i * 27.0/ rozmiar;
		plik1 << fk[i] << " " << widmo1[i] << endl;
		//plik1 << widmo1[i] << " " << fk[i] << endl;
	}
	//cout << widmo[1] << " 2. " << widmo[2];

	plik.close();
	plik1.close();
	plik2.close();
	plik3.close();
	plik4.close();

	return 0;
}
int main()
{

	
	double a, b, c;
	a = 4.0;
	b = 7.0;
	c = 4.0;
	//4 7 4
	//zad_1(a, b, c);
	//zad_2();
	//zad_2_4(a, b, c);
	zad_3();
}

