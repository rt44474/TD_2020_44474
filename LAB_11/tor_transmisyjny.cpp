// tor_transmisyjny.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
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
# define my_sizeof(type) ((char *)(&type+1)-(char*)(&type)) 
#define M_PI           3.14159265508979323846 
#define Tb 0.1
#define A1 0.0
#define A2 1.0
#define N 10.0
#define rozmiar11 42
#define rozmiar22 48
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
string S2BS(int i[], int size) {
	fstream plik1;
	plik1.open("S2BS.txt", ios::out | ios::trunc);
	int j = 0;
	int slowo[100];
	//cout << size1;
	//std::vector<std::string> slowo1;
	string slowo1;
	char buffer[100];
	for (j; j < size; j++) {
		_itoa_s(i[j], buffer, 2);
		//printf("binary: %s\n", buffer);
		//slowo1.push_back(buffer);
		slowo1 = slowo1 + "0" + buffer;
	}
	for (int i = 0; i < size * 8; i++) {
		plik1 << slowo1[i] << endl;
	}
	plik1.close();
	return slowo1;
}
//zwykly hamming
string zad1(int slowo1[], int size1) {
	fstream plik1;
	plik1.open("Hamming.txt", ios::out | ios::trunc);
	int ham[100];
	int size = size1 * 8;
	int size2 = size1 * 2 * 7;
	string x;
	int z = 1;
	int j = 0;
	for (int i = 0; i < size; i += 4) {
		ham[j] = slowo1[i] + slowo1[i + 1] + slowo1[i + 3];
		ham[j + 1] = slowo1[i] + slowo1[i + 2] + slowo1[i + 3];
		ham[j + 2] = slowo1[i];
		ham[j + 3] = slowo1[i + 1] + slowo1[i + 2] + slowo1[i + 3];
		ham[j + 4] = slowo1[i + 1];
		ham[j + 5] = slowo1[i + 2];
		ham[j + 6] = slowo1[i + 3];
		j += 7;
	}
	cout << endl;
	cout << "Hamming(7,4) przed modulo:" << endl;
	for (int i = 0; i < size2; i++) {
		cout << ham[i];
		if (z % 7 == 0) {
			cout << " ";
		}
		z++;
	}
	z = 1;
	cout << endl;
	cout << "Hamming(7,4) po modulo:" << endl;
	for (int i = 0; i < size2; i++) {
		if (ham[i] % 2 == 0) {
			ham[i] = 0;
		}
		cout << ham[i];
		if (z % 14 == 0) {
			cout << " ";
		}
		z++;
		plik1 << ham[i] << endl;
	}
	plik1.close();
	return x;
}
//SECDED
void zad4(int tab[],int size1) {
	int size = size1 * 8;
	int size2 = size1 * 2 * 8;
	int ham[100];

	int i = 0;
	int j = 1;
	fstream plik1;
	plik1.open("Hamming.txt", ios::out | ios::trunc);
	cout << endl << endl << endl << "ZAD 4";

	cout << endl << "Strumien binarny:" << endl;

	for (int i = 0; i < size; i++) {
		cout << tab[i];
		if (j % 4 == 0) {
			cout << " ";
		}
		j++;
	}
	cout << endl;
	j = 0;
	for (int i = 0; i < size; i += 4) {
		ham[j] = (tab[i] + tab[i + 1] + tab[i + 3]) % 2;
		ham[j + 1] = (tab[i] + tab[i + 2] + tab[i + 3]) % 2;
		ham[j + 2] = tab[i];
		ham[j + 3] = (tab[i + 1] + tab[i + 2] + tab[i + 3]) % 2;
		ham[j + 4] = tab[i + 1];
		ham[j + 5] = tab[i + 2];
		ham[j + 6] = tab[i + 3];
		ham[j + 7] = (ham[j] + ham[j + 1] + ham[j + 2] + ham[j + 3] + ham[j + 4] + ham[j + 5] + ham[j + 6]) % 2;
		j += 8;
	}
	int z = 1;
	cout << "SECDED:" << endl;
	for (int i = 0; i < size2; i++) {
		cout << ham[i];
		if (z % 8 == 0) {
			cout << " ";
		}
		z++;
		plik1 << ham[i] << endl;
	}

	plik1.close();
}

