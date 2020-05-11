// lab5.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <bitset>
#include <complex>
#include <string.h>
#include <algorithm>

#define M_PI           3.14159265508979323846 
# define my_sizeof(type) ((char *)(&type+1)-(char*)(&type)) 
#define Tb 1
#define A1 0.0
#define A2 1.0
#define N 10.0
using namespace std;
struct Zespolona {
	double re;
	double im;
};
Zespolona* dft(double tab[], int M, Zespolona dane[]) {

	float sr, si;

	for (int k = 0; k < M; k++)
	{
		dane[k].re = 0;
		dane[k].im = 0;
	}
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
			sr = cos(2 * M_PI * i * j / M);
			si = -sin(2 * M_PI * i * j / M);
			dane[i].re += tab[j] * sr;
			dane[i].im += tab[j] * si;
		}
	}



	return dane;
}

string S2BS(string slowo1,int size) {
	int j;
	cout << endl;
	fstream plik;
	plik.open("dane.txt", ios::out | ios::trunc);
	cout << "Wyswietl w:" << endl << "[1].Big Endian" << endl << "[2].Little Endian" << endl;
	cin >> j;
	double f = 0.0;
	switch (j) {
	case 1:
		for (int i = 0; i < size; i++) {
			cout << slowo1[i];
			for (int j = 0; j < 100;j++) {
				plik << f << " " << slowo1[i] << endl;
				f += Tb;
			}
		}
		plik.close();
		return slowo1;
	case 2:
		for (int i = size-1; i >= 0; i--) {
			cout << slowo1[i];
			for (int j = 0; j < 100;j++) {
				plik << f << " " << slowo1[i] << endl;
				f += Tb;
			}
		}
		plik.close();
		return slowo1;
	}
	return slowo1;
}
double zad1(int size) {
	fstream plik;
	plik.open("dane.txt", ios::in);
	fstream plik1;
	plik1.open("dane1.txt", ios::out | ios::trunc);

	fstream plik2;
	plik2.open("dane4.txt", ios::out | ios::trunc);
	fstream plik3;
	plik3.open("dane9.txt", ios::out | ios::trunc);
	fstream plik4;
	plik4.open("dane1.txt", ios::in);
	double f1 = N * pow(Tb, -1);
	double tab[8000];
	double za[8000];
	double tmp[8000];
	double tmp1[8000];
	double fk[8000];
	double rozmiar = 8000.0;
	double funkcja[8000];
	double f;
	double nic;
	int z = 0;
	int w = 0;
	double t = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < 100; j++) {

			plik >> f >> tab[i];
			if (tab[i] == 1) {
				za[j] = A2 * sin(2 * M_PI * f1 * t + 0.0);
				plik1 << f << " " << za[j] << endl;
				funkcja[w] = A2 * sin(2 * M_PI * f1 * t + 0.0);
			}
			else if (tab[i] == 0) {
				za[j] = A1 * sin(2 * M_PI * f1 * t + 0.0);
				plik1 << f << " " << za[j] << endl;
				funkcja[w] = A1 * sin(2 * M_PI * f1 * t + 0.0);
			}
			//plik3 << f << " " << funkcja[w]<<endl;
			t += 0.01;
			f += Tb;
			//funkcja[w] = za[j];
			w++;
		}
	}
	/*for (int i = 0; i < 8000;i++) {
		plik4 >> nic >> funkcja[i];
		if (funkcja[i] == 0 || funkcja[i] == -0) {
			funkcja[i] = 0;
		}
		plik3 << funkcja[i] << endl;

	}*/
	Zespolona dane[8000];
	dft(funkcja,rozmiar,dane);
	for (int i = 0; i < rozmiar; i++) {
		//tmp[i] = ((sqrt(pow(dane[i].re, 2) + pow(dane[i].im, 2))))/rozmiar;
		tmp[i] = ((sqrt(pow(dane[i].re, 2) + pow(dane[i].im, 2))));
		if (tmp[i]< (10*pow(10,-4))) {
			tmp[i] = 0;
		}
		//plik3 << i << " " << tmp[i] << endl;

	}
	for (int i = 0; i < rozmiar; i++) {
		tmp1[i] = 10.0 * log10(tmp[i]);
		fk[i] = i * 27.0 / rozmiar;
		plik2 << fk[i] << " " << tmp1[i] << endl;

	}

	plik.close();
	plik1.close();
	plik2.close();
	plik3.close();
	plik4.close();
	return 0;
}
double zad1b(int size) {
	fstream plik;
	plik.open("dane.txt", ios::in);
	fstream plik1;
	plik1.open("dane2.txt", ios::out | ios::trunc);
	fstream plik2;
	plik2.open("dane5.txt", ios::out | ios::trunc);
	fstream plik3;
	plik3.open("dane10.txt", ios::out | ios::trunc);
	fstream plik4;
	plik4.open("dane2.txt", ios::in);
	//double f1 = N * pow(Tb, -1);
	double f0 = (N + 1) / Tb;
	double f1 = (N + 2) / Tb;
	double tab[8000];
	double za[8000];
	double f;
	int z = 0;
	int w = 0;
	double tmp[8000];
	double rozmiar = 8000.0;
	double nic;
	double funkcja[8000];
	double tmp1[8000];
	double fk[8000];
	double t = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < 100; j++) {

			plik >> f >> tab[i];
			if (tab[i] == 1) {
				za[j] = A2 * sin(2 * M_PI * f1 * t + 0.0);
				plik1 << f << " " << za[j] << endl;
				funkcja[w] = A2 * sin(2 * M_PI * f1 * t + 0.0);
			}
			else {
			if (tab[i] == 0) {
			za[j] = A2 * sin(2 * M_PI * f0 * t + 0.0);
			plik1 << f << " " << za[j] << endl;
			funkcja[w] = A2 * sin(2 * M_PI * f0 * t + 0.0);
			}
			}
			t += 0.01;
			f += Tb;
			w++;
		}
	}
	Zespolona dane[8000];
	dft(funkcja, rozmiar, dane);
	for (int i = 0; i < rozmiar; i++) {
		//tmp[i] = ((sqrt(pow(dane[i].re, 2) + pow(dane[i].im, 2))))/rozmiar;
		tmp[i] = ((sqrt(pow(dane[i].re, 2) + pow(dane[i].im, 2))));
		if (tmp[i] < (10 * pow(10, -4))) {
			tmp[i] = 0;
		}
		//plik3 << i << " " << tmp[i] << endl;

	}
	for (int i = 0; i < rozmiar; i++) {
		tmp1[i] = 10.0 * log10(tmp[i]);
		fk[i] = i * 27.0 / rozmiar;
		plik2 << fk[i] << " " << tmp1[i] << endl;

	}
	plik.close();
	plik1.close();
	plik3.close();
	plik4.close();
	plik2.close();
	return 0;
}
double zad1c(int size) {
	fstream plik;
	plik.open("dane.txt", ios::in);
	fstream plik1;
	plik1.open("dane3.txt", ios::out | ios::trunc);
	fstream plik2;
	plik2.open("dane6.txt", ios::out | ios::trunc);
	fstream plik3;
	plik3.open("dane11.txt", ios::out | ios::trunc);
	fstream plik4;
	plik4.open("dane3.txt", ios::in);
	double tmp[8000];
	double tmp1[8000];
	double fk[8000];
	double f1 = N * pow(Tb, -1);
	double tab[8000];
	double za[8000];
	int w = 0;
	double nic;
	double rozmiar = 8000.0;
	double funkcja[8000];
	double f;
	int z = 0;
	double t = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < 100; j++) {

			plik >> f >> tab[i];

			if (tab[i] == 1) {
				za[j] = A2 * sin(2 * M_PI * f1 * t + M_PI);
				plik1 << f << " " << za[j] << endl;
				funkcja[w] = A2 * sin(2 * M_PI * f1 * t + M_PI);
			}
			else if (tab[i] == 0) {
				za[j] = A2 * sin(2 * M_PI * f1 * t + 0.0);
				plik1 << f << " " << za[j] << endl;
				funkcja[w] = A2 * sin(2 * M_PI * f1 * t + 0.0);
			}



			t += 0.01;
			f += Tb;
			w++;
		}
	}
	Zespolona dane[8000];
	dft(funkcja, rozmiar, dane);
	for (int i = 0; i < rozmiar; i++) {
		//tmp[i] = ((sqrt(pow(dane[i].re, 2) + pow(dane[i].im, 2))))/rozmiar;
		tmp[i] = ((sqrt(pow(dane[i].re, 2) + pow(dane[i].im, 2))));
		if (tmp[i] < (10 * pow(10, -4))) {
			tmp[i] = 0;
		}
		//plik3 << i << " " << tmp[i] << endl;

	}
	for (int i = 0; i < rozmiar; i++) {
		tmp1[i] = 10.0 * log10(tmp[i]);
		fk[i] = i * 27.0 / rozmiar;
		plik2 << fk[i] << " " << tmp1[i] << endl;

	}
	plik.close();
	plik1.close();
	plik3.close();
	plik4.close();
	plik2.close();
	return 0;
}

int main()
{
	int j = 0;
	int i[10] = { 'T','e','s','t','o','w','a','n','i','e' };
	int size = my_sizeof(i) / my_sizeof(i[0]);
	int size1 = size * 8;
	//cout << size1;
	//std::vector<std::string> slowo1;
	string slowo1;
	char buffer[100];
	for (j; j < size;j++) {
	_itoa_s(i[j], buffer, 2);
	//printf("binary: %s\n", buffer);
	//slowo1.push_back(buffer);
	slowo1 = slowo1 +"0"+ buffer;
	}
	cout << slowo1<<endl;
	//string test = "001001100011000010110110101100001001000000100110101000001001000000100101101001111010101000100001";
	//string test1 = "0001000111";
	//cout << endl << test.length();
	//S2BS(slowo1,size1);
	S2BS(slowo1, 80);
	zad1(80);
	zad1b(80);
	zad1c(80);
	//cout << endl << endl << slowo;
	//S2BS(slowo1);


	return 0;

}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
