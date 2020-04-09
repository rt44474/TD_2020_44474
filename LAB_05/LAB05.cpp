// LAB05.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <fstream>
#define PI           3.14159265358979323846 
#include <math.h>
#include <iomanip>
#include <complex>
//fn = od 800 do 2000

using namespace std;
double m(double t) {
	double a = 1.0;
	double f = 4.0;
	double fi = 5.0 * PI;
	return a * sin(2 * PI * fi *t);
}
double za(double t, double ka, double fn) {
	return (ka * m(t) + 1) * cos(2 * PI * fn * t);
}
double zp(double t, double kp, double fn) {
	return cos((2 * PI * fn * t) + (kp * m(t)));
}
double zad_2_6(double a, double b, double c) {
	double t = 0;
	double k = 1;
	double l = 22050;
	double o[22050];
	double funkcja[22050];
	double funkcja1[22050];
	double fs = 22050.0;
	double ts = 1.0 / fs;
	double start = 0.0;
	double stop = 1.0;
	int data_size = (stop - start) * fs;


	fstream plik;
	plik.open("dane6.txt", ios::out | ios::trunc);
	fstream plik1;
	plik1.open("dane1.txt", ios::out | ios::trunc);
	double m = k / l;
	int i = 0;

	while (t <= 1) {
		funkcja[i] = 0;
		int n = 1;
		for (int n = 1; n <= 4; n++) {

			funkcja1[i] = 1.0 * (cos(12 * t * pow(n, 2)) + cos(16 * t * n)) / (pow(n, 2));
			funkcja[i] += funkcja1[i];
		}
		t = t + m;
		o[i] = t;
		plik << o[i] << " " << funkcja[i] << endl;
		i++;
	}
	//modulacja
	t = 0;
	while(t<=1){
		double x = start + i * ts;
		double y = za(x, 0.5, 100.0);
		plik1 << x << " " << y << endl;
		t = t + m;
	}
	plik1.close();
	plik.close();
	return 1;
}

int main()
{

	zad_2_6(4.0, 7.0, 4.0);
}