//negacja w hammingu
void zad2(int size1) {
	int tab[100];
	int i = 0;
	int k;
	int z = 1;
	int size2 = size1 * 2 * 7;

	fstream plik;
	plik.open("Hamming.txt", ios::in);

	cout << endl <<  endl << "Ktory numer bitu ma zostac uszkodzony:";
	cin >> k;
	while (!plik.eof()) {
		//for (int i = 0; i < 42;i++) {
		plik >> tab[i];
		i++;
	}
	if (tab[k - 1] == 1) {
		tab[k - 1] = 0;
	}
	else if (tab[k - 1] == 0) {
		tab[k - 1] = 1;
	}
	fstream plik2;
	plik2.open("Hamming.txt", ios::out | ios::trunc);

	cout << "Uszkodzony kod Hammiga na pozycji " << k << ":" << endl;
	for (int i = 0; i < size2; i++) {
		cout << tab[i];
		if (z % 14 == 0) {
			cout << " ";
		}
		z++;
		plik2 << tab[i] << endl;
	}
	cout << endl << endl;
	plik.close();
	plik2.close();
}
//negacja SECDED
void zad5(int size1) {
	int tab[100];
	int i = 0;
	int k;
	int l;
	int z = 1;
	int size2 = size1 * 2 * 8;

	fstream plik;
	plik.open("Hamming.txt", ios::in);


	cout << endl << endl << "Ktore numery bitu maja zostac uszkodzone:";
	cin >> k >> l;
	while (!plik.eof()) {
		plik >> tab[i];
		i++;
	}
	if (tab[k - 1] == 1) {
		tab[k - 1] = 0;
	}
	else if (tab[k - 1] == 0) {
		tab[k - 1] = 1;
	}
	if (tab[l - 1] == 1) {
		tab[l - 1] = 0;
	}
	else if (tab[l - 1] == 0) {
		tab[l - 1] = 1;
	}
	plik.close();
	cout << "Uszkodzony kod Hammiga na pozycjach " << k << "," << l << ":" << endl;
	fstream plik2;
	plik2.open("Hamming.txt", ios::out | ios::trunc);
	for (int i = 0; i < size2; i++) {
		cout << tab[i];
		if (z % 16 == 0) {
			cout << " ";
		}
		z++;
		plik2 << tab[i] << endl;
	}
	cout << endl;
	plik2.close();
}

