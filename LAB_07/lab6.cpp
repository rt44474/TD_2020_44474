// lab6.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
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
#define N 2.0
using namespace std;
double zad1a() {
	fstream plik;
	plik.open("dane1.txt",ios::in);
	fstream plik2;
	plik2.open("dane20.txt", ios::in);
	fstream plik1;
	plik1.open("dane10.txt", ios::out|ios::trunc);
	fstream plik3;
	plik3.open("calkaASK.txt", ios::out | ios::trunc);
	fstream plik4;
	plik4.open("koniec.txt", ios::out | ios::trunc);
	double za[3500];
	double za1[3500];
	int tmp[3500];
	double temp[3500];
	double cal = 0;
	double temporary = 0;
	double koniec[3500];
	double a = 0;
	double b=0;
	double c=0;
	double h1 = 0.8;
	double d=0;
	double calka = 0;
	double h = (Tb - 0) / 10.0;
	for (int i = 0; i < 1000;i++) {
		plik2 >> tmp[i] >> za1[i];
		plik >> tmp[i] >> za[i];
	}

	for (int i = 0; i < 1000;i++) {
		temp[i] = za1[i] * za[i];
		plik1 << tmp[i] << " " << temp[i] << endl;
		
	}
	/*for (int i = 0; i < 50; i++) {
		cal[i] += za[i];
	}
	for (int i = 0; i < 1000; i++) {
		cal[i] = cal[49];
	}*/
	for (int i = 0; i < 1000;i++) {
		cal += temp[i] ;
		plik3 << tmp[i] << " " << cal<<endl;
		if (tmp[i] % 100 == 0) {
			cal = 0;
		}
		if (cal > h1) {
			koniec[i] = 1;
			plik4 << tmp[i] << " " << koniec[i] << endl;
		}
		else if (cal < h1) {
			koniec[i] = 0;
			plik4 << tmp[i] << " " << koniec[i] << endl;
		}
	}


	plik2.close();
	plik.close();
	plik.close();
	plik3.close();
	plik4.close();
	return 0;
}
double zad1b() {
	fstream plik;
	plik.open("psk.txt", ios::in);
	fstream plik2;
	plik2.open("psk1.txt", ios::in);
	fstream plik1;
	plik1.open("dane11.txt", ios::out | ios::trunc);
	fstream plik3;
	plik3.open("calkaPSK.txt", ios::out | ios::trunc);
	fstream plik4;
	plik4.open("koniec1.txt", ios::out | ios::trunc);
	double za[3500];
	double za1[3500];
	int tmp[3500];
	double a = 0;
	double koniec[3500];
	double h1 = 0.8;
	double cal = 0;
	double b = 0;
	double c = 0;
	double temp[3500];
	double d = 0;
	for (int i = 0; i < 1000; i++) {
		plik2 >> tmp[i] >> za1[i];
		plik >> tmp[i] >> za[i];
	}

	for (int i = 0; i < 1000; i++) {
		temp[i] = za1[i] * za[i];
		plik1 << tmp[i] << " " << za1[i] * za[i] << endl;
	}
	for (int i = 0; i < 1000; i++) {
		cal += temp[i];
		plik3 << tmp[i] << " " << cal << endl;
		if (tmp[i] % 100 == 0) {
			cal = 0;
		}
		if (cal > h1) {
			koniec[i] = 1;
			plik4 << tmp[i] << " " << koniec[i] << endl;
		}
		else if (cal < h1) {
			koniec[i] = 0;
			plik4 << tmp[i] << " " << koniec[i] << endl;
		}
	}
	plik2.close();
	plik.close();
	plik.close();
	plik3.close();
	plik4.close();
	return 0;
}
double zad1c() {
	fstream plik;
	plik.open("fsk.txt", ios::in);
	fstream plik2;
	plik2.open("fskdla1.txt", ios::in);
	fstream plik3;
	plik3.open("fskdla0.txt", ios::in);
	fstream plik1;
	plik1.open("dane12.txt", ios::out | ios::trunc);
	fstream plik4;
	plik4.open("dane13.txt", ios::out | ios::trunc);

	fstream plik5;
	plik5.open("calkaFSK.txt", ios::out | ios::trunc);
	fstream plik6;
	plik6.open("calkaFSK1.txt", ios::out | ios::trunc);
	fstream plik7;
	plik7.open("dane100.txt", ios::out | ios::trunc);
	fstream plik8;
	plik8.open("koniec2.txt", ios::out | ios::trunc);
	double za[3500];
	double za1[3500];
	double za2[3500];
	int tmp[3500];
	double temp[3500];
	double temp1[3500];
	double a1[3500];
	double a2[3500];
	double a3[3500];
	double cal = 0;
	double cal1 = 0;
	double h1 = 0.5;
	double koniec[3500];
	double a = 0;
	double b = 0;
	double c = 0;
	double d = 0;
	for (int i = 0; i < 1000; i++) {
		plik3 >> tmp[i] >> za2[i];
		plik2 >> tmp[i] >> za1[i];
		plik >> tmp[i] >> za[i];
	}

	for (int i = 0; i < 1000; i++) {
		temp[i] = za1[i] * za[i];
		plik1 << tmp[i] << " " << za1[i] * za[i] << endl;//dla1
	}
	for (int i = 0; i < 1000; i++) {
		temp1[i] = za2[i] * za[i];
		plik4 << tmp[i] << " " << za2[i] * za[i] << endl;//dla0
	}
	for (int i = 0; i < 1000; i++) {
		cal += temp[i];
		a1[i] = cal;
		plik5 << tmp[i] << " " << cal << endl;
		if (tmp[i] % 100 == 0) {
			cal = 0;
		}
		cal1 += temp1[i];
		a2[i] = cal1;
		plik6 << tmp[i] << " " << cal1 << endl;
		if (tmp[i] % 100 == 0) {
			cal1 = 0;
		}
	}
	for (int i = 0; i < 1000;i++) {
		a3[i] = a1[i] - a2[i];
		plik7 << tmp[i] << " " << a3[i] << endl;
		if (a3[i] > h1) {
			koniec[i] = 1;
			plik8 << tmp[i] << " " << koniec[i] << endl;
		}
		else if (a3[i] < h1) {
			koniec[i] = 0;
			plik8 << tmp[i] << " " << koniec[i] << endl;
		}
	}

	plik4.close();
	plik2.close();
	plik3.close();
	plik.close();
	plik.close();
	plik5.close();
	plik6.close();
	plik7.close();
	return 0;
}
int main()
{

	zad1a();
	zad1b();
	zad1c();
    std::cout << "Hello World!\n";
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
