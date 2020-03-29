// ConsoleApplication33.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>
#define M_PI           3.14159265358979323846 
using namespace std;
double zad_1(double a, double b, double c) {

	double funkcja[20001];
	double l[20001];
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
	double fs = (1/krok);
	fstream plik;
	plik.open("dane.txt", ios::out | ios::trunc);
	while (t <= a) {
		t1 = 0.0;
		t3 = 0.0;
		double t2 = t;
		while (t1 <= fs) {		
			if (t3 > krok) {
				break;
			}
			funkcja[j] =(A * sin(((2 * w * t2) + fi)));
			t1 += krok;
			l[j] = t2;
			t2 += 0.002;
			t3 += 0.002;
			plik << t2 << " " << funkcja[j] << endl;
			j++;
		}
		t += krok;
		i++;
	}
	plik.close();
	return 0;

}

double zad_2(double a, double b, double c) {

	int funkcja[20001];
	double l[20001];
	double t = 0.0;
	double t1 = 0.0;
	int i = 0;
	int j = 0;
	double t3;
	double krok = 0.1;
	double f = b;
	double fi = (c * M_PI);
	double A = (pow(2,16));
	double w = (2 * M_PI * b);
	double fs = (1 / krok);
	fstream plik;
	plik.open("dane1.txt", ios::out | ios::trunc);
	while (t <= a) {
		t1 = 0.0;
		t3 = 0.0;
		double t2 = t;
		while (t1 <= fs) {
			if (t3 > krok) {
				break;
			}
			funkcja[j] = ((A +(A * sin(((2 * w * t2) + fi))))*0.49999237060546875);
			t1 += krok;
			l[j] = t2;
			t2 += 0.002;
			t3 += 0.002;
			plik << t2 << " " << funkcja[j] << endl;
			j++;
		}
		t += krok;
		i++;
	}
	plik.close();
	return 0;

}

double zad_3(double a, double b, double c) {

	int funkcja[20001];
	double l[20001];
	double t = 0.0;
	double t1 = 0.0;
	int i = 0;
	int j = 0;
	double t3;
	double krok = 0.1;
	double f = b;
	double fi = (c * M_PI);
	double A = ((pow(2, 8)));
	double w = (2 * M_PI * b);
	double fs = ((1 / krok)/2);
	fstream plik;
	plik.open("dane2.txt", ios::out | ios::trunc);
	while (t <= a) {
		t1 = 0.0;
		t3 = 0.0;
		double t2 = t;
		while (t1 <= fs) {
			if (t3 > krok) {
				break;
			}
			funkcja[j] = ((A + (A * sin(((2 * w * t2) + fi)))) * 0.49999237060546875);
			t1 += krok;
			l[j] = t2;
			t2 += 0.002;
			t3 += 0.002;
			plik << t2 << " " << funkcja[j] << endl;
			j++;
		}
		t += krok;
		i++;
	}
	plik.close();
	return 0;

}
int main()
{
	double a, b, c;
	a = 4.0;
	b = 7.0;
	c = 4.0;
	//4 7 4
	zad_1(a, b, c);
	zad_2(a, b, c);
	zad_3(a, b, c);
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