//zASK modulacja
double zad11(int size) {
	fstream plik;
	plik.open("Hamming.txt", ios::in);
	fstream plik1;
	plik1.open("m(t).txt", ios::out | ios::trunc);
	fstream plik2;
	plik2.open("zASK.txt", ios::out | ios::trunc);
	fstream plik3;
	plik3.open("dft.txt", ios::out | ios::trunc);
	fstream plik4;
	plik4.open("zASKdla1.txt", ios::out | ios::trunc);

	double f1 = 10;
	double tab[4800];
	double za[4800];
	double tmp[4800];
	double tmp1[4800];
	double fk[4800];
	double funkcja[4800];
	double dla1[4800];
	double f = 0;
	double nic;
	int z = 0;
	int w = 0;
	double t = 0;
	int size1 = size * 2 * 3;
	double rozmiar = size1 * 100.0;
	double ham[100];
	for (int i = 0; i < size1; i++) {
		plik >> ham[i];
	}
	for (int i = 0; i < size1; i++) {
		for (int j = 0; j < 100; j++) {
			plik1 << f << " " << ham[i] << endl;
			f += Tb;
		}
	}
	plik1.close();
	fstream plik5;
	plik5.open("m(t).txt", ios::in);
	for (int i = 0; i < size1; i++) {
		for (int j = 0; j < 100; j++) {

			plik5 >> f >> tab[i];
			if (tab[i] == 1) {
				za[j] = A2 * sin(2 * M_PI * f1 * t + 0.0);
				plik2 << f << " " << za[j] << endl;
				funkcja[w] = A2 * sin(2 * M_PI * f1 * t + 0.0);
			}
			else if (tab[i] == 0) {
				za[j] = A1 * sin(2 * M_PI * f1 * t + 0.0);
				plik2 << f << " " << za[j] << endl;
				funkcja[w] = A1 * sin(2 * M_PI * f1 * t + 0.0);
			}
			//plik3 << f << " " << funkcja[w]<<endl;
			t += 0.01;
			f += Tb;
			//funkcja[w] = za[j];
			w++;
		}
	}
	t = 0;
	f = 0;
	for (int i = 0; i < size1; i++) {
		for (int j = 0; j < 100; j++) {

			dla1[j] = A2 * sin(2 * M_PI * f1 * t + 0.0);
			plik4 << f << " " << dla1[j] << endl;
			//funkcja[w] = A2 * sin(2 * M_PI * f1 * t + 0.0);
		//plik3 << f << " " << funkcja[w]<<endl;
		t += 0.01;
		f += Tb;
		//funkcja[w] = za[j];
		w++;
		}
	}


	Zespolona dane[4800];
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
		fk[i] = i * 10000 / rozmiar;
		plik3 << fk[i] << " " << tmp1[i] << endl;

	}
	plik3.close();
	plik.close();
	plik2.close();
	plik5.close();
	plik4.close();
	return 0;
	
}
//modulacja zPSK
double zad1c(int size) {
	fstream plik;
	plik.open("Hamming.txt", ios::in);
	fstream plik1;
	plik1.open("m(t).txt", ios::out | ios::trunc);
	fstream plik2;
	plik2.open("zPSK.txt", ios::out | ios::trunc);
	fstream plik3;
	plik3.open("dft.txt", ios::out | ios::trunc);
	fstream plik4;
	plik4.open("zPSKdla1.txt", ios::out | ios::trunc);
	double f1 = 10;
	double tab[4800];
	double za[4800];
	double tmp[4800];
	double tmp1[4800];
	double fk[4800];
	double funkcja[4800];
	double dla1[4800];
	double f = 0;
	double nic;
	int z = 0;
	int w = 0;
	double t = 0;
	int size1 = size * 2 * 3;
	double rozmiar = size1 * 100.0;
	double ham[100];
	for (int i = 0; i < size1; i++) {
		plik >> ham[i];
	}
	for (int i = 0; i < size1; i++) {
		for (int j = 0; j < 100; j++) {
			plik1 << f << " " << ham[i] << endl;
			f += Tb;
		}
	}
	plik1.close();
	fstream plik5;
	plik5.open("m(t).txt", ios::in);


	for (int i = 0; i < size1; i++) {
		for (int j = 0; j < 100; j++) {

			plik5 >> f >> tab[i];

			if (tab[i] == 1) {
				za[j] = A2 * sin(2 * M_PI * f1 * t + M_PI);
				plik2 << f << " " << za[j] << endl;
				funkcja[w] = A2 * sin(2 * M_PI * f1 * t + M_PI);
			}
			else if (tab[i] == 0) {
				za[j] = A2 * sin(2 * M_PI * f1 * t + 0.0);
				plik2 << f << " " << za[j] << endl;
				funkcja[w] = A2 * sin(2 * M_PI * f1 * t + 0.0);
			}
			t += 0.01;
			f += Tb;
			w++;
		}
	}
	t = 0;
	f = 0;
	for (int i = 0; i < size1;i++) {
		for (int j = 0; j < 100;j++) {
			dla1[j] = A2 * sin(2 * M_PI * f1 * t + M_PI);
			plik4 << f << " " << dla1[j] << endl;
			t += 0.01;
			f += Tb;
			w++;
		}
	}
	Zespolona dane[4800];
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
		fk[i] = i * 10000 / rozmiar;
		plik3 << fk[i] << " " << tmp1[i] << endl;

	}
	plik3.close();
	plik.close();
	plik2.close();
	plik5.close();
	plik4.close();
	return 0;
}

