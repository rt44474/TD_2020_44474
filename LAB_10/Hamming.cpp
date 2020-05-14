// Hamming.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
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
using namespace std;
string S2BS(int i[],int size) {
	fstream plik1;
	plik1.open("dane1.txt", ios::out | ios::trunc);
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
	for (int i = 0; i < size * 8;i++) {
		plik1 << slowo1[i] << endl;
	}
	plik1.close();
	return slowo1;
}
string zad1(int slowo1[],int size1) {
	fstream plik1;
	plik1.open("dane2.txt", ios::out | ios::trunc);
	int ham[100];
	int size = size1 * 8;
	int size2 = size1 * 2 * 7;
	string x;
	int z = 1;
	int j = 0;
	for (int i = 0; i <size; i += 4) {
		ham[j] = slowo1[i] + slowo1[i + 1] + slowo1[i + 3];
		ham[j + 1] = slowo1[i] + slowo1[i + 2] + slowo1[i + 3];
		ham[j + 2] = slowo1[i];
		ham[j + 3] = slowo1[i + 1] + slowo1[i + 2] + slowo1[i + 3];
		ham[j + 4] = slowo1[i + 1];
		ham[j + 5] = slowo1[i + 2];
		ham[j + 6] = slowo1[i + 3];
		j += 7;
	}
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
	for (int i = 0; i < size2;i++) {
		if (ham[i]%2 ==0) {
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
void zad2(int size1) {
	int tab[100];
	int i = 0;
	int k;
	int z = 1;
	int size2 = size1 * 2 * 7;

	fstream plik;
	plik.open("dane2.txt", ios::in);
	fstream plik2;
	plik2.open("dane3.txt", ios::out | ios::trunc);

	cout << endl << endl << "ZAD2" << endl << "Ktory numer bitu ma zostac uszkodzony:";
	cin >> k;
	while (!plik.eof()) {
	//for (int i = 0; i < 42;i++) {
		plik >> tab[i];
		i++;
	}
	if (tab[k-1] ==1 ) {
		tab[k-1] = 0;
	}
	else if (tab[k-1]==0) {
		tab[k-1] = 1;
	}
	cout << "Uszkodzony kod Hammiga na pozycji " << k << ":" << endl;
	for (int i = 0; i < size2;i++) {
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
void zad3(int size1) {
	int size2 = size1 * 2 * 7;
	int size4 = size1 * 7;
	int size = size1 * 2 * 3;
	int tab[100];
	int ham[100];
	int ham1[100];
	int n = 0;
	int tab1[100];
	int damage;
	int korekta1[100];
	int korekta[100];
	int i = 0;
	int j = 0;
	int z = 1;
	fstream plik;
	plik.open("dane2.txt", ios::in);
	fstream plik2;
	plik2.open("dane3.txt", ios::in);
	for (int i = 0; i <size2 ; i += 7) {
		ham[j] = tab[i] + tab[i+2]+tab[i+4]+tab[i+6];
		ham[j + 1] = tab[i+1]+tab[i+2]+tab[i+5]+tab[i+6];
		ham[j + 2] = tab[i+3]+tab[i+4]+tab[i+5]+tab[i+6];
		j += 3;
	}
	while (!plik2.eof()) {
		plik2 >> tab1[i];
		i++;
		//cout << endl << tab1[i] << endl;
	}
	j = 0;
	for (int i = 0; i < size2; i += 7) {
		ham1[j] = (tab1[i] + tab1[i + 2] + tab1[i + 4] + tab1[i + 6])%2;
		ham1[j + 1] = (tab1[i + 1] + tab1[i + 2] + tab1[i + 5] + tab1[i + 6])%2;
		ham1[j + 2] = (tab1[i + 3] + tab1[i + 4] + tab1[i + 5] + tab1[i + 6])%2;
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
	cout << endl << "Zdekodowany:" << endl;
	j = 0;
	z = 0;
	int w = 0;
	cout << endl << "Indeks korekty kodu uszkodzonego: " << endl;
	for (int i = 0; i < size; i += 7) {
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
	for (int i = 0; i < size2;i+=7) {
		korekta[z] = tab1[i + 2];
		korekta[z + 1] = tab1[i + 4];
		korekta[z + 2] = tab1[i + 5];
		korekta[z + 3] = tab1[i + 6];
		cout << korekta[z] << korekta[z + 1] << korekta[z + 2] << korekta[z + 3] << " ";
		j += 3;
		z += 4;
	}




	plik2.close();
	plik.close();

}
void zad4(int size1) {
	int size = size1 * 8;
	int size2 = size1 * 2 * 8;
	fstream plik;
	int tab[100];
	int ham[100];

	int i = 0;
	int j = 1;
	plik.open("dane1.txt", ios::in);
	fstream plik1;
	plik1.open("dane4.txt", ios::out | ios::trunc);
	cout << endl << endl << endl << "ZAD 4"  ;
	while (!plik.eof()) {
		plik >> tab[i];
		i++;
	}
	cout <<endl<< "Strumien binarny:" << endl;

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
		ham[j] = (tab[i] + tab[i + 1] + tab[i + 3])%2;
		ham[j + 1] = (tab[i] + tab[i + 2] + tab[i + 3])%2;
		ham[j + 2] = tab[i];
		ham[j + 3] = (tab[i + 1] + tab[i + 2] + tab[i + 3])%2;
		ham[j + 4] = tab[i + 1];
		ham[j + 5] = tab[i + 2];
		ham[j + 6] = tab[i + 3];
		ham[j + 7] = (ham[j]+ham[j+1]+ham[j+2]+ham[j+3]+ham[j+4]+ham[j+5]+ham[j+6]) % 2;
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
	plik.close();
	plik1.close();
}
void zad5(int size1) {
	int tab[100];
	int i = 0;
	int k;
	int l;
	int z = 1;
	int size2 = size1 * 2 * 8;

	fstream plik;
	plik.open("dane4.txt", ios::in);
	fstream plik2;
	plik2.open("dane5.txt", ios::out | ios::trunc);

	cout << endl  << endl << "Ktore numery bitu maja zostac uszkodzone:";
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
	cout << "Uszkodzony kod Hammiga na pozycjach " << k << ","<<l<<":" << endl;
	for (int i = 0; i < size2; i++) {
		cout << tab[i];
		if (z % 16 == 0) {
			cout << " ";
		}
		z++;
		plik2 << tab[i] << endl;
	}
	cout << endl;
	plik.close();
	plik2.close();
}
void zad6(int size1) {
	fstream plik;
	plik.open("dane4.txt", ios::in);
	fstream plik2;
	plik2.open("dane5.txt", ios::in);
	int size = size1 * 2 * 8;
	int i = 0;
	int tab[100];
	int tab1[100];
	int z;
	int w;
	int n;
	int n1[100];
	int tmp[100];
	int korekta1[100];
	int temp[100];
	int damage;
	int ham[100];
	int ham1[100];
	while (!plik.eof()) {
		//for (int i = 0; i < 42;i++) {
		plik >> tab[i];
		i++;
	}
	i = 0;
	while (!plik2.eof()) {
		//for (int i = 0; i < 42;i++) {
		plik2 >> tab1[i];
		i++;
	}
	i = 0;
	cout << "Weryfikacja p4 uszkodzonego" << endl;
	for (int j = 0; j < size; j += 8) {
		temp[i] = (tab1[j] + tab1[j + 1] + tab1[j + 2] + tab1[j + 3] + tab1[j + 4] + tab1[j + 5] + tab1[j + 6]) % 2;
		if (temp[i] != tab1[j + 7]) {
			cout << "P4 jest niezgodne"<<" ";
		}
		i++;
	}
	int j = 0;
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
		cout << n <<" ";
		if (n > 0) {
			if (tab1[n - 1+i] == 0)tab1[n - 1+i] = 1;
			else if (tab1[n - 1+i] == 1)tab1[n - 1+i] = 0;
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
		z += 4;
	}

	plik.close();
	plik2.close();
}
int main()
{
	int i[] = { 'C','A','B' };
	int size = my_sizeof(i) / my_sizeof(i[0]);
	int size1 = size * 8;
	int tmp[100];
	int j = 1;
	string slowo1 = S2BS(i,size);
	fstream plik;
	plik.open("dane1.txt", ios::in);
	for (int i = 0; i < size1;i++) {
		plik >> tmp[i];
	}
	cout << "ZAD1" << endl;
	cout << "Strumien binarny:" << endl;
	for (int i = 0; i < size1; i++) {
		cout << tmp[i];
		if (j % 4 == 0) {
			cout << " ";
		}
		j++;
	}
	plik.close();
	cout << endl;
	zad1(tmp,size);
	zad2(size);
	zad3(size);
	zad4(size);
	zad5(size);
	zad6(size);

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
