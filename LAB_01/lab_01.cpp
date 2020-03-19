//gnu plot
#include <iostream>
#include <math.h>
#include <cmath>
#include <fstream>
#include <cstdlib>
#define M_PI           3.14159265358979323846 
using namespace std;

double zad_1(double a, double b, double c) {
	double krok = 0.01;
	double t = -10;
	double l[2001];
	double t1;
	double t2;
	double funkcja[2001];
	int i = 0;
	fstream plik;
	plik.open("dane.txt", ios::out | ios::trunc);
	double delta = pow(b, 2.0) - (4.0 * a * c);
	if (delta < 0) {

	}
	else if (delta == 0) {
		t1 = -(b / (2 * a));
	}
	else if (delta > 0) {
		t1 = (-b + (sqrt(delta))) / (2.0 * a);
		t2 = (-b - sqrt(delta)) / (2.0 * a);
	}

	while (t <= 10) {
		funkcja[i] = a * pow(t, 2.0) + b * t + c;
		t = t + krok;
		l[i] = t;
		plik << l[i] << " " << funkcja[i] << endl;
		i++;
	}
	plik.close();
	return 0;
}
double zad_2_1(double a, double b, double c) {
	double t = 0;
	double k = 1;
	double l = 22050;
	double o[22050];
	double funkcja[22050];
	fstream plik;
	plik.open("dane1.txt", ios::out | ios::trunc);
	double m = k / l;
	int i = 0;
	while (t <= 1) {
		funkcja[i] = 2.0 * pow((a * pow(t, 2.0) + b * t + c), 2) + 12 * cos(t);
		t = t + m;
		o[i] = t;
		plik << o[i] << " " << funkcja[i] << endl;
		i++;
	}
	plik.close();
	return 1;
}
double zad_2_2(double a, double b, double c) {
	double t = 0;
	double k = 1;
	double l = 22050;
	double o[22050];
	double funkcja[22050];
	fstream plik;
	plik.open("dane2.txt", ios::out | ios::trunc);
	double m = k / l;
	int i = 0;
	while (t <= 1) {
		funkcja[i] = sin(2 * M_PI * 7 * t) * (a * pow(t, 2.0) + b * t + c) - 0.2 * log10(abs(2.0 * pow((a * pow(t, 2.0) + b * t + c), 2) + 12 * cos(t)) + M_PI);
		t = t + m;
		o[i] = t;
		plik << o[i] << " " << funkcja[i] << endl;
		i++;
	}
	plik.close();
	return 1;
}
double zad_2_3(double a, double b, double c) {
	double t = 0;
	double k = 1;
	double l = 22050;
	double o[22050];
	double funkcja[22050];

	fstream plik;
	plik.open("dane3.txt", ios::out | ios::trunc);
	double m = k / l;
	int i = 0;
	while (t <= 1) {
		//funkcja[i] = sin(2 * M_PI * 7 * t) * (a * pow(t, 2.0) + b * t + c) - 0.2 * log10(abs(2.0 * pow((a * pow(t, 2.0) + b * t + c), 2) + 12 * cos(t)) + M_PI);
		double x = a * pow(t, 2.0) + b * t + c;
		double y = 2.0 * pow((a * pow(t, 2.0) + b * t + c), 2) + 12 * cos(t);
		double z = sin(2 * M_PI * 7 * t) * (a * pow(t, 2.0) + b * t + c) - 0.2 * log10(abs(2.0 * pow((a * pow(t, 2.0) + b * t + c), 2) + 12 * cos(t)) + M_PI);
		funkcja[i] = sqrt(abs(y * y * z)) - 1.8 * sin(0.4 * t * z * x);
		t = t + m;
		o[i] = t;
		plik << o[i] << " " << funkcja[i] << endl;
		i++;
	}
	plik.close();
	return 1;
}
double zad_2_4(double a, double b, double c) {
	double t = 0;
	double k = 1;
	double l = 22050;
	double o[22050];
	double funkcja[22050];

	fstream plik;
	plik.open("dane4.txt", ios::out | ios::trunc);
	double m = k / l;
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
double zad_2_5(double a, double b, double c) {
	double t = 0;
	double k = 1;
	double l = 22050;
	double o[22050];
	double funkcja[22050];
	double funkcja1[22050];


	fstream plik;
	plik.open("dane5.txt", ios::out | ios::trunc);
	double m = k / l;
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
double zad_2_6(double a, double b, double c) {
	double t = 0;
	double k = 1;
	double l = 22050;
	double o[22050];
	double funkcja[22050];
	double funkcja1[22050];


	fstream plik;
	plik.open("dane6.txt", ios::out | ios::trunc);
	double m = k / l;
	int i = 0;

	while (t <= 1) {
		funkcja[i] = 0;
		int n = 1;
		for (int n = 1; n <= 4; n++) {

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
double zad_2_7(double a, double b, double c) {
	double t = 0;
	double k = 1;
	double l = 22050;
	double o[22050];
	double funkcja[22050];
	double funkcja1[22050];


	fstream plik;
	plik.open("dane7.txt", ios::out | ios::trunc);
	double m = k / l;
	int i = 0;

	while (t <= 1) {
		funkcja[i] = 0;
		int n = 1;
		for (int n = 1; n <= 47; n++) {

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
int main()
{
	double a, b, c;
	a = 4.0;
	b = 7.0;
	c = 4.0;
	zad_1(a, b, c);
	zad_2_1(a, b, c);
	zad_2_2(a, b, c);
	zad_2_3(a, b, c);
	zad_2_4(a, b, c);
	zad_2_5(a, b, c);
	zad_2_6(a, b, c);
	zad_2_7(a, b, c);
}