//modulacja zFSK
double zad11b(int size) {
	fstream plik;
	plik.open("Hamming.txt", ios::in);
	fstream plik1;
	plik1.open("m(t).txt", ios::out | ios::trunc);
	fstream plik2;
	plik2.open("zFSK.txt", ios::out | ios::trunc);
	fstream plik3;
	plik3.open("dft.txt", ios::out | ios::trunc);
	fstream plik4;
	plik4.open("zFSKdla1.txt", ios::out | ios::trunc);
	fstream plik6;
	plik6.open("zFSKdla0.txt", ios::out | ios::trunc);
	double tab[4800];
	double za[4800];
	double tmp[4800];
	double tmp1[4800];
	double fk[4800];
	double funkcja[4800];
	double dla1[4800];
	double dla0[4800];
	double f = 0;
	double nic;
	double f0 = 11;
	double f1 = 12;
	int z = 0;
	int w = 0;
	double t = 0;
	int size1 = size * 2 * 3;
	double rozmiar = size1 * 100.0;
	double ham[100];
	for (int i = 0; i < size1; i++) {
		plik >> ham[i];
	}
	for (int i = 0; i < size1; i++) {
		for (int j = 0; j < 100; j++) {
			plik1 << f << " " << ham[i] << endl;
			f += Tb;
		}
	}
	plik1.close();
	fstream plik5;
	plik5.open("m(t).txt", ios::in);
	for (int i = 0; i < size1; i++) {
		for (int j = 0; j < 100; j++) {

			plik5 >> f >> tab[i];
			if (tab[i] == 1) {
				za[j] = A2 * sin(2 * M_PI * f1 * t + 0.0);
				plik2 << f << " " << za[j] << endl;
				funkcja[w] = A2 * sin(2 * M_PI * f1 * t + 0.0);
			}
			else {
				if (tab[i] == 0) {
					za[j] = A2 * sin(2 * M_PI * f0 * t + 0.0);
					plik2 << f << " " << za[j] << endl;
					funkcja[w] = A2 * sin(2 * M_PI * f0 * t + 0.0);
				}
			}
			t += 0.01;
			f += Tb;
			w++;
		}
	}
	t = 0;
	f = 0;
	for (int i = 0; i < size1; i++) {
		for (int j = 0; j < 100;j++) {
			dla1[j] = A2 * sin(2 * M_PI * f1 * t + 0.0);
			dla0[j] = A2 * sin(2 * M_PI * f0 * t + 0.0);
			plik4 << f << " " << dla1[j] << endl;
			plik6 << f << " " << dla0[j] << endl;
			t += 0.01;
			f += Tb;
			w++;

		}
	}



	Zespolona dane[4800];
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
		fk[i] = i * 10000 / rozmiar;
		plik3 << fk[i] << " " << tmp1[i] << endl;

	}
	plik3.close();
	plik.close();
	plik2.close();
	plik5.close();
	plik4.close();
	plik6.close();
	return 0;
}



//demodulacja zASK
double zad1a(int size) {
	fstream plik;
	plik.open("zASK.txt", ios::in);
	fstream plik2;
	plik2.open("zASKdla1.txt", ios::in);
	fstream plik3;
	plik3.open("calkaASK.txt", ios::out | ios::trunc);
	fstream plik4;
	plik4.open("koniec.txt", ios::out | ios::trunc);
	double za[4800];
	double za1[4800];
	double tmp[4800];
	double temp[4800];
	double cal = 0;
	double temporary = 0;
	double koniec[4800];
	int size1 = size * 2 * 3;
	int size2 = size1 * 100;
	double a = 0;
	double b = 0;
	double c = 0;
	double h1 = 0.8;
	double d = 0;
	double calka = 0;
	double h = (Tb - 0) / 10.0;
	for (int i = 0; i < size2; i++) {
		plik2 >> tmp[i] >> za1[i];
		plik >> tmp[i] >> za[i];
	}

	for (int i = 0; i < size2; i++) {
		temp[i] = za1[i] * za[i];

	}
	for (int i = 0; i < size2; i++) {
		cal += temp[i];
		plik3 << tmp[i] << " " << cal << endl;
		if (i % 100 ==0) {
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
	plik3.close();
	plik4.close();
	return 0;
}





//demodulacja zPSK
double zad1b(int size) {
	fstream plik;
	plik.open("zPSK.txt", ios::in);
	fstream plik2;
	plik2.open("zPSKdla1.txt", ios::in);
	fstream plik3;
	plik3.open("calkaPSK.txt", ios::out | ios::trunc);
	fstream plik4;
	plik4.open("koniec.txt", ios::out | ios::trunc);
	int size1 = size * 2 * 3;
	int size2 = size1 * 100;
	double za[4800];
	double za1[4800];
	double tmp[4800];
	double temp[4800];
	double cal = 0;
	double temporary = 0;
	double koniec[4800];

	double a = 0;
	double b = 0;
	double c = 0;
	double h1 = 0.8;
	double d = 0;
	double calka = 0;
	double h = (Tb - 0) / 10.0;
	for (int i = 0; i < size2; i++) {
		plik2 >> tmp[i] >> za1[i];
		plik >> tmp[i] >> za[i];
	}

	for (int i = 0; i < size2; i++) {
		temp[i] = za1[i] * za[i];
	}
	for (int i = 0; i < size2; i++) {
		cal += temp[i];
		plik3 << tmp[i] << " " << cal << endl;
		if ( i % 100 ==0) {
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
	plik3.close();
	plik4.close();
	return 0;
}

//demodulacja zFSK
double zad11c(int size) {
	fstream plik;
	plik.open("zFSK.txt", ios::in);
	fstream plik2;
	plik2.open("zFSKdla1.txt", ios::in);
	fstream plik3;
	plik3.open("zFSKdla0.txt", ios::in);
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
	plik8.open("koniec.txt", ios::out | ios::trunc);
	int size1 = size * 2 * 3;
	int size2 = size1 * 100;
	double za[4800];
	double za1[4800];
	double za2[4800];
	double tmp[4800];
	double temp[4800];
	double temp1[4800];
	double a1[4800];
	double a2[4800];
	double a3[4800];
	double cal = 0;
	double cal1 = 0;
	double h1 = 0.5;
	double koniec[4800];
	double a = 0;
	double b = 0;
	double c = 0;
	double d = 0;
	for (int i = 0; i < size2; i++) {
		plik3 >> tmp[i] >> za2[i];
		plik2 >> tmp[i] >> za1[i];
		plik >> tmp[i] >> za[i];
	}

	for (int i = 0; i < size2; i++) {
		temp[i] = za1[i] * za[i];
		plik1 << tmp[i] << " " << za1[i] * za[i] << endl;//dla1
	}
	for (int i = 0; i < size2; i++) {
		temp1[i] = za2[i] * za[i];
		plik4 << tmp[i] << " " << za2[i] * za[i] << endl;//dla0
	}
	for (int i = 0; i < size2; i++) {
		cal += temp[i];
		a1[i] = cal;
		plik5 << tmp[i] << " " << cal << endl;
		if (i % 100 ==0) {
			cal = 0;
		}
		cal1 += temp1[i];
		a2[i] = cal1;
		plik6 << tmp[i] << " " << cal1 << endl;
		if (i % 100 == 0) {
			cal1 = 0;
		}
	}
	for (int i = 0; i < size2; i++) {
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
//dekodowanie SECDED

void zad6(int size1) {
	fstream plik;
	plik.open("koniec.txt", ios::in);
	fstream plik1;
	plik1.open("HammingDem.txt", ios::out | ios::trunc);
	int size = size1 * 2 * 3;

	int i = 0;
	int rozmiar = size * 100;
	int tab[100];
	int tab1[100];
	int z;
	int w;
	int n;
	int n1[100];
	double tmp;
	int j;
	int korekta1[100];
	int temp[100];
	int damage;
	int ham[100];
	int ham1[100];
	int tab2[4800];
	for (int i = 0; i < rozmiar; i++) {
		plik >> tmp >> tab2[i];
	}
	j = 50;
	w = 0;
	for (int i = 0; i < 4800; i += 100) {

		tab1[w] = tab2[j];
		j += 100;
		if (j >= 4800) {
			j = 4799;
		}
		w++;
	}
	w = 0;
	j = 0;
	i = 0;
	cout << "Weryfikacja p4 uszkodzonego" << endl;
	for (int j = 0; j < size; j += 8) {
		temp[i] = (tab1[j] + tab1[j + 1] + tab1[j + 2] + tab1[j + 3] + tab1[j + 4] + tab1[j + 5] + tab1[j + 6]) % 2;
		if (temp[i] != tab1[j + 7]) {
			cout << "P4 jest niezgodne" << " ";
		}
		i++;
	}
	j = 0;
	//uszkodzony
	for (int i = 0; i < size; i += 8) {
		ham1[j] = (tab1[i] + tab1[i + 2] + tab1[i + 4] + tab1[i + 6]) % 2;
		ham1[j + 1] = (tab1[i + 1] + tab1[i + 2] + tab1[i + 5] + tab1[i + 6]) % 2;
		ham1[j + 2] = (tab1[i + 3] + tab1[i + 4] + tab1[i + 5] + tab1[i + 6]) % 2;
		j += 3;
	}



	//uszkodzony
	j = 0;
	z = 0;
	w = 0;
	cout << endl << "Indeks korekty kodu uszkodzonego: " << endl;
	for (int i = 0; i < size; i += 8) {
		n = (ham1[j] * 1 + ham1[j + 1] * 2 + ham1[j + 2] * 4);
		j += 3;
		z += 4;
		cout << n << " ";
		if (n > 0) {
			if (tab1[n - 1 + i] == 0)tab1[n - 1 + i] = 1;
			else if (tab1[n - 1 + i] == 1)tab1[n - 1 + i] = 0;
		}
		w++;
	}
	cout << endl;
	//cout << endl << "Zdekodowany:";
	//uszkodzony
	cout << "Ponowna weryfikacja p4 uszkodzonego" << endl;
	for (int j = 0; j < size; j += 8) {
		temp[i] = (tab1[j] + tab1[j + 1] + tab1[j + 2] + tab1[j + 3] + tab1[j + 4] + tab1[j + 5] + tab1[j + 6]) % 2;
		if (temp[i] != tab1[j + 7]) {
			cout << "P4 jest niezgodne, byly 2 bledy.";
			break;
		}
		i++;
		korekta1[z] = tab1[j + 2];
		korekta1[z + 1] = tab1[j + 4];
		korekta1[z + 2] = tab1[j + 5];
		korekta1[z + 3] = tab1[j + 6];
		cout << korekta1[z] << korekta1[z + 1] << korekta1[z + 2] << korekta1[z + 3] << " ";
		plik1 << korekta1[z] << endl << korekta1[z + 1] << endl << korekta1[z + 2] << endl << korekta1[z + 3] << endl;
		z += 4;
	}

	plik.close();
	plik1.close();
}
//dekodowanie Hamminga
void zad3(int size1) {
	int size2 = size1 * 2 * 3;
	int size4 = size1 * 7;
	int size = 2 * 2 * 3;
	double rozmiar = size2 * 100.0;
	int tab[100];
	int ham[100];
	int tab2[4200];
	int ham1[100];
	int n = 0;
	int tab1[100];
	double tmp;
	int damage;
	int korekta1[100];
	int korekta[100];
	int i = 0;
	int j = 0;
	int z = 1;
	fstream plik1;
	plik1.open("HammingDem.txt",ios::out | ios::trunc);
	fstream plik2;
	plik2.open("koniec.txt", ios::in);
	for (int i = 0; i < rozmiar;i++) {
		plik2 >> tmp >> tab2[i];
	}
	j = 50;
	int w = 0;
	for (int i = 0; i < 4200;i+=100) {

		tab1[w] = tab2[j];
		j+=100;
		if (j >= 4200) {
			j = 4199;
		}
		w++;
	}
	w = 0;
	j = 0;
	for (int i = 0; i < size2; i += 7) {
		ham1[j] = (tab1[i] + tab1[i + 2] + tab1[i + 4] + tab1[i + 6]) % 2;
		ham1[j + 1] = (tab1[i + 1] + tab1[i + 2] + tab1[i + 5] + tab1[i + 6]) % 2;
		ham1[j + 2] = (tab1[i + 3] + tab1[i + 4] + tab1[i + 5] + tab1[i + 6]) % 2;
		j += 3;
	}
	z = 1;
	cout << endl << "Demodulacja uszkodzona po modulo:" << endl;
	for (int i = 0; i < size; i++) {
		cout << ham1[i];
		if (z % 3 == 0) {
			cout << " ";
		}
		z++;
	}
	j = 0;
	z = 0;
	j = 0;
	z = 0;
	w = 0;
	cout << endl << "Indeks korekty kodu uszkodzonego: " << endl;
	for (int i = 0; i < size2; i += 7) {
		n = (ham1[j] * 1 + ham1[j + 1] * 2 + ham1[j + 2] * 4);
		j += 3;
		z += 4;
		cout << n << " ";
		if (n > 0) {
			if (tab1[n - 1 + i] == 0)tab1[n - 1 + i] = 1;
			else if (tab1[n - 1 + i] == 1)tab1[n - 1 + i] = 0;
		}
		w++;
	}
	cout << endl;
	z = 0;
	cout << "Zdekodowany: "<<endl;
	for (int i = 0; i < size2; i += 7) {
		korekta[z] = tab1[i + 2];
		korekta[z + 1] = tab1[i + 4];
		korekta[z + 2] = tab1[i + 5];
		korekta[z + 3] = tab1[i + 6];
		cout << korekta[z] << korekta[z + 1] << korekta[z + 2] << korekta[z + 3] << " ";
		plik1 << korekta[z] << endl << korekta[z + 1] << endl << korekta[z + 2] << endl << korekta[z + 3] << endl;
		j += 3;
		z += 4;
	}



	plik1.close();
	plik2.close();

}
void zad4(int size1) {
	fstream plik;
	plik.open("HammingDem.txt", ios::in);
	int size = size1 * 8;
	int tab[100];
	string text = "";
	string binary;
	for (int i = 0; i < size;i++) {
		plik >> tab[i];
	}
	for (int i = 0; i < size; i++) {
		binary += to_string(tab[i]);
	}
	cout << endl;
	stringstream sstream(binary);
	while (sstream.good())
	{
		bitset<8> bits;
		sstream >> bits;
		text += char(bits.to_ulong());
	}
	cout << "Dane wyjsciowe: ";
	cout << text;

	plik.close();
}
int main()
{
	int i[] = { 'C','A','B' };
	int size = my_sizeof(i) / my_sizeof(i[0]);
	int size1 = size * 8;
	int tmp[100];
	int z;
	int j = 1;
	int o;
	string slowo1 = S2BS(i, size);
	fstream plik;
	cout << "Dane wejsciowe: CAB"<<endl;

	plik.open("S2BS.txt", ios::in);
	for (int i = 0; i < size1; i++) {
		plik >> tmp[i];
	}
	cout << "Strumien binarny:" << endl;
	for (int i = 0; i < size1; i++) {
		cout << tmp[i];
		if (j % 4 == 0) {
			cout << " ";
		}
		j++;
	}
	plik.close();
	cout <<endl<< "[1]Hamming/[2]HammingSECDED  ";
	cin >> o;
	switch (o) {
	case 1:
		zad1(tmp, size);
		cout << endl;
		cout << "Czy chcesz zanegowac bit?" << endl << "[1]Tak/[2]Nie  ";
		cin >> z;
		switch (z) {
		case 1:
			zad2(size);
			cout << "Ktora modulacje wybierasz?" << endl << "[1]zASK/[2]zPSK/[3]/zFSK  ";
			cin >> z;
			switch (z) {
			case 1:
				zad11(7);
				zad1a(7);
				zad3(7);
				zad4(size);
				break;
			case 2:
				zad1c(7);
				zad1b(7);
				zad3(7);
				zad4(size);
				break;
			case 3:
				zad11b(7);
				zad11c(7);
				zad3(7);
				zad4(size);
				break;
			}
			break;
		case 2:
			cout << "Ktora modulacje wybierasz?" << endl << "[1]zASK/[2]zPSK/[3]/zFSK  ";
			cin >> z;
			switch (z) {
			case 1:
				zad11(7);
				zad1a(7);
				zad3(7);
				zad4(size);
				break;
			case 2:
				zad1c(7);
				zad1b(7);
				zad3(7);
				zad4(size);
				break;
			case 3:
				zad11b(7);
				zad11c(7);
				zad3(7);
				zad4(size);
				break;
			}
			break;
		}
		break;
	case 2:
		zad4(tmp, size);
		cout << endl;
		cout << "Czy chcesz zanegowac bit?" << endl << "[1]Tak/[2]Nie  ";
		cin >> z;
		switch (z) {
		case 1:
			zad5(size);
			cout << "Ktora modulacje wybierasz?" << endl << "[1]zASK/[2]zPSK/[3]/zFSK  ";
			cin >> z;
			switch (z) {
			case 1:
				zad11(8);
				zad1a(8);
				zad6(8);
				zad4(size);
				break;
			case 2:
				zad1c(8);
				zad1b(8);
				zad6(8);
				zad4(size);
				break;
			case 3:
				zad11b(8);
				zad11c(8);
				zad6(8);
				zad4(size);
				break;
			}
			break;
		case 2:
			cout << "Ktora modulacje wybierasz?" << endl << "[1]zASK/[2]zPSK/[3]/zFSK  ";
			cin >> z;
			switch (z) {
			case 1:
				zad11(8);
				zad1a(8);
				zad6(8);
				zad4(size);
				break;
			case 2:
				zad1c(8);
				zad1b(8);
				zad6(8);
				zad4(size);
				break;
			case 3:
				zad11b(8);
				zad11c(8);
				zad6(8);
				zad4(size);
				break;
			}
			break;
		}
		break;
	}

}
